/*
 * Problem elevtrbl (spoj/elevtrbl)
 * Create time: Sun 17 Jan 2021 @ 16:57 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 1e6+10;
ll N, S, T, A, B;
ll ds[MX];

int main()
{
	scanf("%lld%lld%lld%lld%lld", &N, &S, &T, &A, &B);

	typedef tuple<ll, ll> St;
	queue<St> q; q.push(mt(1, S)); ds[S] = 1;
	while (q.size()) {
		ll c, d; tie(d, c) = q.front(); q.pop();
		// ll c = q.front(); q.pop();
		// if (ds[c]) continue; ds[c] = d;
		if (c == T) return printf("%lld\n", ds[c]-1), 0;
		// if (c+A <= N) ds[c+A] = ds[c]+1, q.push(c+A);
		// if (c-B >= 1) ds[c-B] = ds[c]+1, q.push(c-B);
		if (c+A <= N && !ds[c+A]) ds[c+A] = ds[c]+1, q.push(mt(d+1, c+A));
		if (c-B >= 1 && !ds[c-B]) ds[c-B] = ds[c]+1, q.push(mt(d+1, c-B));
	}
	printf("use the stairs\n");
}
