/*
 * Problem 17B (cf/17B)
 * Create time: Tue 19 Jan 2021 @ 20:53 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS__)
#define F(i, N) for (int i=1; i<=N; ++i)
using namespace std;

const ll MX = 1e4+10;
ll N, M;
ll lo[MX];

int main()
{
	scanf("%lld", &N);
	F(i, N) scanf("%*d");
	scanf("%lld", &M);
	memset(lo, 0x3f, sizeof lo);
	F(i, M) {
		ll a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
		lo[b] = min(lo[b], c);
	}

	ll num_non = 0;
	ll ans = 0;
	F(i, N) if (lo[i] > 1e9) ++num_non; else ans += lo[i];
	if (num_non != 1) printf("-1\n");
	else printf("%lld\n", ans);
}
