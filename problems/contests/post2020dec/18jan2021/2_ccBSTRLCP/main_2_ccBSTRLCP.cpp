/*
 * Problem 2_ccBSTRLCP (contests/post2020dec/18jan2021/2_ccBSTRLCP)
 * Create time: Mon 18 Jan 2021 @ 15:09 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stdout, __VA_ARGS__)
#define F(i, N) for (ll i=1; i<=(N); ++i)
using namespace std;

const ll MX = 64;

ll psum[MX];
ll ans[MX*MX*MX][MX]; // [K][M]

int main()
{
	ll N, n;
	scanf("%lld", &n);
	// ll N = 5;
	// F(n, N) {
		memset(ans, 0, sizeof ans);
		for (ll x=0; x<(1ll<<n); ++x) {
			if (! (x%(ll)1e6)) fprintf(stderr, "%020lld of %020lld\r", x, 1ll<<n);
			memset(psum, 0, sizeof psum);
			for (ll i=1; i<n; ++i) {
				ll k = 0;
				while (k<i && i+k<n && (x>>k&1) == (x>>(k+i)&1)) ++k;
				// db("        k og got %d, now %d vs %d (x is %x)\n", k, ((x>>k)&1), ((x>>(k+i))&1), x);
				// if (((x>>k)&1) == ((x>>(k+i))&1)) ++k;
				// db("    %d got %d\n", i, k);
				++psum[k];
			}
			for (ll i=n; i; --i) psum[i-1] += psum[i];
			for (ll k=1; k<n; ++k) {
				// if (!psum[k]) continue;
				for (ll i=1; i<psum[k]; ++i) {
					++ans[k][i];
					// for (int i=0; i<n; ++i) db("%2d", x>>i&1);
					// db("  contributed to %d, %d, %d\n", n, k, i);
				}
			}
		}
		F(k, n) {
			F(m, n-1) if (ans[k][m]) {
				db("%lld %lld %lld", n, k, m);
					db(" -> %lld", ans[k][m]);
				db("\n");
			}
			// db("\n");
		}
	// } //
}
