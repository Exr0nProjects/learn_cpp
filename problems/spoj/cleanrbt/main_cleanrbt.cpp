/*
 * Problem cleanrbt (spoj/cleanrbt)
 * Create time: Sun 17 Jan 2021 @ 09:08 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS__)
#define mt make_tuple
using namespace std;

const ll MX = 210;
const ll MXX = 10;
// const ll _y[] = { 1, 0, -1, 0 };
// const ll _x[] = { 0, 1, 0, -1 };
const ll _y[] = { 1, -1, -1, 1 };
const ll _x[] = { 0, 1, -1, -1 };
ll N, M, Y, X;
char grid[MX][MX];              // 0..9 means the kth dirty spot, others are as in input
ll dist[MX][MX][1<<MXX];

int main()
{
	while (~scanf("%lld%lld", &M, &N)) {
		if (!N && !M) return 0;
		memset(grid, 'x', sizeof grid);
		// for (int i=0; i<=N+1; ++i) { for (int j=0; j<=M+1; ++j) db("%2c", (grid[i][j]<10?grid[i][j]+'0' : grid[i][j])); db("\n"); }
		memset(dist, 0x3f, sizeof dist);
		for (int i=1; i<=N; ++i) scanf("%s", grid[i]+1);
		for (int i=1; i<=N; ++i) grid[i][M+1] = 'x';

		int cnt=0; for (int i=1; i<=N; ++i) for (int j=1; j<=M; ++j) {
			if (grid[i][j] == '*') grid[i][j] = cnt++;
			else if (grid[i][j] == 'o') grid[i][j] = '.', Y=i, X=j;
		}
		typedef tuple<ll, ll, ll, ll> St; // < dist, y, x, mask >
		queue<St> q; q.push(mt(0, Y, X, 0));
		ll ans = -1;
		while (q.size()) {
			ll d, y, x, m; tie(d, y, x, m) = q.front(); q.pop();
			// db("at %d, %d after %d with %x\n", y, x, d, m);
			// for (int i=0; i<=N+1; ++i) { for (int j=0; j<=M+1; ++j) db("%2c", (i==y&&j==x?'@':(grid[i][j]<10?grid[i][j]+'0' : grid[i][j]))); db("\n"); }
			if (grid[y][x] < 10) m |= (1<<grid[y][x]);
			else if (grid[y][x] != '.') continue;
			if (dist[y][x][m] <= d) continue;
			dist[y][x][m] = d;
			if (m+1 == 1<<cnt) { ans = d; break; }
			for (int n=0; n<4; ++n) {
				y+=_y[n], x+=_x[n];
				// db("%lld %lld\n", y, x);
				q.push(mt(d+1, y, x, m));
			}
			// NOTE! y, x is different here
		}
		printf("%lld\n", ans);
	}
}
