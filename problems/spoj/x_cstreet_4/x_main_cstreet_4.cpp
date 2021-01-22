/*
 * Problem cstreet_4 (spoj/cstreet_4)
 * Create time: Fri 22 Jan 2021 @ 11:44 (PST)
 * Accept time: Fri 22 Jan 2021 @ 11:51 (PST)
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define F(i, N) for (int i=1; i<=N; ++i)
#define db(...) fprintf(stderr, __VA_ARGS__)
#define mt make_tuple
using namespace std;

const ll MX = 1e3+10;
const ll MXE = 3e5+10;

ll T, P, N, M;
ll vs[MX]; // FIX: prim needs vis array
struct Edge { ll t, w, n; } eg[MXE<<1]; ll hd[MX], ecnt=2;
void addEdge(ll u=0, ll v=0, ll w=0)
{
	if (!u) scanf("%lld%lld%lld", &u, &v, &w), addEdge(v, u, w);
	eg[ecnt] = { v, w, hd[u] }; hd[u] = ecnt++;
}

int main()
{
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld%lld%lld", &P, &N, &M);
		memset(eg, 0, sizeof eg);
		memset(hd, 0, sizeof hd);
		memset(vs, 0, sizeof vs);
		F(i, M) addEdge();
		typedef tuple<ll, ll> St;
		priority_queue<St, deque<St>, greater<St> > pq;
		pq.push(mt(0, 1));
		ll ans = 0;
		while (pq.size()) {
			ll d, c; tie(d, c) = pq.top(); pq.pop();
			if (vs[c]) continue; vs[c] = 1;
			// db("at %d after %d\n", c, d);
			ans += d;
			for (int e=hd[c]; e; e=eg[e].n)
				pq.push(mt(eg[e].w, eg[e].t));
		}
		printf("%lld\n", ans * P);
	}
}
