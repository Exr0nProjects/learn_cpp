/*
 * Problem 1218down (uva/pid/1218down)
 * Create time: Wed 22 Jul 2020 @ 11:56 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
#include <utility>
#include <iterator>
#include <exception>
#include <algorithm>
#include <functional>

using namespace std;
const int MX = 10111;

list<int> head[MX];
int N, dp[MX][5];   // 0 = server, 1 = served, 2 = not served

void op(int cur, int pre=0)
{
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%d from %d\n", cur, pre);
    //int sum1=0, max0=-1e6, sum2=1;  // FIX: max0 = 0 doesn't work, max might be negative
    //int sum1=0, max0=1e6, sum2=1;  // FIX: max0 = 0 doesn't work, max might be negative
    dp[cur][0] = 1;
    dp[cur][1] = 1e6;
    dp[cur][2] = 0;
    int minm = 1e6;
    for (int nxt : head[cur]) if (nxt != pre)
    {
        op(nxt, cur);
        //sum1 += dp[nxt][1];
        //sum2 += min(dp[nxt][2], dp[nxt][0]);
        dp[cur][0] += min(dp[nxt][2], dp[nxt][0]);
        dp[cur][2] += dp[nxt][1];
        //max0 = max(max0, dp[nxt][1]-dp[nxt][0]);
        minm = min(minm, dp[nxt][0]-dp[nxt][1]);
    }
    dp[cur][0] = min((int)2e6, dp[cur][0]);
    //dp[cur][1] = sum1-max0;
    dp[cur][1] = dp[cur][2] + minm;
    //if (head[cur].size() == 1 && pre) dp[cur][1] = 2e6;
    dp[cur][2] = min((int)2e6, dp[cur][2]);
    //for (int i=0; i<lay; ++i) printf("|   "); printf("sum %d sub %d\n", sum1, max0);
    //for (int i=0; i<lay; ++i) printf("|   "); printf("=> %d %d %d\n", dp[cur][0], dp[cur][1], dp[cur][2]);
}

int main()
{
    while (~scanf("%d", &N))
    {
        if (N == 1) printf("1\n");
        else
        {
            for (int i=0; i<MX; ++i) head[i].clear();   // FIX: clears
            memset(dp, 0, sizeof dp);
            for (int i=1; i<N; ++i)
            {
                int u, v; scanf("%d%d", &u, &v);
                //printf("connecting %d and %d\n", u, v);
                head[u].push_back(v);
                head[v].push_back(u);
            }
            op(1);
            //printf("dp 1,0 %d  ;  1,1 %d\n", dp[1][0], dp[1][1]);
            printf("%d\n", min(dp[1][0], dp[1][1]));
        }
        //int t; scanf("%d", &t); if (t == -1) break;
        int t; cin >> t; if (t == -1) break;
    }

	return 0;
}

