/*
 * Problem chmaze (spoj/chmaze)
 * Create time: Sun 17 Jan 2021 @ 10:37 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stdout, __VA_ARGS__)
#define F(i, N) for (int i=1; i<=(N); ++i)
#define mt make_tuple
using namespace std;
const ll MX = 32;
const ll MXC = 16;
const ll _x[] = { 0, 1, 0, -1, 0 };
const ll _y[] = { 1, 0, -1, 0, 0 };
ll N, M, K;
char grid[MXC][MX][MX];
ll dist[MXC][MX][MX];

int main()
{
	while (~scanf("%lld%lld%lld", &N, &M, &K)) {
		if (!N && !M && !K) return 0;
		memset(grid, '1', sizeof grid);
		memset(dist, 0, sizeof dist);
		F(k, K) F(i, N) scanf("%s", grid[k-1][i]+1);
		F(k, K) F(i, N) grid[k-1][i][M+1] = '1';
		// F(k, K) { F(i, N) { F(j, M) db("%2c", grid[k][i][j]); db("\n"); } db("\n"); }
		typedef tuple<ll, ll, ll> St; // < dist, y, x >
		queue<St> q; q.push(mt(0, 1, 1));
		ll ans = -1;
		while (q.size()) {
			ll d, y, x; tie(d, y, x) = q.front(); q.pop();
			// db("at %d, %d after %d\n", y, x, d);
			if (y == N && x == M) { ans = d; break; }
			if (dist[d%K][y][x] || grid[d%K][y][x] == '1') continue;
			dist[d%K][y][x] = d;
			for (int n=0; n<5; ++n)
				if (grid[d%K][y+_y[n]][x+_x[n]] == '0')
					q.push(mt(d+1, y+_y[n], x+_x[n]));
		}
		printf("%lld\n", ans);
	}
}
