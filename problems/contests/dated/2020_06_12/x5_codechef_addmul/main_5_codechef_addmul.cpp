/*
 * Problem 5_codechef_addmul (contests/dated/2020_06_12/5_codechef_addmul)
 * Create time: Tue 16 Jun 2020 @ 11:37 (PDT)
 * Accept time: [!meta:end!]
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
const ll MX = 100111;
const ll MOD = 1e9 + 7;
ll N, D, M, segt[MX<<2], mult[MX<<2], addt[MX<<2];
void dump()
{
	int d = D+1;
	for (int i=1; i<1<<1+D; ++i)
	{
		if (__builtin_popcount(i) == 1) { printf("\n"); --d; }
		printf("%3lld *%lld +%lld  ", segt[i], mult[i], addt[i]);
		for (int i=1; i<1<<d; ++i) printf("           ");
	}
}
void apply(ll mulv, ll addv, ll k, ll tl, ll tr)
{
	mult[k] = mult[k] * mulv % MOD;
	addt[k] = (addt[k] * mulv + addv) % MOD;
	segt[k] = (segt[k] * mulv + addv * (tr-tl+1)) % MOD;
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
	segt[k] = (segt[k<<1] + segt[k<<1|1]) % MOD;
}

void update(ll ql, ll qr, ll mulv, ll addv, ll k=1, ll tl=1, ll tr=1<<D)
{
	if (tr < ql || qr < tl) return;
	if (ql <= tl && tr <= qr)
	{
		apply(mulv, addv, k, tl, tr);
		return;
	}
	push(k, tl, tr);
	ll mid = tl + (tr-tl>>1);
	update(ql, qr, mulv, addv, k<<1, tl, mid);
	update(ql, qr, mulv, addv, k<<1|1, mid+1, tr);
	collect(k, tl, tr);
}

ll query(ll ql, ll qr, ll k=1, ll tl=1, ll tr=1<<D)
{
	if (qr < tl || tr < ql) return 0;
	if (ql <= tl && tr <= qr) return segt[k];
	push(k, tl, tr);
	ll mid = tl + (tr-tl>>1);
	return (query(ql, qr, k<<1, tl, mid)
		  + query(ql, qr, k<<1|1, mid+1, tr)) % MOD;
}

int main()
{
	scanf("%lld%lld", &N, &M);
	D = log2(N) +1;	// FIX: init D
	for (int i=1; i<=N; ++i)
	{
		ll d; scanf("%lld", &d);
		update(i, i, 0, d);
	}
	for (int i=0; i<M; ++i)
	{
		//dump(); printf("\n$ ");
		ll c, l, r;
		scanf("%lld%lld%lld", &c, &l, &r);
		if (c == 4) printf("%lld\n", query(l, r));
		else
		{
			ll d; scanf("%lld", &d);
			if (c == 1) update(l, r, 1, d);
			if (c == 2) update(l, r, d, 0);
			if (c == 3) update(l, r, 0, d);
		}
	}

	return 0;
}

