/*
 * Problem 6 (contests/post2020dec/23/6)
 * Create time: Thu 24 Dec 2020 @ 12:26 (PST)
 * Accept time: Thu 24 Dec 2020 @ 16:44 (PST)
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define ord(c) (c - 'A' +1)
#define db(...) fprintf(stdout, __VA_ARGS__)
//#define db(...)
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;

const ll MX = 110;
const ll MXE = 10010;

ll N, M, Q;
ll adj[30][30];
vector<pair<ll, ll> > radj[MX];
char dp[MX][MX][30];
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

bool op(ll i, ll j, ll c) // inc exc
{
    if (~dp[i][j][c]) return dp[i][j][c];
    if (i == j) return ord(buf[i]) == c;
    if (i+1 == j) return adj[ord(buf[i])][ord(buf[j])]>>c&1;
    char &ret = dp[i][j][c]; ret = 0;
    //db("%d %d %d\n", i, j, c);
    for (int k=i; k<j; ++k)
        for (auto p : radj[c])
            //db("trying k = %d (%d, %d)\n", k, p.f, p.s),
            ret |= op(i, k, p.f) && op(k+1, j, p.s);
    //db("%d %d %d got %d\n" ,i, j, c, ret);
    //db("%d..%d got ", i, j); dbm(ret); db("(%d)\n", ret>>ord('S')&1);
    if (c == ord('S') && ret) tail[j].pb(i);
    return ret;
}

int main()
{
    scanf("%d", &M);
    for (int i=1; i<=M; ++i)
    {
        char u, a, b; scanf("\n%c%c%c", &u, &a, &b);
        adj[ord(a)][ord(b)] |= (1<<ord(u)); // FIX: |= to 1<< ord not just ord smah
        radj[ord(u)].pb(mp(ord(a), ord(b)));
    }

    scanf("%d", &Q);
    for (int i=1; i<=Q; ++i)
    {
        scanf("%s", buf+1);
        N = strlen(buf+1);

        memset(dp, -1, sizeof dp);
        for (int i=1; i<=N; ++i) tail[i].clear();
        //op(1, N, ord('S'));  // doesn't matter what letter we want it to be anyway

        //for (int i=1; i<=N; ++i) db("tail %d has %d\n", i, tail[i].size());

        memset(dp2, 0x3f, sizeof dp2);
        dp2[0] = 0;
        for (int j=1; j<=N; ++j)
            for (int i=1; i<=j; ++i)
                if (op(i, j, ord('S')))
                    dp2[j] = min(dp2[j], dp2[i-1]+1);
            //for (ll i : tail[j])
            //    dp2[j] = min(dp2[j], dp2[i-1]+1);

        if (dp2[N] >= 1e9) printf("NIE\n");
        else printf("%lld\n", dp2[N]);
    }
}

