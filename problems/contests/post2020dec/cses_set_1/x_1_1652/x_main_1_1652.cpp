/*
 * Problem 1_1652 (contests/post2020dec/cses_set_1/1_1652)
 * Create time: Sat 06 Feb 2021 @ 14:28 (PST)
 * Accept time: Sat 06 Feb 2021 @ 14:37 (PST)
 *
 */

#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define F(i, N) for (int i=1; i<=N; ++i)
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
const ll MX = 1e3+10;

ll N, M;
char grid[MX][MX];
ll dp[MX][MX];

int main()
{
	scanf("%lld%lld", &N, &M);
	F(i, N) scanf("%s", grid[i]+1);
	F(i, N) F(j, N) dp[i][j] = grid[i][j] == '*';
	F(i, N) F(j, N) dp[i][j] += dp[i-1][j];
	F(i, N) F(j, N) dp[i][j] += dp[i][j-1];

	F(i, M) {
		ll x1, x2, y1, y2, a, b, c, d;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		y1 = min(a, c); y2 = max(a, c);
		x1 = min(b, d); x2 = max(b, d);
		--y1; --x1;
		printf("%lld\n", dp[y2][x2] + dp[y1][x1] - dp[y1][x2] - dp[y2][x1]);
	}
}
