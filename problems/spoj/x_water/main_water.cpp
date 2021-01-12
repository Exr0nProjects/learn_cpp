/*
 * Problem water (spoj/water)
 * Create time: Mon 11 Jan 2021 @ 18:18 (PST)
 * Accept time: [!meta:end!]
 * water flow and puddles staggered bfs
 */
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 110;
const ll _x[] = { 0, 1, 0, -1 };
const ll _y[] = { 1, 0, -1, 0 };

ll T, N, M, grid[MX][MX], dist[MX][MX];

queue<tuple<int, int, int> > q; // < y, x, maxdep >

int main() {
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld%lld", &N, &M);
		memset(grid, 0, sizeof grid);
		memset(dist, 0, sizeof dist);
		for (int i=1; i<=N; ++i) for (int j=1; j<=M; ++j)
			scanf("%lld", &grid[i][j]), dist[i][j] = 1e9;

		for (int i=1; i<=max(N, M); ++i)
			q.push(mt(i, 1, 0)),
			q.push(mt(1, i, 0)),
			q.push(mt(i, M, 0)),
			q.push(mt(N, i, 0));

		while (q.size()) {
			ll y, x, d; tie(y, x, d) = q.front(); q.pop();
			// db("at %d,%d after %d\n", y, x, d);
			if (dist[y][x] <= d) continue;
			d = max(d, grid[y][x]);
			dist[y][x] = d;
			for (int n=0; n<4; ++n)
				q.push(mt(y+_y[n], x+_x[n], d));
		}
		ll ans = 0;
		for (int i=1; i<=N; ++i) for (int j=1; j<=M; ++j)
			                         ans += dist[i][j] - grid[i][j];
		printf("%lld\n", ans);
	}
}
