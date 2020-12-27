/*
 * Problem 3 (contests/post2020dec/23/3)
 * Create time: Sun 27 Dec 2020 @ 12:51 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 1e3+10;
ll N, a[MX<<1];
ll dp[MX][MX];  // dp[i][j] = max power when merging i thru j

int main()
{
    scanf("%lld", &N);
    for (int i=1; i<=N; ++i) scanf("%lld", a+i), a[N+i] = a[i];


    for (ll l=1; l+2 <= 2*N; ++l)
        dp[l][l+1] = max(a[l], a[l+1])*max(a[l], a[l+1])*min(a[l], a[l+1]); // FIX: special case for len=2
    for (ll n=2; n<N; ++n)
        for (ll l=1; l+n <=2*N; ++l)
        {
            ll r = l+n;
            for (ll i=l; i<r; ++i)
                dp[l][r] = max(dp[l][r], dp[l][i] + dp[i+1][r] + a[l]*a[i+1]*a[r]);
            //for (int i=1; i<=l; ++i) db("   "); for (int i=l; i<=r; ++i) db("%3d", a[i]); for (int i=r; i<=2*N; ++i) db("   "); db(":   %lld\n", dp[l][r]);
        }
    ll ans = 0;
    for (int i=1; i<=N; ++i)
        ans = max(ans, dp[i][i+N-1]);
    printf("%lld\n", dp[1][N]);
}

