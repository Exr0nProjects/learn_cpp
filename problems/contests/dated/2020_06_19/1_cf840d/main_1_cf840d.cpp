/*
 * Problem 1_cf840d (contests/dated/2020_06_19/1_cf840d)
 * Create time: Sun 21 Jun 2020 @ 11:33 (PDT)
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
const ll MX = 300111;
ll N, D, Q, tsum[MX<<5], addt[MX<<5];
int alc=1, lc[MX<<5], rc[MX<<5], rt[MX];

void dump(ll k)
{
	ll d = D+1;
	queue<ll> bfs; bfs.push(k);
	for (ll i=1; i<1<<1+D; ++i)
	{
		if (__builtin_popcount(i) == 1) { --d; printf("\n"); }
		k = bfs.front(); bfs.pop();
		bfs.push(lc[k]); bfs.push(rc[k]);
		printf("%3d+%-d @%-2d(%-2d %2d)", tsum[k], addt[k], k, lc[k], rc[k]);	// FIX: typo--print k not i
		for (ll i=1; i<1<<d; ++i) printf("                ");
	}
	printf("\n");
}

inline void dupe(int &k)
{
	tsum[alc] = tsum[k];
	addt[alc] = addt[k];
	lc[alc] = lc[k];
	rc[alc] = rc[k];
	k = alc++;
}
inline void apply(ll addv, int &k, int tl, int tr)
{
	dupe(k);
	addt[k] = addv;
	tsum[k] += addv*(tr-tl+1);
}
inline void push(int &k, int tl, int tr)
{
	dupe(k);
	if (!addt[k]) return;
	ll mid = tl + (tr-tl>>1);
	apply(addt[k], lc[k], tl, mid);
	apply(addt[k], rc[k], mid+1, tr);
	addt[k] = 0;
}

void update(int q, ll addv, int &k, int tl=1, int tr=1<<D)
{
	if (q < tl || q > tr) return;
	if (tl == tr) return apply(addv, k, tl, tr);
	push(k, tl, tr); ll mid = tl + (tr-tl>>1);
	if (q <= mid) update(q, addv, lc[k], tl, mid);
	else update(q, addv, rc[k], mid+1, tr);
	tsum[k] = tsum[lc[k]] + tsum[rc[k]];
}
ll querykdup(int k1, int k2, ll kdup, int tl=1, int tr=1<<D)
{
	//printf("query dup %d: @%d, %d (%d..%d)\n", kdup, k1, k2, tl, tr);
	if (tl == tr) return tsum[k2]-tsum[k1] > kdup ? tl : -1;
	push(k1, tl, tr); push(k2, tl, tr);
	ll mid = tl + (tr-tl>>1);
	unsigned ll ret = -1; // unsigned so the min overwrites this
	//printf("lef %3d   rig %3d     vs kdup = %d\n", tsum[lc[k2]]-tsum[lc[k1]], tsum[rc[k2]]-tsum[rc[k1]], kdup);
	if (tsum[lc[k2]]-tsum[lc[k1]] > kdup)
		ret = min(ret, (unsigned ll)querykdup(lc[k1], lc[k2], kdup, tl, mid));
	if (tsum[rc[k2]]-tsum[rc[k1]] > kdup)
		ret = min(ret, (unsigned ll)querykdup(rc[k1], rc[k2], kdup, mid+1, tr));
	return ret;
}

int main()
{
	scanf("%lld%lld", &N, &Q);
	D = log2(N)+1;
	rt[0] = alc++;
	for (ll i=1; i<1<<D; ++i)
	{
		lc[i] = alc++;
		rc[i] = alc++;
	}

	for (ll i=1; i<=N; ++i)
	{
		ll d; scanf("%lld", &d);
		rt[i] = rt[i-1];
		update(d, 1, rt[i]);
	}

	//for (ll i=1; i<=N; ++i) { printf("\ntree at %d:", i); dump(rt[i]); }

	for (ll i=0; i<Q; ++i)
	{
		ll l, r, k;
		scanf("%lld%lld%lld", &l, &r, &k);
		printf("%lld\n", querykdup(rt[l-1], rt[r], (r-l+1)/k)); // FIX: r-l+1 not l-r+1 smah
	}

	return 0;
}

