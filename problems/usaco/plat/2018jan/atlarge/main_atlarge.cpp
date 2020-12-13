/*
 * Problem atlarge (usaco/plat/2018jan/atlarge)
 * Create time: Sun 13 Dec 2020 @ 13:46 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MX = 7e4+10;
struct Edge { ll t, n; } eg[MX<<2]; ll hd[MX], ecnt=2;
void addEdge(ll u=0, ll v=0, bool b=1)
{
    if (!u) scanf("%d%d", &u, &v);
    eg[ecnt] = { v, hd[u] };
    hd[u] = ecnt++;
    if (b) addEdge( v, u, 0 );
}
ll N, near[MX], par[MX];

ll knear(ll c, ll p=0)
{
    par[c] = p;
    if (!eg[hd[c]].n) return near[c] = 0;
    near[c] = 1e9;
    for (int e=hd[c]; e; e=eg[e].n) if (eg[e].t != p)
        near[c] = min(near[c], knear(eg[e].t, c)+1);    // FIX: +1 inside multi-min not outside
    return near[c];
}

void knear2(ll c, ll p=0)
{
    for (int e=hd[c]; e; e=eg[e].n) if (eg[e].t != p)
        near[eg[e].t] = min(near[eg[e].t], near[c]+1),
        knear2(eg[e].t, c);
}

ll dfs(ll c, ll p=0, ll d=0)
{
    //for (int i=1; i<=d; ++i) printf("|   "); printf("at %d <- %d after %d\n", c, p, d);
    if (!eg[hd[c]].n) return 0;
    if (d >= near[c]) return 0;
    ll ret = -2;
    for (int e=hd[c]; e; e=eg[e].n, ++ret)
        if (eg[e].t != p)
            ret += dfs(eg[e].t, c, d+1);
    //for (int i=1; i<=d; ++i) printf("|   "); printf("=> %d\n", ret);
    return ret;
}

int main()
{
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w+", stdout);
    scanf("%d", &N);
    for (int i=1; i<N; ++i) addEdge();

    ll rt = 0;
    for (int i=1; !rt && i<=N; ++i) if (eg[hd[i]].n) rt = i;
    knear(rt);
    //for (int i=1; i<=N; ++i) printf("%3d",      i ); printf("\n");
    //for (int i=1; i<=N; ++i) printf("%3d", near[i]); printf("\n");
    knear2(rt);
    //for (int i=1; i<=N; ++i) printf("%3d", near[i]); printf("\n");
    //{ rt = i; knear(i); knear2(i); break; }
    //for (int i=1; i<=N; ++i) near[i] = min(near[i], near[par[i]]+1);
    for (int i=1; i<=N; ++i)
        if (!eg[hd[i]].n) printf("1\n");
        else printf("%d\n", dfs(i) +2);
}

