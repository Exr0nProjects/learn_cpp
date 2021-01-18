/*
 * Problem iitkwpcg (spoj/iitkwpcg)
 * Create time: Sun 17 Jan 2021 @ 20:51 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 2e5+10;
ll T, N, M;
ll vis[MX];
struct Edge { ll t, w, n; } eg[MX<<1]; ll hd[MX], ecnt=2;
void addEdge(ll u=0, ll v=0, ll w=0)
{
	if (!u) scanf("%lld%lld%lld", &u, &v, &w), addEdge(v, u, w);
	eg[ecnt] = { v, __builtin_ctzll(w), hd[u] }; hd[u] = ecnt++;
}

int main()
{
	scanf("%lld", &T);
	while (T--) {
		memset(eg, 0, sizeof eg);
		memset(hd, 0, sizeof hd);
		memset(vis, 0, sizeof vis);
		scanf("%lld%lld", &N, &M);
		for (int i=1; i<=M; ++i) addEdge();
		// for (int i=1; i<=N; ++i) for (int e=hd[i]; e; e=eg[e].n) db("%d --%d--> %d\n", i, eg[e].w, eg[e].t);
		// db("===========\n");
		typedef tuple<ll, ll> St; // < dist, cur >
		priority_queue<St, deque<St>, greater<St> > pq;
		pq.push(mt(0, 1));
		ll ans = 0;
		while (pq.size()) {
			ll d, c; tie(d, c) = pq.top(); pq.pop();
			if (vis[c]) continue; vis[c] = 1;
			ans += d;
			for (int e=hd[c]; e; e=eg[e].n)
				pq.push(mt(eg[e].w, eg[e].t));
		}
		printf("%lld\n", ans+1);
	}
}
