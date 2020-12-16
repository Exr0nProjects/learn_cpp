/*
 * Problem ezdijkst_1 (spoj/ezdijkst_1)
 * Create time: Wed 16 Dec 2020 @ 13:32 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
const ll MX = 1e4+10;

ll T, N, M, A, B, dist[MX];
typedef pair<ll, ll> St;
struct Edge { ll t, w, n; } eg[MX<<2]; ll hd[MX], ecnt=2;
void addEdge()
{
    ll u, v, w; scanf("%d%d%d", &u, &v, &w);
    eg[ecnt] = { v, w, hd[u] };
    hd[u] = ecnt++;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        memset(dist, 0x3f, sizeof dist);
        memset(eg, 0, sizeof eg);
        memset(hd, 0, sizeof hd);

        scanf("%d%d", &N, &M);
        for (int i=1; i<=M; ++i) addEdge();
        scanf("%d%d", &A, &B);

        priority_queue<St, deque<St>, greater<St> > pq;
        pq.push(mp(0, A));
        while (pq.size())
        {
            ll d, c; tie(d, c) = pq.top(); pq.pop();
            if (dist[c] <= d) continue;
            dist[c] = d;

            if (d == B) { B = -1, a = d; break; }
            for (int e=hd[c]; e; e=eg[e].n)
                pq.push(mp(eg[e].w + d, eg[e].t));
        }
    }
}

