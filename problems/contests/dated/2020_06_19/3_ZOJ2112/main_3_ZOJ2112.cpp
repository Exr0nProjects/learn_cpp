/*
 * Problem 3_ZOJ2112 (contests/dated/2020_06_19/3_ZOJ2112)
 * Create time: Sat 20 Jun 2020 @ 09:22 (PDT)
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
const ll MX = 50111;
ll N, D, Q;
ll alloc=1, segt[MX<<6], sett[MX<<6], lc[MX<<6], rc[MX<<6], rt[MX];
void dupe(ll &k)
{
	segt[alloc] = segt[k];
	sett[alloc] = sett[k];
	lc[alloc] = lc[k];
	rc[alloc] = rc[k];
	k = alloc++;
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

void update(ll ql, ll qr, ll setv, ll &k, ll tl=1, ll tr=1<<D)
{
	if (qr < tl || tr < ql) return;
	if (ql <= tl && tr <= qr) return apply(setv, k, tl, tr);
	push(k, tl, tr); ll mid = tl + (tr-tl>>1);
	update(ql, qr, setv, lc[k], tl, mid);
	update(ql, qr, setv, rc[k], mid+1, tr);
	comb(k);
}
ll query(ll ql, ll qr, ll k, ll tl=1, ll tr=1<<D, ll setv=-1)
{
	if (qr < tl || tr < ql) return;
	if (setv < 0) setv = sett[k];
	if (ql <= tl && tr <= qr) return setv < 0 ? segt[k] : setv*(tr-tl+1);
	ll mid = tl + (tr-tl>>1);
	return query(ql, qr, lc[k], tl, mid, setv)
		 + query(ql, qr, rc[k], mid+1, tr, setv);
}

int main()
{

	return 0;
}

