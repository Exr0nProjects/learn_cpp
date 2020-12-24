/*
 * Problem 6 (contests/post2020dec/23/6)
 * Create time: Thu 24 Dec 2020 @ 12:26 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define ord(c) (c - 'A' +1)
#define db(...) fprintf(stdout, __VA_ARGS__)
using namespace std;

const ll MX = 110;
const ll MXE = 10010;

ll N, M, Q;
ll adj[30][30], dp[MX][MX];
vector<ll> tail[MX];
ll dp2[MX];
char buf[MX];

ll op(ll i, ll j) // inc exc
{
    if (i+1 == j) return ord(buf[i]);
    if (dp[i][j]) return dp[i][j];
    if (i+2 == j) return adj[i][j];
    ll &ret = dp[i][j];
    for (int k=i+1; k<j; ++k)
    {
        ll l = op(i, k), r = op(k, j);
        for (int xl=1; xl<30; ++xl) if (l>>xl & 1)
        for (int xr=1; xr<30; ++xr) if (r>>xr & 1)
            ret |= adj[xl][xr];
    }
    if (ret>>ord('S')&1) tail[j+1].push_back(i+1);
    return ret;
}

int main()
{
    scanf("%d", &M);
    for (int i=1; i<=M; ++i)
    {
        char u, a, b; scanf("\n%c%c%c", &u, &a, &b);
        adj[ord(a)][ord(b)] |= ord(u);
    }
    scanf("%d", &Q);
    for (int i=1; i<=Q; ++i)
    {
        scanf("%s", buf);
        N = strlen(buf);
        ll g = op(0, N);

        memset(dp, 0, sizeof dp);
        for (int i=1; i<=N; ++i) tail[i].clear();
        op(0, N);

        memset(dp2, 0x3f, sizeof dp2);
        dp2[0] = 0;
        for (int j=1; j<=N; ++j)
            for (ll i : tail[j])
                dp2[j] = min(dp2[j], dp2[i-1]+1);

        if (ans >= 1e9) printf("NIE\n");
        else printf("%lld\n", ans);
    }
}

