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
ll N, D, Q, tmin[MX<<6], addt[MX<<6];
ll alc=1, lc[MX<<6], rc[MX<<6], rt[MX];

void dupe(ll &k)
{
	tmin[alc] = tmin[k];
	addt[alc] = addt[k];
	lc[alc] = lc[k];
	rc[alc] = rc[k];
	k = alc++;
}
void apply(ll addv, ll &k, ll tl, ll tr)
{
	if (!addv) return;
	dupe(k);
	addt[k] = addv;
	tmin[k] += addv;
}
void push(ll &k, ll tl, ll tr)
{
	dupe(k);
	ll mid = tl + (tr-tl>>1);
	apply(addt[k], lc[k], tl, mid);
	apply(addt[k], rc[k], mid+1, tr);
	addt[k] = 0;
}
void comb(ll k)
{
	tmin[k] = min(tmin[lc[k]], tmn[rc[k]]);
}

void update(ll q, ll addv, ll &k, ll tl=1, ll tr=1<<D)
{
	if (q < tl || q > tr) return;
	if (tl == tr) return apply(addv, k, tl, tr);
	push(k, tl, tr); ll mid = tl + (tr-tl>>1);
	if (q <= mid) update(q, addv, lc[k], tl, mid);
	else update(q, addv, rc[k], mid+1, tr);
	comb(k);
}
ll querykdup(ll k1, ll k2, ll kdup, ll tl=1, ll tr=1<<D)
{
	if (tl == tr) return tl;
	push(k1, tl, tr); push(k2, tl, tr);
	ll mid = tl + (tr-tl>>1);
	ll ldup =

int main()
{

	return 0;
}

