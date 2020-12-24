/*
 * Problem 6 (contests/post2020dec/23/6)
 * Create time: Thu 24 Dec 2020 @ 12:26 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define ord(c) (ll)(c - 'A' +1)
#define db(...) fprintf(stdout, __VA_ARGS__)
//#define db(...)
using namespace std;

ll pow(ll b, ll e, ll m)
{
    ll ans = 1;
    assert(e >= 0);
    for (; e; e>>=1, (b*=b)%=m)
        if (e&1) (ans *= b) %= m;
    return ans;
}

const ll MX = 110;
const ll MXE = 10010;
const ll P = 29;
const ll MOD1 = 1e9+7;
const ll MOD2 = 1e9+9;

ll N, M, Q;
ll adj[30][30], dp[MX][MX];
ll phash[MX];
unordered_map<ll, ll> mem;
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

ll op(ll i, ll j) // inc
{
    ll &ret = dp[i][j];
    //ll hash = (((phash[j]>>32) - (phash[i-1]>>32)*pow(P, j-i+1, MOD1)%MOD1)<<32) | ((phash[j]&((1ll<<32)-1ll))-(phash[i-1]&((1ll<<32)-1ll))*pow(P, j-i+1, MOD2)%MOD2);
    //if (mem.count(hash)) ret = hash;
    if (i == j) ret = 1<<ord(buf[i]);
    if (i+1 == j) ret = adj[ord(buf[i])][ord(buf[j-1])];
    if (!ret)
    for (int k=i; k<j; ++k)
    {
        ll l = op(i, k), r = op(k+1, j);
        if (!l || !r) continue;
        for (int xl=1; xl<27; ++xl) if (l>>xl & 1)
        for (int xr=1; xr<27; ++xr) if (r>>xr & 1)
            ret |= adj[xl][xr];
    }
    //db("%d..%d got ", i, j); dbm(ret); db("(%d)\n", ret>>ord('S')&1);
    if (ret>>ord('S')&1) tail[j+1].push_back(i);
    //mem[hash] = ret;
    return ret;
}

int main()
{
    scanf("%lld", &M);
    for (int i=1; i<=M; ++i)
    {
        char u, a, b; scanf("\n%c%c%c", &u, &a, &b);
        adj[ord(a)][ord(b)] |= (1<<ord(u)); // FIX: |= to 1<< ord not just ord smah
    }

    scanf("%lld", &Q);
    for (int i=1; i<=Q; ++i)
    {
        scanf("%s", buf+1);
        N = strlen(buf+1);
        for (int i=1; i<=N; ++i)
            //printf("%llx (%lld) * %lld + %lld = %lld (%llx)\n", phash[i-1]>>32, phash[i-1]>>32, P, ord(buf[i]), (((phash[i-1ll]>>32ll)*P%MOD1 + ord(buf[i])) % MOD1), (((phash[i-1ll]>>32ll)*P%MOD1 + ord(buf[i])) % MOD1)),
            phash[i] = ((((phash[i-1ll]>>32ll)*P%MOD1 + ord(buf[i])) % MOD1)<<32ll) | (((phash[i-1] & ((1ll<<32ll)-1ll))*P%MOD2 + ord(buf[i]))%MOD2);
        //for (int i=1; i<=N; ++i) db("%3d: %20llx ( %10llx %10llx )\n", i, phash[i], phash[i]>>32, phash[i] &((1ll<<32ll)-1ll));

        //for (int i=1; i<=N; ++i) { for (int j=i; j<=N; ++j)
        //{
        //    ll hash = (((phash[j]>>32) - (phash[i-1]>>32)*pow(P, j-i+1, MOD1)%MOD1)<<32) | ((phash[j]&((1ll<<32)-1ll))-(phash[i-1]&((1ll<<32)-1ll))*pow(P, j-i+1, MOD2)%MOD2);
        //    db("hash %3d..%3d = %20llx %20llx -> %20llx\n", i, j, (((phash[j]>>32) - (phash[i-1]>>32)*pow(P, j-i+1, MOD1)%MOD1)), ((phash[j]&((1ll<<32)-1ll))-(phash[i-1]&((1ll<<32)-1ll))*pow(P, j-i+1, MOD2)%MOD2), hash);
        //} }
        memset(dp, 0, sizeof dp);
        for (int i=1; i<=N; ++i) tail[i].clear();
        op(0, N);

        for (int i=1; i<=N; ++i) db("tail %d has %d\n", i, tail[i].size());

        memset(dp2, 0x3f, sizeof dp2);
        dp2[0] = 0;
        for (int j=1; j<=N; ++j)
            for (ll i : tail[j])
                dp2[j] = min(dp2[j], dp2[i]+1);

        if (dp2[N] >= 1e9) printf("NIE\n");
        else printf("%lld\n", dp2[N]);
    }
}

