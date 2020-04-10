// alex chen's codes
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int sick [n];
    for(int i = 0; i < n; i++){
        cin >> sick[i];
    }
    vector <int> edges [n];
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }
    //bfs from node 0 to find x;
    //bfs from node x to find y, and determin distances from x
    //bfs from node y to determine distances from y;
    bool vis [n];
    for(int i = 0; i < n; i++){
        vis[i] = false;
    }
    vis[0] = true;
    queue <int> q;
    q.push(0);
    int x = 0;
    while(!q.empty()){
        x = q.front();
        for(int i = 0; i < edges[x].size(); i++){
            if(!vis[edges[x][i]]){
                q.push(edges[x][i]);
                vis[edges[x][i]] = true;
            }
        }
        q.pop();
    }
    int dx [n];
    for(int i = 0; i < n; i++){
        dx[i] = -1;
    }
    dx[x] = 0;
    q.push(x);
    int y;
    while(!q.empty()){
        y = q.front();
        for(int i = 0; i < edges[y].size(); i++){
            if(dx[edges[y][i]] == -1){
                q.push(edges[y][i]);
                dx[edges[y][i]] = dx[y]+1;
            }
        }
        q.pop();
    }
    int dy[n];
    for(int i = 0; i < n; i++){
        dy[i] = -1;
    }
    dy[y] = 0;
    q.push(y);
    while(!q.empty()){
        int k = q.front();
        for(int i = 0; i < edges[k].size(); i++){
            if(dy[edges[k][i]] == -1){
                q.push(edges[k][i]);
                dy[edges[k][i]] = dy[k]+1;
            }
        }
        q.pop();
    }
    int m = 0;
    for(int i = 0; i < n; i++){
        m = max(m,max(dx[i],dy[i])*sick[i]);
    }
    cout << m << endl;
    return 0;
}

