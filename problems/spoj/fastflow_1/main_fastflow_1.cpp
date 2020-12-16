/*
 * Problem fastflow_1 (spoj/fastflow_1)
 * Create time: Tue 15 Dec 2020 @ 21:50 (PST)
 * Accept time: Tue 15 Dec 2020 @ 22:13 (PST)
 *
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MX = 5010;
const ll MXE = 30010;

ll N, M;
ll q[MX], ql=1, qr=0;
ll dep[MX];

struct Edge { ll t, w, n; } eg[MXE<<1]; ll hd[MX], thd[MX], ecnt=2;
void addEdge(ll u=0, ll v=0, ll w=0)
{
    if (!u) scanf("%d%d%d", &u, &v, &w),
        addEdge(v, u, w);   // FIX: if (!u), add the opp (not else)
    eg[ecnt] = { v, w, hd[u] };
    hd[u] = ecnt++;
}

bool bfs()
{
    memset(dep, 0, sizeof dep);
    memset(q, 0, sizeof q);
    memcpy(thd, hd, sizeof hd);
    ql = 1, qr = 0;
    dep[1] = 2; // FIX: set dep of src after memset
    for (q[++qr] = 1; ql <= qr; ++ql)
    {
        if (q[ql] == N) return 1;
        for (int e=hd[q[ql]]; e; e=eg[e].n)
            if (!dep[eg[e].t] && eg[e].w > 0)
                dep[eg[e].t] = dep[q[ql]]+1,
                q[++qr] = eg[e].t;  // could be compressed
    }
    return 0;
}

ll aug(ll c, ll mn)
{
    if (!mn || c == N) return mn;
    ll flo = 0;
    //for (int e=hd[c]; e && mn; e=eg[e].n)
    for (; thd[c]; thd[c] = eg[thd[c]].n)
        if (dep[eg[thd[c]].t] == dep[c]+1)   // FIX: check dep in aug !!
    {
        ll g = aug(eg[thd[c]].t, min(mn, eg[thd[c]].w));
        eg[thd[c]].w -= g, eg[thd[c]^1].w += g;
        mn -= g, flo += g;
        if (!mn) break; // IF using head optimization, must have this line (else a node may get skipped if &&mn is in for condition) else it will be very slow
    }
    if (!flo) dep[c] = 0;
    return flo;
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=1; i<=M; ++i) addEdge();

    ll ans = 0;
    while (bfs())
        ans += aug(1, 1e16);
    printf("%lld\n", ans);
}

