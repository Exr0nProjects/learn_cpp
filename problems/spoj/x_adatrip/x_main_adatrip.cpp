/*
 * Problem adatrip (spoj/adatrip)
 * Create time: Sat 16 Jan 2021 @ 13:22 (PST)
 * Accept time: Sat 16 Jan 2021 @ 13:46 (PST)
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS__)
#define mt make_tuple
using namespace std;
const ll MX = 5e5+10;
const ll MXE = 2e6+10;          // FIX: bidirectional edges needs 2x storage

ll N, M, Q;
ll dist[MX];
struct Edge { ll t, w, n; } eg[MXE]; ll hd[MX], ecnt=2;
void addEdge(ll u=0, ll v=0, ll w=0, ll b=0)
{
	if (!b) scanf("%lld%lld%lld", &u, &v, &w), addEdge(v, u, w, 1); // FIX: need b=0 bc u, v, w can all be zero in the input
	eg[ecnt] = { v+1, w, hd[u+1] }; hd[u+1] = ecnt++;
}

tuple<ll, ll> dijkstra(ll src)
{
	memset(dist, 0x3f, sizeof dist);
	ll mx = 0, mxcnt=0;
	typedef tuple<ll, ll> St; // < dist, cur >
	priority_queue<St, deque<St>, greater<St> > pq;
	pq.push(mt(0, src));
	while (pq.size()) {
		ll d, c; tie(d, c) = pq.top(); pq.pop();
		if (dist[c] < d) continue;
		dist[c] = d;

		if (d > mx) mx = d, mxcnt=0;
		if (d == mx) ++mxcnt;

		for (int e=hd[c]; e; e=eg[e].n)
			if (dist[eg[e].t] > d + eg[e].w)
				dist[eg[e].t] = d + eg[e].w,
				pq.push(mt(d + eg[e].w, eg[e].t));
	}
	return mt(mx, mxcnt);
}

int main()
{
	scanf("%lld%lld%lld", &N, &M, &Q);
	for (int i=1; i<=M; ++i) addEdge();
	for (int i=1; i<=Q; ++i) {
		ll src; scanf("%lld", &src); ++src;
		ll d, n; tie(d, n) = dijkstra(src);
		printf("%lld %lld\n", d, n);
	}
}
