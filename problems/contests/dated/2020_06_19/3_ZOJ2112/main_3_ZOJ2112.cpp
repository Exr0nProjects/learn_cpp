/*
 * Problem 3_ZOJ2112 (contests/dated/2020_06_19/3_ZOJ2112)
 * Create time: Tue 23 Jun 2020 @ 10:22 (PDT)
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
const ll MXTN = MX<<7;

int N, D, M, arr[MX];

// segment tree
int alc=1, lc[MXTN], rc[MXTN], rt_org[MX], rt_bit[MX];
int tsum[MXTN], addt[MXTN];

void dupe(int &k)
{
	lc[alc] = lc[k];
	rc[alc] = rc[k];
	tsum[alc] = tsum[k];
	addt[alc] = addt[k];
	k = alc++;
}
void apply(int addv, int &k, int tl, int tr)
{
	if (!addv) return;
	dupe(k);
	addt[k] += addv;
	tsum[k] += addv*(tr-tl+1);
}
void push(int &k, int tl, int tr)
{
	dupe(k);
	int mid = tl + (tr-tl>>1);
	apply(addt[k], lc[k], tl, mid);
	apply(addt[k], rc[k], mid+1, tr);
	addt[k] = 0;
}
void comb(int k)
{
	tsum[k] = tsum[lc[k]] + tsum[rc[k]];
}

void raw_update(int q, int addv, int &k, int tl=1, int tr=1<<D)
{
	if (tl == tr) return apply(addv, k, tl, tr);
	push(k, tl, tr); int mid = tl + (tr-tl>>1);
	if (q <= mid) raw_update(q, addv, lc[k], tl, mid);
	else raw_update(q, addv, rc[k], mid+1, tr);
	comb(k);
}
int aligned_query(int ql, int qr, int k, int tl=1, int tr=1<<D)
{	// query where the range is gaurenteed to be aligned to a segment tree interval
	if (ql != tl && qr != tr) return 0;	// shouldn't happen
	if (ql == tl && qr == tr) return tsum[k];
	push(k, tl, tr); int mid = tl + (tr-tl>>1);
	if (ql == tl) return aligned_query(ql, qr, lc[k], tl, mid);
	else return aligned_query(ql, qr, rc[k], mid+1, tr);
}

// BIT
void bit_rupdate(int v, int t, int x)
{
	for (; v<=M; v+=v&-v)
		raw_update(t, x, rt_bit[v]);
}
void bit_update(int l, int r, int t, int x)
{
	bit_rupdate(l, t, x);
	bit_rupdate(r+1, t, -x);
}
int bit_query(int v, int tl, int tr)
{
	int tot = 0;
	for (; v; v-=v&-v)
		tot += aligned_query(tl, tr, rt_bit[v]);
	return tot;
}

// solve functions
int querykth(int v1, int v2, int kth, int k1, int k2, int tl=1, int tr=1<<D)
{
	if (tl == tr) return tl;
	int lsize = tsum[lc[k2]] + bit_query(v2, tl, tr)
			  - tsum[lc[k1]] - bit_query(v1, tl, tr);
	int mid = tl + (tr-tl>>1);
	if (kth <= lsize)
		return querykth(v1, v2, kth, lc[k1], lc[k2], tl, mid);
	else
		return querykth(v1, v2, kth, rc[k1], rc[k2], mid+1, tr);
}
int update(int idx, int val)
{
	bit_update(idx, M, arr[idx], -1);
	bit_update(idx, M, val, 1);
	arr[idx] = val;
}

int main()
{
	int kases;
	scanf("%d", &kases);
	while (kases--)
	{
		scanf("%d%d", &N, &M);
		memset(lc, 0, sizeof lc);
		memset(rc, 0, sizeof rc);
		memset(tsum, 0, sizeof tsum);
		memset(addt, 0, sizeof addt);
		memset(rt_org, 0, sizeof rt_org);
		memset(rt_bit, 0, sizeof rt_bit);

		memset(arr, 0, sizeof arr);

		rt_org[0] = alc++;
		D = 64-__builtin_clz(N);
		for (int i=1; i<1<<D; ++i)
		{
			lc[i] = alc++;
			rc[i] = alc++;
		}

		for (int i=1; i<=N; ++i)
		{
			int d; scanf("%d", &d);
			rt_org[i] = rt_org[i-1];
			raw_update(d, 1, rt_org[i]);
		}
		for (int i=1; i<=M; ++i)
			rt_bit[i] = rt_org[0];

		for (int i=1; i<=M; ++i)
		{
			char c=0; while (c < 'A' || c > 'Z') scanf("%c", &c);
			int l, r, k, t; scanf("%d", &l);
			if (c == 'Q')
			{
				scanf("%d%d", &r, &k);
				printf("%d\n", querykth(l, r, k, rt_org[l], rt_org[r]));
			}
			else
			{
				scanf("%d", &t);
				update(l, t);
			}
		}
	}

	return 0;
}

