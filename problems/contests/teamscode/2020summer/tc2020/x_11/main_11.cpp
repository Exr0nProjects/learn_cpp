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
dl dp[MX][MX][MX];       // dp[i][j][k] = max profit after i days holding j crates and k transactions, FIX: not optimal to take max profit, can't just take min transactions, so one must become a dp dimension
int N;

int main()
{
    scanf("%d%lf", &N, &P);
    for (int i=1; i<=N; ++i)
        scanf("%lf", &cost[i]);
    for (int i=0; i<MX; ++i) for (int j=0; j<MX; ++j) for (int k=0; k<MX; ++k) dp[i][j][k] = -100000000;  // cuz mEmSeT DoEsNt WOrK
    dp[0][0][0] = 0;
    int mn = 1e8;
    for (int i=1; i<=N; ++i)
        for (int j=0; j<=i; ++j)
            for (int k=0; k<=i; ++k)
                if (k%2 == j%2) // FIX: legal transaction numbers
                {
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j+1][k-1] + cost[i]);      // do nothing or sell
                    if (j) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-1] - cost[i]); // buy
                    //printf("dp[%d][%d][%d] = %lf\n", i, j, k, dp[i][j][k]);
                    if (dp[i][j][k] >= P) mn = min(mn, k);
                }
    printf("%d\n", mn);

	return 0;
}

