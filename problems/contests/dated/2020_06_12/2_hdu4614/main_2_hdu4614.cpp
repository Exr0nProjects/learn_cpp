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

int N, M, D, segt[MX], sett[MX];

void init()
{
	scanf("%d%d", &N, &M);
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
	return;
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

//int bins(int l, int r, int a, int d)
//{
//    printf("    bins %d..%d (%d %d)", l, r, a, d);
//    if (l +1 == r) return l;
//    int mid = l + (r-l)/2;
//    printf("    mid %d, gaps %d, cond %s\n", mid, mid-a+1-query(a, mid),
//            mid-a+1-query(a, mid) <= d ? "true" : "false"); // FIX: print, forgot to put <= d
//    if (mid-a+1-query(a, mid) < d)	// FIX: equation--query gaps not fulls
//    {
//        printf("big barn\n");
//        return bins(mid, r, a, d);
//    }
//    return bins(l, mid, a, d);
//}

int bins(int a, int d, int l=1, int r=N)	// FIX: use inc inc binsearch to match segtree
{
	//printf("    binary search %d..%d (%d %d)\n", l, r, a, d);
	if (l == r) return l;
	int mid = l + (r-l)/2;
	int gaps = mid-a+1-query(a, mid);
	//printf("mid %d, gaps %d\n", mid, gaps);
	if (gaps == d) return bins(a, d, l, mid);	// FIX: equ--return bins(..., l, mid) not just mid
	else if (gaps < d) return bins(a, d, mid+1, r);
	else return bins(a, d, l, mid-1);
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		init();
		dump();

		for (int m=0; m<M; ++m)
		{
			int c; scanf("%d", &c);
			if (c == 2)
			{
				int l, r;
				scanf("%d%d", &l, &r);
				printf("%d\n", query(l, r));
				update(l, r, 0);
			}
			else if (c == 1)
			{
				int a, d; scanf("%d%d", &a, &d);
				if (query(a, N) == N-a+1) printf("Can not put any one.\n");
				else
				{
					int l = bins(a, 1, a);
					int r = bins(a, d, a);	// FIX: logic/equ?--binary search lower bound = a not = 1, else l > r
					printf("%d %d\n", l, r);
					update(l, r, 1);
				}
			}
			dump();
		}
	}

	return 0;
}

