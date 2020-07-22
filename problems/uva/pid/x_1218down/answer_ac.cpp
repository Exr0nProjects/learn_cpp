// tles
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;
int big = 100000;
int mem [11111][3];//0 - server, 1 - unserved client, 2 - served client
vector <int> children [11111];
void reset(){
    for(int i = 0; i < 11111; i++){
        mem[i][0] = big;
        mem[i][1] = big;
        mem[i][2] = big;
        children[i].clear();
    }
}
int dp(int curr, int state){
    if(mem[curr][state] == big){
        int total_servers = 0;
        if(state == 0){
            total_servers++;
            for(int i = 0; i < children[curr].size(); i++){
                total_servers += dp(children[curr][i],2);
            }
        }else if(state == 1){
            if(children[curr].size() == 0){
                total_servers = big;
            }else{
                vector <int> diff;
                for(int i = 0; i < children[curr].size(); i++){
                    total_servers += dp(children[curr][i],1);
                    diff.push_back(dp(children[curr][i],0)-dp(children[curr][i],1));
                }
                int lowest = big;
                for(int i = 0; i < diff.size(); i++){
                    lowest = min(lowest,diff[i]);
                }
                total_servers += lowest;
            }
        }else{
            for(int i = 0; i < children[curr].size(); i++){
                total_servers += dp(children[curr][i],1);
            }
        }
        total_servers = min(total_servers, big);
    }
    return mem[curr][state];
}

int main(int argc, const char * argv[]) {
    while(true){
        int n;
        cin >> n;
        unordered_set <int> u [n];
        for(int i = 0; i < n-1; i++){
            int a;
            int b;
            cin >> a >> b;
            u[b-1].insert(a-1);
            u[a-1].insert(b-1);
        }
        queue <int> q;
        int parent [n];
        for(int i = 0; i < n; i++){
            parent[i] = -1;
        }
        q.push(0);
        parent[0] = -1;
        while(!q.empty()){
            int curr = q.front();
            if(parent[curr] != -1){
                u[curr].erase(parent[curr]);
            }
            for(auto i = u[curr].begin(); i != u[curr].end(); i++){
                int child = *i;
                parent[child] = curr;
                children[curr].push_back(child);
                q.push(child);
            }
        }
        cout << min(dp(0,0), min(dp(0,1), dp(0,2))) << endl;
    }
}

