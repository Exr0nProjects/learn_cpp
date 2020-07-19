/*
 * Problem 13 (tcp2020/13)
 * Create time: Sun 19 Jul 2020 @ 10:01 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
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
const ll MX = 1111;
int T, N, cost[MX], val[MX], dp[MX][MX];

int main()
{
    scanf("%d%d", &T, &N);
    for (int i=0; i<N; ++i)
        scanf("%d%d", &cost[i], &val[i]);

    int ret = 0;
    for (int i=cost[0]; i<T; ++i)
    {
        dp[0][i] = val[0];
        ret = max(ret, dp[0][i]);
    }
    for (int i=1; i<N; ++i)
        for (int j=0; j<=T; ++j)
        {
            if (cost[i] >= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]]+val[i]);
            else dp[i][j] = dp[i-1][j];
            ret = max(ret, dp[i][j]);
        }
    printf("%d\n", ret);

	return 0;
}

