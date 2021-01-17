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
const ll _y[] = { 1, 0, -1, 0 };
const ll _x[] = { 0, 1, 0, -1 };
// const ll _y[] = { 1, -1, -1, 1 };
// const ll _x[] = { 0, 1, -1, -1 };
ll N, M, Y, X;
char grid[MX][MX];              // 0..9 means the kth dirty spot, others are as in input
ll adj[MX][MX];
ll dist[MX][MX];
ll dy[MXX], dx[MXX];

ll dp[1<<MXX][MX];

void bfs(ll n, ll y, ll x)
{
	memset(dist, 0x3f, sizeof dist);
	typedef tuple<ll, ll> St;
	queue<St> q; dist[y][x] = 0; // FIX: need to set dist here bc we are using the next_loop dist update
	for (q.push(mt(y, x)); q.size(); q.pop()) {
		ll y, x; tie(y, x) = q.front();
		// db("at %d, %d after %d\n", y, x, dist[y][x]);
		// for (int i=0; i<=N+1; ++i) { for (int j=0; j<=M+1; ++j) db("%2c", (i==y&&j==x?'@':(grid[i][j]<10?grid[i][j]+'0' : grid[i][j]))); db("\n"); }
		if (~n && grid[y][x] < 10) adj[n][grid[y][x]] = dist[y][x];
		for (int n=0; n<4; ++n) {
			if (grid[y+_y[n]][x+_x[n]] != 'x' && dist[y+_y[n]][x+_x[n]] > 1e9)
				dist[y+_y[n]][x+_x[n]] = dist[y][x]+1,
				q.push(mt(y+_y[n], x+_x[n]));
		}
	}
}

int main()
{
	while (~scanf("%lld%lld", &M, &N)) {
		if (!N && !M) return 0;
		memset(grid, 'x', sizeof grid);
		memset(dist, 0x3f, sizeof dist);
		memset(adj, 0x3f, sizeof adj); // FIX: clears
		memset(dy, 0, sizeof dy);
		memset(dx, 0, sizeof dx);
		for (int i=1; i<=N; ++i) scanf("%s", grid[i]+1);
		for (int i=1; i<=N; ++i) grid[i][M+1] = 'x';

		int cnt=0; for (int i=1; i<=N; ++i) for (int j=1; j<=M; ++j) {
			if (grid[i][j] == '*') dy[cnt] = i, dx[cnt] = j, grid[i][j] = cnt++;
			else if (grid[i][j] == 'o') grid[i][j] = '.', Y=i, X=j;
		}

		// for (int i=0; i<=N+1; ++i) { for (int j=0; j<=M+1; ++j) db("%2c", (grid[i][j]<10?grid[i][j]+'0' : grid[i][j])); db("\n"); }

		for (int i=0; i<cnt; ++i) {
			bfs(i, dy[i], dx[i]);
			// for (int i=1; i<=N; ++i) { for (int j=1; j<=M; ++j) db("%3d", dist[i][j]>1e9?-1:dist[i][j]); db("\n"); }
		}
		// for (int i=0; i<cnt; ++i) for (int j=0; j<cnt; ++j) db("%d to %d = %d\n", i, j, adj[i][j]);
		bfs(-1, Y, X);
		// for (int i=1; i<=N; ++i) { for (int j=1; j<=M; ++j) db("%3d", dist[i][j]); db("\n"); }

		memset(dp, 0x3f, sizeof dp);
		for (int c=0; c<cnt; ++c) dp[0][c] = dist[dy[c]][dx[c]];
		for (int m=1; m<1<<cnt; ++m)
			for (int c=0; c<cnt; ++c) if (m>>c&1)
				for (int k=0; k<cnt; ++k) if (m>>k&1)
					dp[m][c] = min(dp[m][c], dp[m&~(1<<c)][k] + adj[k][c]);
		ll ans = 1e9; for (int i=0; i<cnt; ++i) ans = min(ans, dp[(1<<cnt)-1][i]);
		printf("%lld\n", ans == 1e9 ? -1 : ans);


		// typedef tuple<ll, ll, ll, ll> St; // < dist, y, x, mask >
		// queue<St> q; q.push(mt(0, Y, X, 0));
		// ll ans = -1;
		// while (q.size()) {
		// 	ll d, y, x, m; tie(d, y, x, m) = q.front(); q.pop();
		// 	// db("at %d, %d after %d with %x\n", y, x, d, m);
		// 	// for (int i=0; i<=N+1; ++i) { for (int j=0; j<=M+1; ++j) db("%2c", (i==y&&j==x?'@':(grid[i][j]<10?grid[i][j]+'0' : grid[i][j]))); db("\n"); }
		// 	// if (grid[y][x] < 10) m |= (1<<grid[y][x]);
		// 	// else if (grid[y][x] != '.') continue;
		// 	if (dist[y][x][m] <= d) continue;
		// 	dist[y][x][m] = d;
		// 	if (m+1 == 1<<cnt) { ans = d; break; }
		// 	for (int n=0; n<4; ++n) {
		// 		y+=_y[n], x+=_x[n];
		// 		ll _m = m;
		// 		if (grid[y][x] < 10) _m |= 1<<grid[y][x];
		// 		else if (grid[y][x] != '.') continue;;
		// 		// db("%lld %lld\n", y, x);
		// 		q.push(mt(d+1, y, x, _m));
		// 	}
		// 	// NOTE! y, x is different here
		// }
		// printf("%lld\n", ans);
	}
}
