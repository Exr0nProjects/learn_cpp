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
ll N, near[MX], snear[MX];

ll knear(ll c, ll p=0)
{
    if (!eg[hd[c]].n) return near[c] = 0;
    near[c] = snear[c] = 1e9;
    for (int e=hd[c]; e; e=eg[e].n) if (eg[e].t != p)
    {
        ll g = knear(eg[e].t, c);
        if (g < near[c]) snear[c] = near[c], near[c] = g;
        else if (g < snear[c]) snear[c] = g;
    }
    return near[c];
}

ll dfs(ll c, ll p=0, ll d=0)
{
    if (!eg[hd[c]].n) return 0;
    if (d >= near[c]) return 0;
    ll ret = -2;
    for (int e=hd[c]; e; e=eg[e].n, ++ret)
        if (eg[e].t != p)
            ret += dfs(eg[e].t, c, d+1);
    return ret;
}

int main()
{
    scanf("%d", &N);
    for (int i=1; i<N; ++i) addEdge();
    for (int i=1; i<=N; ++i)
        if (!eg[hd[i]].n) printf("1\n");
        else printf("%d\n", dfs(i) +2);
}

