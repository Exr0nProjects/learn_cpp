/*
 * Problem grid_paths_down (cses/dp/grid_paths_down)
 * Create time: Sat 29 Aug 2020 @ 17:46 (PDT)
 * Accept time: Sat 29 Aug 2020 @ 17:51 (PDT)
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
char grid[MX][MX];

int kdp(int i, int j)
{
    if (i == 1 && j == 0) return 1;
    int &ret = dp[i][j];
    if (ret) return ret;
    if (grid[i][j] == '.')
        ret = (kdp(i-1, j) + kdp(i, j-1)) % MOD;
    return ret;
}

int main()
{
    scanf("%d", &N);
    for (int i=1; i<=N; ++i) scanf("%s", grid[i]+1);
    printf("%d\n", kdp(N, N));

	return 0;
}

