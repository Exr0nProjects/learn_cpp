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
ll dist[MX];

typedef tuple<ll, ll, ll> St;
stack<ll> pre[MX];
queue<St> store[MX];

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
    memset(dist, 0x3f, sizeof dist);
    priority_queue<St, deque<St>, greater<St> > pq;
    pq.push(mt(0, 1, -1));
    while (pq.size())
    {
        ll d, c, p; tie(d, c, p) = pq.top(); pq.pop();
        printf("at %d from %d after %d\n", c, p, d);
        if (dist[c] <= d) { store[c].push(mt(d, c, p)); continue; }
        dist[c] = d;
        pre[c].push(p);
        //printf("continuing\n");
        if (c == N && K--)
        {
            printf("%lld ", d);
            //printf("set pre[%d] to %d\n", c, pre[c]);
            while (~c && pre[c].size())
            {
                printf("back to %d\n", c);
                dist[c] = 1e17;
                if (store[c].size())
                    pq.push(store[c].front()),
                    store[c].pop();
                ll t = c; c = pre[c].top();
                pre[t].pop();
            }
        } if (!K) break;
        for (int e=hd[c]; e; e=eg[e].n)
            pq.push(mt(d+eg[e].w, eg[e].t, c));
    }
    printf("\n");
    return 0;
}

