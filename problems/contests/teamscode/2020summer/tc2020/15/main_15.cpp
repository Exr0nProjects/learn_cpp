/*
 * Problem 15 (contests/teamscode/2020summer/tc2020/15)
 * Create time: Tue 28 Jul 2020 @ 12:12 (PDT)
 * Accept time: [!meta:end!]
 *   not 0/1 knapsack but rather 0..k knapsack
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
const ll MX = 311;
int N, S, cnt[MX], siz[MX], dp[MX][MX];

int main()
{
    scanf("%d%d", &N, &S);
    for (int i=1; i<=N; ++i)
        scanf("%d%d", &cnt[i], &siz[i]);

    dp[0][0] = 1;
    for (int i=1; i<=N; ++i)
        for (int j=0; j<=S; ++j)
            for (int k=0; k<=cnt[i]; ++k)
                if (j-k*siz[i] >= 0)    // FIX: ge not gt
                {
                    //printf("%3d %3d %3d += %3d %3d = %3d\n", i, j, k, i-1, j-k*siz[i], dp[i-1][j-k*siz[i]]);
                    dp[i][j] += dp[i-1][j-k*siz[i]];
                }
    printf("%d\n", dp[N][S]);

	return 0;
}

