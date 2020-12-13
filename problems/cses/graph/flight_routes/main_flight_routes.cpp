/*
 * Problem flight_routes (cses/graph/flight_routes)
 * Create time: Sat 12 Dec 2020 @ 19:47 (PST)
 * Accept time: [!meta:end!]
 *  can't just print the next couple best..
 */
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
using namespace std;
const int MX = 1e5+10;
ll N, M, K;
ll dist[MX], pre[MX];

struct Edge { ll t, w, n; } eg[MX<<2]; ll hd[MX], ecnt=2;
void addEdge()
{
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    eg[ecnt] = { v, w, hd[u] };
    hd[u] = ecnt++;
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    for (int i=1; i<=M; ++i) addEdge();
    typedef tuple<ll, ll, ll> St;
    //memset(dist, 0x3f, sizeof dist);
    priority_queue<St, deque<St>, greater<St> > pq;
    pq.push(mt(0, 1, {1}));
    while (pq.size())
    {
        ll d, c; tie(d, c) = pq.top(); pq.pop();
        //printf("at %d after %d   (hav? %d)\n", c, d, dist[c].count(d));
        if (c == N && K--)
        {
            printf("%d ", d);

        }
        if (!K) break;
        //if (dist[c] <= d) continue;
        if (dist[c].count(d)) continue;
        dist[c].insert(d);
        for (int e=hd[c]; e; e=eg[e].n)
            pq.push(mt(d+eg[e].w, eg[e].t));
    }
    printf("\n");
    return 0;
}

