/*
 * Problem 2_2431 (contests/post2020dec/cses_set_1/2_2431)
 * Create time: Sat 06 Feb 2021 @ 14:45 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define F(i, N) for (int i=1; i<=N; ++i)
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

ll Q;

int main()
{
	scanf("%lld", &Q);
	F(q, Q) {
		ll x; scanf("%lld", &x);
		ll n = 1, shift=9, nines=9;
		while (x > shift) {
			x-=shift;
			shift = 9*n*pow(10, n-1);
			(nines *= 10) += 9;
			++n;
		}
		nines /= 10;
		nines += (x-1)/n+1;
		nines /= pow(10, x%n);
		nines %= 10;
		printf("%lld\n", nines);
	}
}
