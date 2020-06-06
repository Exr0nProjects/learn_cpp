#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int N;
vector<int> height;
vector<pair<int,int>> base;
vector <int> adj [200];
int mem [200];
int casenum = 0;
void insert_block(int x, int y, int z){
    base.push_back(make_pair(x,y));
    base.push_back(make_pair(y,x));
    base.push_back(make_pair(x,z));
    base.push_back(make_pair(z,x));
    base.push_back(make_pair(y,z));
    base.push_back(make_pair(z,y));
    height.push_back(z);
    height.push_back(z);
    height.push_back(y);
    height.push_back(y);
    height.push_back(x);
    height.push_back(x);
}
bool can_stack(int i, int j){
    //returns whether we can stack block j on i;
    return base[j].first < base[i].first && base[j].second < base[i].second;
}
void construct_graph(){
    for(int i = 0; i < 6*N; i++){
        for(int j = 0; j < 6*N; j++){
            if(can_stack(i,j)){
                adj[i].push_back(j);
            }
        }
    }
}
int dp(int block){
    if(mem[block] == -1){
        int ans = height[block];
        for(int i = 0; i < adj[block].size(); i++){
            ans = max(ans,height[block]+dp(adj[block][i]));
        }
        mem[block] = ans;
    }
    return mem[block];
}
void erase_everything(){
    height.clear();
    base.clear();
    for(int i = 0; i < 200; i++){
        adj[i].clear();
        mem[i] = -1;
    }
    casenum++;
}
void recive_input(){
    for(int i = 0; i < N; i++){
        int a,b,c;
        cin >> a >> b >> c;
        insert_block(a,b,c);
    }
}
int find_ans(){
    int max_val = 0;
    for(int i = 0; i < 6*N; i++){
        max_val = max(max_val,dp(i));
    }
    return max_val;
}
int main(int argc, const char * argv[]) {
    while(true){
        erase_everything();
        cin >> N;
        if(N == 0){
            break;
        }
        recive_input();
        construct_graph();
        cout << "Case " << casenum << ": maximum height = " << find_ans() << endl;
    }
    return 0;
}

