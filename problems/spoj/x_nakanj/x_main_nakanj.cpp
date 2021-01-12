/*
 * Problem nakanj (spoj/nakanj)
 * Create time: Mon 11 Jan 2021 @ 17:26 (PST)
 * Accept time: Mon 11 Jan 2021 @ 17:47 (PST)
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
const ll MX = 20;
const ll _x[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
const ll _y[] = { 2, 2, 1, -1, -2, -2, -1, 1 };

ll dist[MX][MX];

void bfs(ll y1, ll x1, ll y2, ll x2)
{
	queue<tuple<int, int, int> > q;
	q.push(mt(y1, x1, 0));
	while (q.size()) {
		ll y, x, d; tie(y, x, d) = q.front(); q.pop();
		// printf("at %d,%d after %d\n", y, x, d);
		if (dist[y][x]) continue;
		dist[y][x] = d;
		if (y == y2 && x == x2) return printf("%d\n", d), void();
		for (int n=0; n<8; ++n)
			if (!dist[y+_y[n]][x+_x[n]])
				q.push(mt(y+_y[n], x+_x[n], d+1));
	}
}

int main()
{
	ll T;
	scanf("%lld", &T);
	memset(dist, -1, sizeof dist);
	while (T--) {
		for (int i=2; i<=9; ++i) for (int j=2; j<=9; ++j)
			                         dist[i][j] = 0;
		char y1, x1, y2, x2;
		scanf("\n%c%c %c%c", &y1, &x1, &y2, &x2);
		y1 -= 'a'-2; y2 -= 'a'-2;
		x1 -= '1'-2; x2 -= '1'-2;
		// db("got %d %d, %d %d\n", y1, x1, y2, x2);
		bfs(y1, x1, y2, x2);
	}
}












































































































































// e
