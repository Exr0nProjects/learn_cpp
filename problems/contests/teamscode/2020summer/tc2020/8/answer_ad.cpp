#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdio>
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iterator>
using namespace std;
#define INF 999999999
int N, T;
char arr[40][40];
bool vis[40][40];
int ss, se;
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};
int main(){
    scanf("%d%d", &N, &T);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 'Z'){
                ss = i;
                se = j;
            }
        }
    }
    queue <pair<pair<int, int>, int> > q;
    q.push({{ss, se}, 0});
    vis[ss][se] = true;
    while (!q.empty()){
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int val = q.front().second;
        q.pop();
        if (val == T) continue;
        for (int i = 0; i < 4; i++){
            int nx = curx+x[i];
            int ny = cury+y[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && arr[nx][ny] != '#' && !vis[nx][ny]){
                vis[nx][ny] = true;
                arr[nx][ny] = 'Z';
                q.push({{nx, ny}, val+1});
            }
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (arr[i][j] == 'Z'){
                for (int k = 0; k < 4; k++){
                    int nx = i+x[k];
                    int ny = j+y[k];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < N && arr[nx][ny] == '*'){
                        arr[nx][ny] = '$';
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (arr[i][j] == '$') ans++;
        }
    }
    printf("%d", ans);
}

