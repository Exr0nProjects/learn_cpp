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
list<int> head[MX+1]; // adjacency list
int dp[MX+1][3]; // 0 is the server, 1 is connected, 2 is not connected


 // deep search
 // Parameters: current node and father node
void op(int cur, int pre=0)
{
    dp[cur][0] = 1;
    dp[cur][1] = 1e6;
    dp[cur][2] = 0;
    //if (head[cur].size() == 1 && *head[cur].begin() == pre) return ;

    int minm = 1e6;
    //for (int i = 0; i < head[cur].size(); i++)
    for (int nxt : head[cur]) if (nxt != pre)
    {
        //int nxt = head[cur][i];
        op(nxt, cur);
        dp[cur][0] += min(dp[nxt][2], dp[nxt][0]);
        // If the nxt has an unreachable connected state, the father's unconnected is also unreachable.
        dp[cur][2] += dp[nxt][1];
        minm = min(minm, dp[nxt][0]-dp[nxt][1]);
    }
    dp[cur][0] = min((int)2e6, dp[cur][0]);

    dp[cur][1] = dp[cur][2] + minm;
    dp[cur][2] = min((int)2e6, dp[cur][2]);
}

int main()
{
    while (true)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i <= MX; i++) head[i].clear();
        for (int i = 1; i < n; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            head[a].push_back(b);
            head[b].push_back(a);
        }
        //printf("%d\n", dfsSolve());
        op(1);
        printf("%d\n", min(dp[1][0], dp[1][1]));
        int end;
        scanf("%d", &end);
        if (end == -1) break;
    }
    // system("pause");
}

