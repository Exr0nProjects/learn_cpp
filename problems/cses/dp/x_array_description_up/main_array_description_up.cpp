/*
 * Problem array_description_up (cses/dp/array_description_up)
 * Create time: Sun 30 Aug 2020 @ 10:09 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
#include <vector>
#include <random>
#include <map>
#include <set>
#include <string>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <chrono>
#include <functional>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 1e5+11;
const int MXV = 110;
const int MOD = 1e9+7;  // FIX: mod

int N, M, a[MX], dp[MX][MXV];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=1; i<=N; ++i) scanf("%d", a+i);

    //for (int j=1; j<MXV; j+=3) dp[0][j] = 1;
    if (a[1]) dp[1][a[1]] = 1;  // FIX: tried to cheat on broken base case
    else fill(dp[1]+1, dp[1]+M+1, 1);

    for (int i=1; i<=N; ++i)
    for (int j=1; j<=M; ++j)
    if (!a[i] || a[i] == j)
        dp[i][j] += dp[i-1][j-1] * (j > 1), dp[i][j]%=MOD,
        dp[i][j] += dp[i-1][j  ],           dp[i][j]%=MOD,
        dp[i][j] += dp[i-1][j+1] * (j < M), dp[i][j]%=MOD;

    //for (int i=0; i<=N; ++i)
    //{
    //    for (int j=1; j<=M; ++j)
    //        printf("%3d", dp[i][j]);
    //    printf("\n");
    //}

    for (int j=1; j<=M; ++j)
        (dp[N][j] += dp[N][j-1]) %= MOD;    // FIX: mod everywhere
    printf("%d\n", dp[N][M]);

	return 0;
}

