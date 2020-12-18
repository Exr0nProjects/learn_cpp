/*
 * Problem cstreet (cses/graph/cstreet)
 * Create time: Thu 17 Dec 2020 @ 22:06 (PST)
 * Accept time: Thu 17 Dec 2020 @ 22:13 (PST)
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;

const ll MX = 1e3+10;
const ll MXE = 3e5+10;

ll T, P, N, M;
bool vis[MX];
typedef pair<ll, ll> St;

struct Edge { ll t, w, n; } eg[MXE]; ll hd[MX], ecnt=2;
void addEdge(ll u=0, ll v=0, ll w=0)
{
    if (!u) scanf("%lld%lld%lld", &u, &v, &w), addEdge(v, u, w);
    eg[ecnt] = { v, w, hd[u] };
    hd[u] = ecnt++;
}

int main()
{
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld%lld", &P, &N, &M);
        for (int i=1; i<=M; ++i) addEdge();

        priority_queue<St, deque<St>, greater<St> > pq;
        pq.push(mp(0, 1));

        ll ans = 0;
        while (pq.size())
        {
            ll d, c; tie(d, c) = pq.top(); pq.pop();
            if (vis[c]) continue;
            vis[c] = 1;
            ans += d;
            for (int e=hd[c]; e; e=eg[e].n)
                pq.push(mp(eg[e].w, eg[e].t));
        }
        printf("%lld\n", ans*P);
    }
}

