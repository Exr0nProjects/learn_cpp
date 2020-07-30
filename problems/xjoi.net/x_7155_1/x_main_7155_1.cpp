/*
 * Problem 7155_1 (xjoi.net/7155_1)
 * Create time: Wed 29 Jul 2020 @ 23:55 (PDT)
 * Accept time: Thu 30 Jul 2020 @ 00:12 (PDT)
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

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define lr tl, (tl+((tr-tl)>>1))
#define rr (tl+((tr-tl)>>1)+1), tr

using namespace std;
const ll MX = 111;
int N, M, w[MX], v[MX], dp[MX][MX*MX];

int main()
{
    int vsum=0;
    scanf("%d%d", &N, &M);
    for (int i=1; i<=N; ++i) scanf("%d%d", &w[i], &v[i]);
    for (int i=1; i<=N; ++i) vsum += v[i];

    memset(dp, 0x3f, sizeof dp); // FIX: surrounding base case
    dp[0][0] = 0;
    for (int i=1; i<=N; ++i)
        for (int j=0; j<=vsum; ++j)
        {
            dp[i][j] = dp[i-1][j];
            if (j >= v[i]) dp[i][j]
                = min(dp[i][j], dp[i-1][j-v[i]]+w[i]);
        }

    //for (int i=0; i<=N; ++i) { for (int j=0; j<=vsum; ++j) printf("%12d", dp[i][j]); printf("\n"); }

    int ret = vsum;
    while (ret && dp[N][ret] > M)
        --ret;
    printf("%d\n", ret);

	return 0;
}

