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

	queue<ll> q; q.push(S);
	ds[S] = 1;                  // FIX: init--bfs headvisiting (marking as vis before pushing to queue) requires setting start dist != unvisited_value
	while (q.size()) {
		ll c = q.front(); q.pop();
		if (c == T) return printf("%lld\n", ds[c]-1), 0;
		if (c+A <= N && !ds[c+A]) ds[c+A] = ds[c]+1, q.push(c+A);
		if (c-B >  0 && !ds[c-B]) ds[c-B] = ds[c]+1, q.push(c-B);
	}
	printf("use the stairs\n");
}
