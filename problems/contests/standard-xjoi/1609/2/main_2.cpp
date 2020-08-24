/*
 * Problem 2 (contests/standard-xjoi/2)
 * Create time: Sat 22 Aug 2020 @ 21:20 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 111;
const int S = MX*1000;
int N, best=0, s[MX], f[MX], dp[MX][S*2]; // dp[i][j] = max sum of `f` from first `i` cows with sum of `s` = `j`

int main()
{
    scanf("%d", &N);
    for (int i=1; i<=N; ++i) scanf("%d%d", &s[i], &f[i]);

    memset(dp, 0x8f, sizeof dp);

    dp[0][S] = 0;   // FIX: base-case: dp[0][S] not dp[0][0] because everything is shifted
    for (int i=1; i<=N; ++i)
    {
        for (int j=-S; j<S; ++j)
        {
            if (s[i] + f[i] >= 0)
                dp[i][j+S] = dp[i-1][j-s[i]+S]+f[i];
            else dp[i][j+S] = dp[i-1][j+S];
            //dp[i][j+S] = max(dp[i-1][j+S], dp[i-1][j-s[i]+S]+f[i]);
            //printf("i %d j %d dp[i][j] %d\n", i, j, dp[i][j+S]);
            if (dp[i][j+S] >= 0 && j >= 0)
                best = max(best, dp[i][j+S]+j);
        }
        printf("i = %d best = %d\n", i, best);
    }
    printf("%d\n", best);

	return 0;
}

