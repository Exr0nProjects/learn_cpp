/*
 * Problem 4_hdu4578 (contests/dated/2020_06_12/4_hdu4578)
 * Create time: Tue 16 Jun 2020 @ 12:21 (PDT)
 * Accept time: Wed 17 Jun 2020 @ 09:00 (PDT)
 *
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
#include <utility>
#include <iterator>
#include <exception>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 100111;
const ll MOD = 10007;
ll N, D, M, segt[MX<<2][3], mult[MX<<2], addt[MX<<2];

void dump()
{
	int d = D+1;
	for (int k=1; k<1<<1+D; ++k)
	{
		if (__builtin_popcount(k) == 1) { --d; printf("\n"); }
		printf("%3lld *%lld +%lld  ", segt[k][0], mult[k], addt[k]);
		for (int i=1; i<1<<d; ++i) printf("           ");
	}
}
void apply(ll mulv, ll addv, ll k, ll tl, ll tr)
{
	mult[k] = mult[k] * mulv % MOD;
	addt[k] = (addt[k] * mulv + addv) % MOD;
	for (ll i=0, c=mulv; i<3; ++i, c*=mulv)
		segt[k][i] *= c;
	const ll len = tr-tl+1;
	segt[k][2] += 3*addv*segt[k][1] + 3*addv*addv*segt[k][0] + addv*addv*addv*len;
	segt[k][1] += 2*addv*segt[k][0] + addv*addv*len;
	segt[k][0] += addv*len;
	for (ll i=0; i<3; ++i) segt[k][i] %= MOD;
}
void push(ll k, ll tl, ll tr)
{
	if (mult[k] == 1 && !addt[k]) return;
	ll mid = tl + (tr-tl>>1);
	apply(mult[k], addt[k], k<<1, tl, mid);
	apply(mult[k], addt[k], k<<1|1, mid+1, tr);
	mult[k] = 1; addt[k] = 0;
}
void collect(ll k, ll tl, ll tr)
{
	for (int i=0; i<3; ++i)
		segt[k][i] = segt[k<<1][i] + segt[k<<1|1][i];
}

ll query(ll ql, ll qr, ll p, ll k=1, ll tl=1, ll tr=1<<D)
{
	if (qr<tl || tr<ql) return 0;
	if (ql <= tl && tr <= qr) return segt[k][p];
	push(k, tl, tr);
	ll mid = tl + (tr-tl>>1);
	return (query(ql, qr, p, k<<1, tl, mid)
		  + query(ql, qr, p, k<<1|1, mid+1, tr)) % MOD;
}
void update(ll ql, ll qr, ll mulv, ll addv, ll k=1, ll tl=1, ll tr=1<<D)
{
	if (qr < tl || tr < ql) return;
	if (ql <= tl && tr <= qr) { apply(mulv, addv, k, tl, tr); return; }
	push(k, tl, tr);
	ll mid = tl + (tr-tl>>1);
	update(ql, qr, mulv, addv, k<<1, tl, mid);
	update(ql, qr, mulv, addv, k<<1|1, mid+1, tr);
	collect(k, tl, tr);
}

int main()
{
	while (scanf("%d%d", &N, &M), N)
	{
		memset(segt, 0, sizeof segt);
		memset(mult, 0, sizeof mult);
		memset(addt, 0, sizeof addt);

		for (int k=1; k<1<<D; ++k) mult[k] = 1;
		D = log2(N)+1;	// FIX: init--forgot to init mult array and D

		for (int i=0; i<M; ++i)
		{
			//dump(); printf("\n\n$ ");
			int c, l, r, v;
			scanf("%d%d%d%d", &c, &l, &r, &v);
			if (c == 1) update(l, r, 1, v);
			if (c == 2) update(l, r, v, 0);
			if (c == 3) update(l, r, 0, v);
			if (c == 4) printf("%lld\n", query(l, r, v-1) % MOD);
		}
	}

	return 0;
}

