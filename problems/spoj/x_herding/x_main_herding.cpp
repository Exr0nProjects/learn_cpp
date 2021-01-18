/*
 * Problem herding (spoj/herding)
 * Create time: Sun 17 Jan 2021 @ 17:49 (PST)
 * Accept time: Sun 17 Jan 2021 @ 19:06 (PST)
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 1e3+10;
ll N, M;
char grid[MX][MX];
ll vs[MX][MX], acnt=1;

ll rec(ll y, ll x, ll a=acnt)
{
	if (vs[y][x]) {
		if (vs[y][x] == a) ++acnt;
		return vs[y][x];        // FIX: typo--return vis[y][x] not grid[y][x].. grid[y][x] is the input grid smah
	}
	vs[y][x] = a;

	ll _y = y, _x = x;
	if (grid[y][x] == 'N') --_y;
	if (grid[y][x] == 'S') ++_y;
	if (grid[y][x] == 'E') ++_x;
	if (grid[y][x] == 'W') --_x;

	vs[y][x] = rec(_y, _x);
	return vs[y][x];
}

int main()
{
	scanf("%lld%lld", &N, &M);
	for (int i=1; i<=N; ++i) scanf("%s", grid[i]+1);
	for (int i=1; i<=N; ++i) for (int j=1; j<=M; ++j) rec(i, j);
	printf("%lld\n", acnt-1);
}
