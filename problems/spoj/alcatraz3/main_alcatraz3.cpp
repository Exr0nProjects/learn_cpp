/*
 * Problem alcatraz3 (spoj/alcatraz3)
 * Create time: Sat 16 Jan 2021 @ 13:52 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 110;
const ll _y[] = { 1, 0, -1, 0 };
const ll _x[] = { 0, 1, 0, -1 };
ll N, M, D, Y, X;
ll grid[MX][MX], vis[MX][MX];

bool dfs(ll y, ll x, ll d=1)
{
	if (D == 0) return 1;
	if (y == Y && x == X && vis[y][x]) return d > D; // maybe ll d=0 and d >= D?
	if (vis[y][x] || grid[y][x]) return 0;
	// for (int i=0; i<=N+1; ++i) { for (int j=0; j<=M+1; ++j) printf("%2c", grid[i][j] ? '#' : (vis[i][j] ? 'X' : (i==y&&j==x? '@' : ' '))); printf("\n"); } printf("\n");
	vis[y][x] = d;
	for (int n=0; n<4; ++n)
		if (dfs(y+_y[n], x+_x[n], d+1)) return 1;
	vis[y][x] = 0;
	return 0;
}

int main()
{
	scanf("%lld%lld%lld%lld%lld", &N, &M, &D, &Y, &X);
	memset(grid, -1, sizeof grid);
	for (int i=1; i<=N; ++i) {
		getchar();
		for (int j=1; j<=M; ++j) {
			getchar(); // newline or space
			if (getchar() == '.') grid[i][j] = 0;
		}
	}
	// for (int i=1; i<=N; ++i) { for (int j=1; j<=M; ++j) printf("%3c", grid[i][j] ? '#' : '.'); printf("\n"); }
	if (dfs(Y, X)) printf("YES\n"); else printf("NO\n");
}
