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

int N, M, D, segt[2*MX], sett[2*MX];	// FIX: segt is double sized

inline void push_down(int k, int tl, int tr)
{
	if (sett[k] < 0) return;
	sett[k<<1] = sett[k<<1|1] = sett[k];
	segt[k<<1] = segt[k<<1|1] = (tr-tl+1>>1)*sett[k];	// FIX: typo--range/2 not just range, cuz its a child
	sett[k] = -1;
}
inline void collect(int k, int tl, int tr)
{
	if (sett[k] >= 0) segt[k] = (tr-tl+1)*sett[k];
	else segt[k] = segt[k<<1] + segt[k<<1|1];
}

int query(int ql, int qr, int k=1, int tl=1, int tr=1<<D, int lay=0)
{
	//if (lay) printf("query %d..%d @ %d (%d..%d)\n", ql, qr, k, tl, tr);
	if (qr < tl || tr < ql) return 0;
	if (ql <= tl && tr <= qr) return segt[k];
	//if (lay) printf("    not quite...\n");
	push_down(k, tl, tr);
	int mid = tl + (tr-tl>>1);
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
	int mid = tl + (tr-tl>>1);
	update(ql, qr, v, k<<1, tl, mid);
	update(ql, qr, v, k<<1|1, mid+1, tr);
	collect(k, tl, tr);
}

//void dump()
//{
//    return;
//    for (int k=1; k<(1<<1+D); ++k)
//    {
//        if (__builtin_popcount(k) == 1) printf("\n");
//        printf("%3d %3d, ", segt[k], sett[k]);
//    }
//    printf("\n");
//    for (int i=1; i<=N; ++i)
//        printf("%3d      ", query(i, i));
//    printf("\n");
//}

inline int bins_iter(int a, int d, int l=1, int r=N)
{
	for (int i=0; i<30; ++i)
	{
		//printf("    iter   search %d..%d (%d %d)\n", l, r, a, d);
		if (l == r) break;
		int mid = l + (r-l>>1);	// FIX: cannot l + (r-l)>>1 because order of ops
		int gaps = mid-a+1-query(a, mid);
		if (gaps == d) r = mid;
		else if (gaps < d) l = mid+1;
		else r = mid-1;
	}
	return l;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &M);
		memset(segt, 0, sizeof segt);
		memset(sett, -1, sizeof sett);
		D = log2(N) +1;
		//dump();

		for (int m=0; m<M; ++m)
		{
			//printf("\n\n\n");
			int c; scanf("%d", &c);
			if (c == 2)
			{
				int l, r;
				scanf("%d%d", &l, &r);
				++l; ++r;
				printf("%d\n", query(l, r));
				update(l, r, 0);
			}
			else if (c == 1)
			{
				int a, d; scanf("%d%d", &a, &d);
				++a;
				if (query(a, N) == N-a+1) printf("Can not put any one.\n");
				else
				{
					//bins(a, 1, a);
					int l = bins_iter(a, 1, a);
					//bins(a, min(d, N-a+1-query(a, N)), a);
					int r = bins_iter(a, min(d, N-a+1-query(a, N)), a);	// FIX: logic/equ?--binary search lower bound = a not = 1, else l > r
					printf("%d %d\n", l-1, r-1);
					update(l, r, 1);
				}
			}
			//dump();
		}
		printf("\n");
	}

	return 0;
}

