/*
 * Problem 3_poj2777 (contests/dated/2020_06_12/3_poj2777)
 * Create time: Mon 15 Jun 2020 @ 11:29 (PDT)
 * Accept time: [!meta:end!]
 * FIX: needed to check if l was larger than r, becaues I didn't read the "and A may be larger than B" in the problem statement
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <numeric>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 300111;
ll N, numcolors, D, segt[MX<<1], sett[MX<<1];	// FIX: bounds--segtee needs 2*MX

inline ll popcount(ll n)
{
	ll tot = 0;
	for (ll i=0; i<numcolors; ++i)
		if (n & 1<<i) ++tot;
	return tot;
}
void push_down(ll k, ll tl, ll tr)
{
	if (!sett[k]) return;
	segt[k<<1] = segt[k<<1|1] =
	sett[k<<1] = sett[k<<1|1] = sett[k];
	sett[k] = 0;
}
void consolidate(ll k, ll tl, ll tr)
{
	segt[k] = segt[k<<1] | segt[k<<1|1];
}

ll query(ll ql, ll qr, ll k=1, ll tl=1, ll tr=1<<D)
{
	if (qr < tl || tr < ql) return 0;
	if (ql <= tl && tr <= qr) return segt[k];
	push_down(k, tl, tr);
	ll mid = tl + (tr-tl>>1);
	return query(ql, qr, k<<1, tl, mid) | query(ql, qr, k<<1|1, mid+1, tr);
}
void update(ll ql, ll qr, ll v, ll k=1, ll tl=1, ll tr=1<<D)
{
	//printf("update %lld..%lld with %lld @ %lld (%lld..%lld %f)\n", ql, qr, v, k, tl, tr, log2(tr-tl));
	if (qr < tl || tr < ql) return;
	if (ql <= tl && tr <= qr)
	{
		sett[k] = segt[k] = v;
		return;
	}
	push_down(k, tl, tr);
	ll mid = tl + (tr-tl>>1);
	update(ql, qr, v, k<<1, tl, mid);
	update(ql, qr, v, k<<1|1, mid+1, tr);
	consolidate(k, tl, tr);
}

void dump()
{
	return;
	ll pad = D;
	for (ll i=1; i<1<<1+D; ++i)
	{
		if (popcount(i) == 1) { printf("\n"); --pad; }
		printf("%3d%3d, ", segt[i], sett[i]);
		for (ll i=1; i<1<<D; ++i) printf("        ");
	}
	printf("\n");
}

int main()
{
	ll O;
	scanf("%lld%lld%lld", &N, &numcolors, &O);
	for (D=1; 1<<D<=N; ++D);	// FIX: init segtree
	update(1, N, 1);	// FIX: init the values too
	//printf("D = %lld vs %lld\n", D, (int)log2(N)+1);

	for (ll i=0; i<O; ++i)
	{
		char c; scanf("\n%c", &c);
		//printf("got %c\n", c);
		ll l, r; scanf("%lld%lld", &l, &r);
		if (r < l) swap(l, r);	// FIX: boundary checking, needed?
		if (c == 'C')
		{
			ll d; scanf("%lld", &d);
			update(l, r, 1<<d-1);
		}
		else if (c == 'P')
			printf("%lld\n", popcount(query(l, r)));
		else --i;
		dump();
	}

	return 0;
}

