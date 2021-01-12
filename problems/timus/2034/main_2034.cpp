/*
 * Problem 2034 (timus/2034)
 * Create time: Mon 11 Jan 2021 @ 19:08 (PST)
 * Accept time: [!meta:end!]
 * caravans (enumerate shortest paths and find farthest closest point)
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS__)
#define mt make_tuple
using namespace std;

const ll MX = 1e5+10;
ll N, M, S, D, R;
struct Edge { ll t, n; } eg[MX]; ll hd[MX], ecnt=2;
void addEdge(ll u=0, ll v=0)
{
	if (!u) scanf("%lld%lld", &u, &v), addEdge(v, u);
	eg[ecnt] = { v, hd[u] }; hd[u] = ecnt++;
}
ll dist[MX], ans=0;
ll dijkstra(ll src, ll dst)
{
	memset(dist, 0x3f, sizeof dist);
	typedef tuple<ll, ll> St;   // <cur, dist>
	priority_queue<St, deque<St>, greater<St> > pq;
	pq.push(mt(src, 0));
	while (pq.size()) {
		ll c, d; tie(c, d) = pq.top(); pq.pop();
		if (dist[c] <= d) continue;
		if (c == dst) return d;
		dist[c] = d;
		for (int e=hd[c]; e; e=eg[e].n)
			pq.push(mt(eg[e].t, d+1));
	}
	return -1;
}

bool vis[MX];
void dfs(ll c, ll r, ll mn=1e9)
{
	if (vis[c]) return;
	if (c == D) ans = max(ans, mn);
	if (r == 0) return;
	vis[c] = 1;
	mn = min(mn, dist[c]);
	for (int e=hd[c]; e; e=eg[e].n)
		dfs(eg[e].t, r-1, mn);
	vis[c] = 0;
}

int main()
{
	scanf("%lld%lld", &N, &M);
	for (int i=1; i<=M; ++i) addEdge();
	scanf("%lld%lld%lld", &S, &D, &R);
	ll len = dijkstra(S, D);
	dijkstra(R, -1);            // populate dist array with distance from robbers
	dfs(S, len);
	printf("%lld\n", ans);
}
