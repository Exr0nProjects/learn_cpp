/*
 * Problem grid_paths_up (cses/dp/grid_paths_up)
 * Create time: Sat 29 Aug 2020 @ 17:39 (PDT)
 * Accept time: Sat 29 Aug 2020 @ 17:46 (PDT)
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
const ll MX = 1e3+11;
const int MOD = 1e9+7;

int N, dp[MX][MX];
char g[MX][MX];

int main()
{
    scanf("%d", &N);
    for (int i=1; i<=N; ++i) scanf("%s", g[i]+1);

    dp[1][0] = 1; // FIX: forgot base case
    for (int i=1; i<=N; ++i)
        for (int j=1; j<=N; ++j)
            if (g[i][j] == '.')
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
    printf("%d\n", dp[N][N]);

	return 0;
}

