/*
 * Problem planets_and_kingdoms (cses/graph/planets_and_kingdoms)
 * Create time: Tue 15 Dec 2020 @ 22:50 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MX = 1e5+10;
ll N, M;
ll pre[MX], low[MX], ans[MX], acnt=0, ncnt=0;
ll sk[MX], scnt=0;

struct Edge { ll t, n; } eg[MX<<2]; ll hd[MX], ecnt=2;
void addEdge(ll u=0, ll v=0)
{
    if (!u) scanf("%d%d", &u, &v), addEdge(v, u);
    eg[ecnt] = { v, hd[u] }; hd[u] = ecnt++;
}

ll tarjan(ll c)
{
    // init
    pre[c] = ++ncnt;
    low[c] = pre[c];
    sk[scnt++] = c;
    // prop
    for (int e=hd[c]; e; e=eg[e].t)
    {
        if (!pre[eg[e].t]) low[c] = min(low[c], tarjan(eg[e].t));
        else if (!ans[eg[e].t]) low[c] = min(low[c], pre[eg[e].t]);
    }
    // report
    if (low[c] == pre[c])
    {
        while (sk[scnt] != c)
            ans[sk[scnt--]] = c;
        ans[c] = c, scnt--;
    }
    return low[c];
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=1; i<=M; ++i) addEdge();

    for (int i=1; i<=N; ++i) if (!ans[i])
        tarjan(i);
    printf("%d\n", acnt);
    for (int i=1; i<=N; ++i) printf("%d ", ans[i]);
}

