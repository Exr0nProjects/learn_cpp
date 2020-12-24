/*
 * Problem 6 (contests/post2020dec/23/6)
 * Create time: Thu 24 Dec 2020 @ 12:26 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define ord(c) (c - 'A' +1)
//#define db(...) fprintf(stdout, __VA_ARGS__)
#define db(...)
using namespace std;

const ll MX = 110;
const ll MXE = 10010;
const ll mod = 1e6+3;

ll N, M, Q;
ll adj[30][30], dp[MX][MX];
ll mem[1e6+10];
vector<ll> tail[MX];
ll dp2[MX];
char buf[MX];

ll dbm(ll mask)
{
    for (int i=1; i<27; ++i)
        db("%3c", mask>>i&1? i+'A'-1 : ' ');
    db("\n");
    return mask;
}

ll op(ll i, ll j) // inc exc
{
    ll &ret = dp[i][j];
    //if (i+1 == j) ret = dbm(1<<ord(buf[i]));
    //if (i+2 == j) ret = dbm(adj[ord(buf[i])][ord(buf[j-1])]);
    if (i+1 == j) ret = 1<<ord(buf[i]);
    if (i+2 == j) ret = adj[ord(buf[i])][ord(buf[j-1])];
    if (!ret)
    for (int k=i+1; k<j; ++k)
    {
        ll l = op(i, k), r = op(k, j);
        //db("l "); dbm(l); db("r "); dbm(r);
        if (!l || !r) continue;
        for (int xl=1; xl<27; ++xl) if (l>>xl & 1)
        for (int xr=1; xr<27; ++xr) if (r>>xr & 1)
            ret |= adj[xl][xr];
    }
    db("%d..%d got ", i, j); dbm(ret); db("(%d)\n", ret>>ord('S')&1);
    if (ret>>ord('S')&1) tail[j].push_back(i);
    return ret;
}

int main()
{
    scanf("%d", &M);
    for (int i=1; i<=M; ++i)
    {
        char u, a, b; scanf("\n%c%c%c", &u, &a, &b);
        //db("got '%c' '%c' '%c'\n", u, a, b);
        adj[ord(a)][ord(b)] |= (1<<ord(u)); // FIX: |= to 1<< ord not just ord smah
    }
    //db("adj[1][1] = %d\n", adj[1][1]);
    //for (int i=1; i<=30; ++i) if (adj[1][1]>>i &1) db("%3d", i); else db("   ");
    //for (int i=1; i<27; ++i) for (int j=1; j<27; ++j)
    //    db("i %d j %d :   ", i, j), dbm(adj[i][j]);

    scanf("%d", &Q);
    for (int i=1; i<=Q; ++i)
    {
        scanf("%s", buf);
        N = strlen(buf);
        ll g = op(0, N);

        memset(dp, 0, sizeof dp);
        for (int i=1; i<=N; ++i) tail[i].clear();
        op(0, N);

        //for (int i=1; i<=N; ++i) db("tail %d has %d\n", i, tail[i].size());

        memset(dp2, 0x3f, sizeof dp2);
        dp2[0] = 0;
        for (int j=1; j<=N; ++j)
            for (ll i : tail[j])
                dp2[j] = min(dp2[j], dp2[i]+1);

        if (dp2[N] >= 1e9) printf("NIE\n");
        else printf("%lld\n", dp2[N]);
    }
}

