/*
 * Problem course_schedule2 (cses/graph/course_schedule2)
 * Create time: Thu 17 Dec 2020 @ 23:13 (PST)
 * Accept time: Thu 17 Dec 2020 @ 23:20 (PST)
 *
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MX = 1e5+10;
ll N, M;
ll vis[MX], ans[MX], acnt=0;
struct Edge { ll t, n; } eg[MX<<2]; ll hd[MX], ecnt=2;
void addEdge()
{
    ll u, v; scanf("%lld%lld", &u, &v);
    eg[ecnt] = { v, hd[u] };
    hd[u] = ecnt++;
}

bool topo(ll c)
{
    if (vis[c]) return vis[c] > 0;
    vis[c] = 1;
    for (int e=hd[c]; e; e=eg[e].n)
        if (topo(eg[e].t)) return 1;
    vis[c] = -1;
    ans[acnt++] = c;    // FIX: push to the stack
    return 0;
}

int main()
{
    scanf("%lld%lld", &N, &M);
    for (int i=1; i<=M; ++i) addEdge();
    ll bad = 0;
    for (int i=1; i<=N; ++i) bad |= topo(i);

    if (bad) { printf("IMPOSSIBLE\n"); return 0; }
    while (acnt--) printf("%d ", ans[acnt]); printf("\n");
}

