/*
 * Problem 11 (tc2020/11)
 * Create time: Sat 25 Jul 2020 @ 13:40 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <utility>
#include <algorithm>

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
const ll MX = 31;
dl P, cost[MX];
pair<dl, int> dp[MX][MX];       // dp[i][j] = max profit after i days holding j crates
int N;

int main()
{
    scanf("%d%lf", &N, &P);
    for (int i=1; i<=N; ++i)
        scanf("%lf", &cost[i]);
    for (int i=0; i<MX; ++i) for (int j=0; j<MX; ++j) dp[i][j] = mp(-100000000, 0);  // cuz mEmSeT DoEsNt WOrK
    dp[0][0] = {0, 0};
    for (int i=1; i<=N; ++i)
        for (int j=0; j<=i; ++j)
        {
            //printf("dp[%d][%d] = %lf\n", i, j, dp[i][j]);
            dp[i][j] = max(dp[i-1][j], mp(dp[i-1][j+1].f + cost[i], dp[i-1][j+1].s-1));
            if (j) dp[i][j] = max(dp[i][j], mp(dp[i-1][j-1].f - cost[i], dp[i-1][j-1].s-1));
            //printf("dp[%d][%d] = %lf\n", i, j, dp[i][j].f);
            if (dp[i][j].f >= P) {
                printf("%d\n", -dp[i][j].s);
                i = N+1;
                break;
            }
        }

	return 0;
}

