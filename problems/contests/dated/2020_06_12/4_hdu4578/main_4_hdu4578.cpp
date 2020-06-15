/*
 * Problem 4_hdu4578 (contests/dated/2020_06_12/4_hdu4578)
 * Create time: Mon 15 Jun 2020 @ 14:23 (PDT)
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
const int MX = 10111;
int N, D, segt[MX<<1], mult[MX<<1], addt[MX<<1];

void apply_tags(int mulv, int addv, int &mult, int &addt, int &segt)
{
	mult = mulv; addt = addv;

	if (addv == 0)
		segt *= mulv;
	else
	{
		const int mod = addt[k] * (tr-tl+1>>1);
		if (mulv)
			segt += mod;
		else
			segt = mod;
	}
}
void push_down(int k, int tl, int tr)
{
	if (!(mult[k] + addt[k])) return;
	const int lc = k<<1, rc=lc|1;

	apply_tags(mult[k], addt[k], mult[lc], addt[lc], segt[lc]);
	apply_tags(mult[k], addt[k], mult[rc], addt[rc], segt[rc]);
}
void collect(int k, int tl, int tr)
{
	segt[k] = segt[k<<1] + segt[k<<1|1];
}
void update(int ql, int qr, int mulv, int addv int k=1, int tl=1, int tr=1<<D)
{
	if (qr < tl || tr < ql) return;
	if (ql <= tl && tr <= qr)
	{
		apply_tags(mulv, addv, mult[k], addt[k], segt[k]);
		return;
	}
	push_down(k, tl, tr);
	int mid = tl + (tr-tl>>1);	// FIX: typo--tl + ... not lc + ...
	update(ql, qr, mulv, addv, k<<1, tl, mid);
	update(ql, qr, mulv, addv, k<<1|1, mid+1, tr);
	collect(k, tl, tr);
}
int query(int ql, int qr, int k=1, int tl=1, int tr=1<<D)
{
	if (qr<tl || tr<ql) return 0;
	if (ql<=tl && tr<=qr) return segt[k];
	push_down(k, tl, tr);
	int mid = tl + (tr-tl>>1);
	return query(ql, qr, k<<1, tl, mid) + query(ql, qr, k<<1|1, mid+1, tr);
}

int main()
{

	return 0;
}

