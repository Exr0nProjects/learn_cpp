/*
 * Problem 4 (contests/post2020dec/23/4)
 * Create time: Wed 23 Dec 2020 @ 20:22 (PST)
 * Accept time: Wed 23 Dec 2020 @ 20:37 (PST)
 *
 */
#include <cstdio>
#include <algorithm>
#define ll long long
#define db(...) fprintf(stdout, __VA_ARGS__)
using namespace std;

const ll MX = 5010;
ll N, M, K, a[MX];

ll dp[MX][MX], jbest[MX], psum[MX];

int main()
{
    scanf("%lld%lld%lld", &N, &M, &K); --M;
    for (int i=1; i<=N; ++i) scanf("%lld", a+i);
    for (int i=1; i<=N; ++i) a[i] += a[i-1];
    //memset(jbest, 0x3f, sizeof jbest);
    //memset(dp, 0x3f, sizeof dp);
    ll ans = 0;
    for (int i=1; i+M<=N; ++i)
        for (int j=1; j<=K; ++j)
        {
            if (i > M+1) jbest[j] = max(jbest[j], dp[i-M-1][j]);
            dp[i][j] = jbest[j-1] + a[i+M] - a[i-1];
            //db("%d %d -> %d .. %d\n", i, j, jbest[j-1], dp[i][j]);
            ans = max(ans, dp[i][j]);
        }
    printf("%lld\n", ans);
}

