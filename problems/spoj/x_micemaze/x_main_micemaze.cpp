/*
 * Problem micemaze (spoj/micemaze)
 * Create time: Mon 11 Jan 2021 @ 18:34 (PST)
 * Accept time: Mon 11 Jan 2021 @ 18:58 (PST)
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS__)
#define mt make_tuple
using namespace std;

const ll MX = 110;
ll N, M, E, T;
ll dist[MX];
struct Edge { ll t, w, n; } eg[MX*MX]; ll hd[MX], ecnt=2;
void addEdge()
{
	ll u, v, w; scanf("%lld%lld%lld", &u, &v, &w);
	eg[ecnt] = { u, w, hd[v] }; hd[v] = ecnt++; // FIX: typo-- need to reverse the edges
}

int main()
{
	scanf("%lld%lld%lld%lld", &N, &E, &T, &M);
	for (int i=1; i<=M; ++i) addEdge();

	memset(dist, 0x3f, sizeof dist);
	typedef tuple<int, int> State; // cur, dist
	priority_queue<State, deque<State>, greater<State> > pq;
	pq.push(mt(E, 0));
	while (pq.size()) {
		ll c, d; tie(c, d) = pq.top(); pq.pop();
		if (dist[c] <= d) continue;
		dist[c] = d;
		for (int e=hd[c]; e; e=eg[e].n)
			pq.push(mt(eg[e].t, d+eg[e].w));
	}
	ll ans = 0;
	for (int i=1; i<=N; ++i) {
		db("%d takes %d\n", i, dist[i]);
		if (dist[i] <= T) ++ans;
	}
	printf("%d\n", ans);
}
