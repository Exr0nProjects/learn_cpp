/*
 * Problem P3919 (luogu/P3919)
 * Create time: Mon 22 Jun 2020 @ 11:22 (PDT)
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
ll N, D, Q, tsum[MX<<6], sett[MX<<6];
ll alc=1, lc[MX<<6], rc[MX<<6], rt[MX];

void dump(ll k)
{
	ll d = D+1;
	queue<ll> bfs; bfs.push(k);
	for (ll i=1; i<1<<1+D; ++i)
	{
		k = bfs.front(); bfs.pop();
		bfs.push(lc[k]); bfs.push(rc[k]);
		if (__builtin_popcount(i) == 1) { printf("\n"); --d; }
		printf("%3d: %-2d+%-2d  ", k, tsum[k], sett[k]);
		for (ll i=1; i<1<<d; ++i) printf("            ");
	}
}
void dupe(ll &k)
{
	tsum[alc] = tsum[k];
	sett[alc] = sett[k];
	lc[alc] = lc[k];
	rc[alc] = rc[k];
	k = alc++;
}
void apply(ll setv, ll &k, ll tl, ll tr)
{
	if (setv < 0) return;
	dupe(k);
	sett[k] = setv;
	tsum[k] = setv * (tr-tl+1);
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
	tsum[k] = tsum[lc[k]] + tsum[rc[k]];
}

void update(ll q, ll setv, ll &k, ll tl=1, ll tr=1<<D)
{
	if (q < tl || q > tr) return;
	if (tl == tr) return apply(setv, k, tl, tr);
	push(k, tl, tr); ll mid = tl + (tr-tl>>1);
	if (q <= mid) update(q, setv, lc[k], tl, mid);
	else update(q, setv, rc[k], mid+1, tr);
}
ll query(ll q, ll &k, ll tl=1, ll tr=1<<D)
{
	if (q < tl || q > tr) return 0;
	if (tl == tr) return tsum[k];
	push(k, tl, tr); ll mid = tl + (tr-tl>>1);
	if (q <= mid) return query(q, lc[k], tl, mid);
	else return query(q, rc[k], mid+1, tr);
}

int main()
{
	scanf("%lld%lld", &N, &Q);
	D = log2(N)+1;
	rt[0] = alc++;
	for (ll i=1; i<=N; ++i)
	{
		lc[i] = alc++;
		rc[i] = alc++;
	}

	for (ll i=1; i<=N; ++i)
	{
		ll d; scanf("%lld", &d);
		update(i, d, rt[0]);
	}

	for (ll q=1; q<=Q; ++q)
	{
		//dump(rt[q-1]); printf("\n$ ");
		ll t, c, p; scanf("%lld%lld%lld", &t, &c, &p);
		rt[q] = rt[t];
		if (c == 2) printf("%lld\n", query(p, rt[q]));
		if (c == 1)
		{
			ll d; scanf("%lld", &d);
			update(p, d, rt[q]);
		}
	}

	return 0;
}

