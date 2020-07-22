// https://programmersought.com/article/44061177119/

// Tree DP
 // Three states: Server, connected, not connected
 // The server's son is not connected or the server
 // The connected son is a server plus connected
 // Unconnected sons are all connected
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
using namespace std;
const int MX = 10111;
const int INF_ = 0x3f3f3f3f;
list<int> edge[MX+1]; // adjacency list
int dp[MX+1][3]; // 0 is the server, 1 is connected, 2 is not connected

void init()
{
    for (int i = 0; i <= MX; i++) edge[i].clear();
}

 // deep search
 // Parameters: current node and father node
void dfs(int v, int fa)
{
    dp[v][0] = 1;
    dp[v][1] = MX; // means unreachable, if set to infinity, the following dp[v][2] overflow occurs.
    dp[v][2] = 0;
    if (edge[v].size() == 1 && *edge[v].begin() == fa) return ;
    int minm = INF_;
    //for (int i = 0; i < edge[v].size(); i++)
    for (int son : edge[v])
    {
        //int son = edge[v][i];
        if (son == fa) continue;
        dfs(son, v);
        dp[v][0] += min(dp[son][0], dp[son][2]);
        dp[v][2] += dp[son][1]; // If the son has an unreachable connected state, the father's unconnected is also unreachable.
        minm = min(minm, dp[son][0]-dp[son][1]);
    }
    dp[v][1] = dp[v][2] + minm; // The son has more than two unreachable connected states, and the father's connection is not reachable.
}

int main()
{
    while (true)
    {
        int n;
        scanf("%d", &n);
        init();
        for (int i = 1; i < n; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        //printf("%d\n", dfsSolve());
        dfs(1, -1);
        printf("%d\n", min(dp[1][0], dp[1][1]));
        int end;
        scanf("%d", &end);
        if (end == -1) break;
    }
    // system("pause");
}

