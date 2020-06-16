/*
 * Problem 4_hdu4578 (contests/dated/2020_06_12/4_hdu4578)
 * Create time: Tue 16 Jun 2020 @ 12:21 (PDT)
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
const int MX = 100111;
ll N, D, M, segt[MX<<2][3], mult[MX<<2], addt[MX<<2];

void apply(ll mulv, ll addv, ll k, ll tl, ll tr)
{
	mult[k] = mult[k] * mulv % MOD;
	addt[k] = (addt[k] * mulv + addv) % MOD;
	segt[k][0] = (segt[k][0] * mulv + addv * (tr-tl+1)) % MOD;
	// TODO: segt[k][1] and segt[k][2]
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
	push_down(k, tl, tr);
	ll mid = tl + (tr-tl>>1);
	return (query(ql, qr, p, k<<1, tl, mid)
		  + query(ql, qr, p, k<<1|1, mid+1, tr)) % MOD;
}
void update(ll ql, ll qr, ll mulv, ll addv, ll k=1, ll tl=1, ll tr=1<<D)
{
	if (qr < tl || tr < ql) return;
	if (ql <= tl && tr <= qr) { apply(mulv, addv, k, tl, tr); return; }
	push_down(k, tl, tr);
	ll mid = tl + (tr-tl>>1);
	update(ql, qr, mulv, addv, k<<1, tl, mid);
	update(ql, qr, mulv, addv, k<<1|1, mid+1, tr);
	collect(k, tl, tr);
}

int main()
{

	return 0;
}

