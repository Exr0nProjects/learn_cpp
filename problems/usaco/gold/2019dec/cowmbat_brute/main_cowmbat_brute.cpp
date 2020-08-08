/*
 * Problem cowmbat_brute (usaco/gold/2019dec/cowmbat_brute)
 * Create time: Sat 08 Aug 2020 @ 12:37 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
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
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 100111;
const int MXM = 30;
int N, M, K;
char inp[MX];
int dist[MXM][MXM];
int dp[MX];

int main()
{
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w+", stdout);
    scanf("%d%d%d%s", &N, &M, &K, inp+1);
    for (int i=1; i<=N; ++i) inp[i] -= 'a'-1;   // FIX: typo--  -'a' not -'0' smah
    for (int i=1; i<=M; ++i)
        for (int j=1; j<=M; ++j)
            scanf("%d", &dist[i][j]);
    // floyd
    for (int k=1; k<=M; ++k)
        for (int i=1; i<=M; ++i)
            for (int j=1; j<=M; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    //for (int i=1; i<=M; ++i)
    //{
    //    for (int j=1; j<=M; ++j)
    //        printf("%3d", dist[i][j]);
    //    printf("\n");
    //}

    // palendrome-split dp
    memset(dp, 0x2f, sizeof dp);
    dp[0] = 0;
    for (int i=K; i<=N; ++i)
    {
        for (int t=1; t<=M; ++t)
        {
            //printf("\ntarget = %d\n", t);
            int cost=0, j=0;
            for (; j+1<K; ++j)  // FIX: don't go right up to j<K (instead do j+1<K) cuz j will get incremented and another will be added before dp equation
                cost += dist[inp[i-j]][t];
            //printf("cost to convert %d..%d to %d: %d\n", i-j, i, t, cost);
            for (; i-j>0; ++j) // FIX: fencepost-- i-j>=0 not just gt 0
            {
                cost += dist[inp[i-j]][t];
                //printf("i-j %d dp of %d cost %d\n", i-j, dp[i-j], cost);
                int pre = dp[i];
                dp[i] = min(dp[i], dp[i-j-1] + cost);
                //if (dp[i] < pre) printf("dp[%d] = %d from %d\n", i, dp[i], i-j);
            }
        }
        //printf("dp[%d] = %d\n", i, dp[i]);
    }
    printf("%d\n", dp[N]);

	return 0;
}

