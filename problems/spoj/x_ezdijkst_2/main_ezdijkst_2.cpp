/*
 * Problem ezdijkst_2 (spoj/ezdijkst_2)
 * Create time: Thu 17 Dec 2020 @ 23:21 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
const ll MX = 1e4+10;
typedef pair<ll, ll> St;

ll T, N, M, A, B;
ll dist[MX];
struct Edge { ll t, w, n; } eg[MX]; ll hd[MX], ecnt=2;
void addEdge()
{
    ll u, v, w; scanf("%lld%lld%lld", &u, &v, &w);
    eg[ecnt] = { v, w, hd[u] }; hd[u] = ecnt++;
}

int main()
{
    scanf("%lld", &T); while (T--)
    {
        memset(eg, 0, sizeof eg);
        memset(hd, 0, sizeof hd);
        memset(dist, 0x3f, sizeof dist);
        scanf("%lld%lld", &N, &M);
        for (int i=1; i<=M; ++i) addEdge();
        scanf("%lld%lld", &A, &B);

        priority_queue<St, deque<St>, greater<St> > pq;
        pq.push(mp(0, A));  // FIX: start from A, not 1
        while (pq.size())
        {
            ll d, c; tie(d, c) = pq.top(); pq.pop();
            if (dist[c] <= d) continue;
            dist[c] = d;
            if (c == B) { B=0, printf("%lld\n", d); break; }
            for (int e=hd[c]; e; e=eg[e].n)
                pq.push(mp(d+eg[e].w, eg[e].t));
        }
        if (B) printf("NO\n");
    }
}

