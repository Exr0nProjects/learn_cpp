/*
 * Problem high_score_spfa3 (cses/graph/high_score_spfa3)
 * Create time: Thu 17 Dec 2020 @ 23:29 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MX = 2510;

ll N, M, dist[MX];
ll q[MX<<2], ql=1, qr=0;
ll vis[MX], inq[MX];
bool vbad[MX];
struct Edge { ll t, w, n; } eg[MX<<2]; ll hd[MX], ecnt=2;
void addEdge()
{
    ll u, v, w; scanf("%lld%lld%lld", &u, &v, &w);
    eg[ecnt] = { v, -w, hd[u] }; hd[u] = ecnt++;
}

bool bad(ll c)
{
    if (vbad[c]) return 1;
    vbad[c] = 1;
    for (int e=hd[c]; e; e=eg[e].n) bad(eg[e].t);
}

int main()
{
    scanf("%lld%lld\n", &N, &M);
    for (int i=1; i<=M; ++i) addEdge();
    memset(dist, 0x3f, sizeof dist);

    for (q[++qr] = 1; ql+1 != qr; ++ql%=MX<<2)
    {
        inq[q[ql]] = 0;
        if (vis[q[ql]]++ > N) if (bad(q[ql])) break;
        for (int e=hd[q[ql]]; e; e=eg[e].n)
            if (dist[eg[e].t] > dist[q[ql]] + eg[e].w)
            {
                dist[eg[e].t] = dist[q[ql]] + eg[e].w;
                if (!inq[eg[e].t]) q[++qr%=MX<<2] = eg[e].t, inq[eg[e].t] = 1;
            }
    }
    if (ql+1 != qr) printf("-1\n"); // reached break; instead of normal for loop break
    else printf("%d\n", -dist[N]);
}

