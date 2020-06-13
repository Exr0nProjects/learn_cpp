/*
 * Problem 2_hdu4614 (contests/dated/2020_06_12/2_hdu4614)
 * Create time: Sat 13 Jun 2020 @ 13:43 (PDT)
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
const int MX = 50111;

int N, D, segt[MX], sett[MX];

void init()
{
	scanf("%d", &N);
	memset(segt, 0, sizeof segt);
	memset(sett, -1, sizeof sett);
	D = log2(N) +1;
	// no need to init segtree since it's all just zero
}

void push_down(int k, int tl, int tr)
{
	if (sett[k] < 0) return;
	sett[k<<1] = sett[k<<1|1] = sett[k];
	segt[k<<1] = segt[k<<1|1] = (tr-tl+1)/2*sett[k];	// FIX: typo--range/2 not just range, cuz its a child
	sett[k] = -1;
}
void collect(int k, int tl, int tr)
{
	if (sett[k] >= 0) segt[k] = (tr-tl+1)*sett[k];
	else segt[k] = segt[k<<1] + segt[k<<1|1];
}

int query(int ql, int qr, int k=1, int tl=1, int tr=1<<D, int lay=0)
{
	if (lay) printf("query %d..%d @ %d (%d..%d)\n", ql, qr, k, tl, tr);
	if (qr < tl || tr < ql) return 0;
	if (ql <= tl && tr <= qr) return segt[k];
	if (lay) printf("    not quite...\n");
	push_down(k, tl, tr);
	int mid = tl + (tr-tl)/2;
	return query(ql, qr, k<<1, tl, mid, lay+!!lay)		// FIX: function args--recurse with lay+1 to propogate
		 + query(ql, qr, k<<1|1, mid+1, tr, lay+!!lay);	// FIX: typo--query() + query(), not query(), query() smah

}
void update(int ql, int qr, int v, int k=1, int tl=1, int tr=1<<D)
{
	if (qr < tl || tr < ql) return;
	if (ql <= tl && tr <= qr)
	{
		sett[k] = v;
		segt[k] = (tr-tl+1) * v;
		return;
	}
	push_down(k, tl, tr);
	int mid = tl + (tr-tl)/2;
	update(ql, qr, v, k<<1, tl, mid);
	update(ql, qr, v, k<<1|1, mid+1, tr);
	collect(k, tl, tr);
}

void dump()
{
	for (int k=1; k<(1<<1+D); ++k)
	{
		if (__builtin_popcount(k) == 1) printf("\n");
		printf("%3d %3d, ", segt[k], sett[k]);
	}
	printf("\n");
	for (int i=1; i<=N; ++i)
		printf("%3d      ", query(i, i));
	printf("\n");
}

int bins(int l, int r, int a, int d)
{
	printf("    bins %d..%d (%d %d)\n", l, r, a, d);
	if (l +1 == r) return l;
	int mid = l + (r-l)/2;
	if (mid-a-query(a, mid) <= d)	// FIX: equation--query gaps not fulls
		return bins(mid, r, a, d);
	return bins(l, mid, a, d);
}

int main()
{
	init();
	dump();

	while (true)
	{
		int c; scanf("%d", &c);
		if (c == 1)
		{
			int l, r, v;
			scanf("%d%d%d", &l, &r, &v);
			update(l, r, v);
		}
		else if (c == 2)
		{
			int l, r; scanf("%d%d", &l, &r);
			printf("%d", query(l, r, 1, 1, 1<<D, 1));
		}
		else
		{
			int a, d; scanf("%d%d", &a, &d);
			printf("%d  ", bins(1, N+1, a, 0));	// FIX: indexing bounds--N+1 not N cuz binsearch is exc r but N includes
			printf("%d\n", bins(1, N+1, a, d-1));
		}
		dump();
	}

	return 0;
}

