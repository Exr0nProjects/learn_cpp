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
		ll _x; scanf("%lld", &_x);
		__int128 x = _x;
		__int128 n = 1, shift=9, nines=9;
		while (x > shift) {
			// db("    x = %lld shift = %lld n = %lld\n", x, shift, n);
			x-=shift;
			shift = 9*(n+1)*pow((double)10, n);
			// db("    -> shift = %lld\n", shift);
			(nines *= 10) += 9;
			++n;
		}
		nines /= 10;
		nines += (x-1)/n+1;
		// db("n=%lld  nines %lld      x %lld\n", n, nines, x);
		nines /= pow((double)10, n-(x%n ? x%n : n));
		nines %= 10;
		printf("%lld\n", (ll)nines);
	}
}
