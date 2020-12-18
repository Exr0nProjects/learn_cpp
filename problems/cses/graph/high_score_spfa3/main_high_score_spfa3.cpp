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
    if (vbad[c]) return vbad[c];
    if (c == N) return 1;
    vbad[c] = 1;
    for (int e=hd[c]; e; e=eg[e].n) if (bad(eg[e].t)) return 1;
    return 0;   // FIX: forgot default return, should look at compiler warnings
}

int main()
{
    scanf("%lld%lld\n", &N, &M);
    for (int i=1; i<=M; ++i) addEdge();
    memset(dist, 0x3f, sizeof dist);

    dist[1] = 0;
    for (q[++qr] = 1; ql-1 != qr; ++ql%=MX<<2)
    {
        inq[q[ql]] = 0;
        //printf("at %d (%d..%d)\n", q[ql], ql, qr);
        if (vis[q[ql]]++ > N) if (bad(q[ql])) break;
        for (int e=hd[q[ql]]; e; e=eg[e].n)
        {
            //printf("would go %d -> %d but %lld > %lld?\n", q[ql], eg[e].t, dist[eg[e].t], dist[q[ql]] + eg[e].w);
            if (dist[eg[e].t] > dist[q[ql]] + eg[e].w)
            {

                dist[eg[e].t] = dist[q[ql]] + eg[e].w;
                if (!inq[eg[e].t]) q[++qr%=MX<<2] = eg[e].t, inq[eg[e].t] = 1;
            }
        }
    }
    if (ql-1 != qr) printf("-1\n"); // reached break; instead of normal for loop break
    else printf("%lld\n", -dist[N]);
}

