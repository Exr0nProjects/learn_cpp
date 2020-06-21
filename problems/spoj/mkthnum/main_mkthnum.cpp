/*
 * Problem mkthnum (spoj/mkthnum)
 * Create time: Sun 21 Jun 2020 @ 09:25 (PDT)
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
ll N, D, M;
ll alc=1, segt[MX<<6], sett[MX<<6], lc[MX<<6], rc[MX<<6], rt[MX];

void dupe(ll &k)
{
	segt[alc] = segt[k];
	sett[alc] = sett[k];	// FIX: postchange--dupe sett[k] as well
	lc[alc] = lc[k];
	rc[alc] = rc[k];
	k = alc++;
}
void apply(ll setv, ll &k, ll tl, ll tr)
{
	if (setv < 0) return;
	dupe(k);
	sett[k] = setv;
	segt[k] = setv * (tr-tl+1);
}
void push(ll &k, ll tl, ll tr)
{
	dupe(k);
	ll mid = tl + (tr-tl>>1);
	apply(sett[k], lc[k], tl, mid);
	apply(sett[k], rc[k], mid+1, tr);
	sett[k] = -1;
}
void comb(ll k)
{
	segt[k] = segt[lc[k]] + segt[rc[k]];
}

void update(ll q, ll setv, ll &k, ll tl=1, ll tr=1<<D)
{
	if (q < tl || q > tr) return;
	if (tl == tr) return apply(setv, k, tl, tr);
	push(k, tl, tr); ll mid = tl + (tr-tl>>1);
	if (q <= mid) update(q, setv, lc[k], tl, mid);
	else update(q, setv, rc[k], mid+1, tr);
	comb(k);	// FIX: don't forget push(k) and comb(k) in update, even if it's point update
}
ll query(ll ql, ll qr, ll k, ll tl=1, ll tr=1<<D)
{
	if (qr < tl || tr < ql) return 0;
	if (ql <= tl && tr <= qr) return segt[k];
	push(k, tl, tr); ll mid = tl + (tr-tl>>1);
	return query(ql, qr, lc[k], tl, mid)
		 + query(ql, qr, rc[k], mid+1, tr);
}

ll querykth(ll k1, ll k2, ll kth, ll tl=1, ll tr=1<<D)
{
	//printf("query %dth at %d, %d (%d..%d)\n", kth, k1, k2, tl, tr);
	if (tl == tr) return tl;
	push(k1, tl, tr); push(k2, tl, tr); // FIX: push on query
	ll mid = tl + (tr-tl>>1);
	ll lsize = segt[lc[k2]] - segt[lc[k1]];	// FIX: equ--size of k2 - sizeof k1, not just one of them
	//printf("%d - %d = %d\n", segt[lc[k2]], segt[lc[k1]], lsize);
	if (kth <= lsize) return querykth(lc[k1], lc[k2], kth, tl, mid);
	else return querykth(rc[k1], rc[k2], kth-lsize, mid+1, tr);
}

int main()
{
	scanf("%lld%lld", &N, &M);
	D = log2(N) +1;
	rt[0] = alc++;
	for (ll i=1; i<1<<D; ++i)
	{
		lc[i] = alc++;
		rc[i] = alc++;
		sett[i] = -1;	// FIX: clears--init set tags
	}
	for (ll i=1; i<=N; ++i)
	{
		ll d; scanf("%lld", &d);
		rt[i] = rt[i-1];
		update(d, 1, rt[i]);	// FIX: equ--update(d, 1, ...) not update(i, d, ...)
	}

	for (ll i=0; i<M; ++i)
	{
		ll l, r, k; scanf("%lld%lld%lld", &l, &r, &k);
		printf("%lld\n", querykth(rt[l-1], rt[r], k));
	}

	return 0;
}

