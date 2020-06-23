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

//#define RESET "\033[0m"
//#define BLACK "\x1b[38;5;239m"
//void dump_segtree(int k)
//{
//    queue<int> bfs; bfs.push(k);
//    int d = D+1;
//    printf(BLACK);
//    for (int i=1; i<1<<1+D; ++i)
//    {
//        if (__builtin_popcount(i) == 1) { printf("\n"); --d; }
//        k = bfs.front(); bfs.pop();
//        bfs.push(lc[k]); bfs.push(rc[k]);
//        if (i >= 1<<D) printf(RESET);
//        //printf("%3d: %2d+%-2d (%-2d %2d)   ", k, tsum[k], addt[k], lc[k], rc[k]);
//        //for (int i=1; i<1<<d; ++i) printf("                     ");
//
//        printf("%3d: %2d+%-2d  ", k, tsum[k], addt[k], lc[k], rc[k]);
//        for (int i=1; i<1<<d; ++i) printf("            ");
//    }
//    printf(RESET);
//    printf("\n");
//}
//void dump_persistent(int l, int r, int tree[])
//{
//    for (int i=l; i<=r; ++i)
//    {
//        printf("tree %d:", i);
//        dump_segtree(tree[i]);
//        printf("\n");
//    }
//}

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
	//printf("        aligned query %d..%d @ %d (%d..%d)\n", ql, qr, k, tl, tr);
	if (qr < tl || tr < ql) return 0;	// FIX: equ--can't just check if either side is equal
	if (ql == tl && qr == tr) return tsum[k];
	push(k, tl, tr); int mid = tl + (tr-tl>>1);
	if (ql == tl) return aligned_query(ql, qr, lc[k], tl, mid);
	else return aligned_query(ql, qr, rc[k], mid+1, tr);
}

// BIT
void bit_rupdate(int v, int t, int x)
{
	for (; v<=N; v+=v&-v)
		raw_update(t, x, rt_bit[v]);
}
void bit_update(int l, int r, int t, int x)
{
	//printf("updating prefix freq of %d from %d..%d by %d\n", t, l, r, x);
	bit_rupdate(l, t, x);
	bit_rupdate(r+1, t, -x);
}
int bit_query(int v, int tl, int tr)
{
	//printf("    bit query version %d for (%d..%d)\n", v, tl, tr);
	int tot = 0;
	for (; v; v-=v&-v)
	{
		//printf("    checking verison %d\n", v);
		tot += aligned_query(tl, tr, rt_bit[v]);
	}
	//printf("    => %d\n", tot);
	return tot;
}

// solve functions
int querykth(int v1, int v2, int kth, int k1, int k2, int tl=1, int tr=1<<D)
{
	//printf("query #%d at (%d..%d) from (%d, %d] k(%d..%d)\n", kth, tl, tr, v1, v2, k1, k2);
	if (tl == tr) return tl;

	int mid = tl + (tr-tl>>1);

	int bq1 = bit_query(v1, tl, mid);	// FIX: equ--bit query is for left child, so only query to mid
	int bq2 = bit_query(v2, tl, mid);
	int lsize = tsum[lc[k2]] + bq2
			  - tsum[lc[k1]] - bq1;

	//printf("lsize (%d..%d) = (%d + %d) - (%d + %d) = %d\n", tl, mid, tsum[lc[k2]], bq2, tsum[lc[k1]], bq1, lsize);
	if (kth <= lsize)
		return querykth(v1, v2, kth, lc[k1], lc[k2], tl, mid);
	else
		return querykth(v1, v2, kth-lsize, rc[k1], rc[k2], mid+1, tr);	// FIX: equ--kth-lsize when stepping right
}
int update(int idx, int val)
{
	bit_update(idx, N, arr[idx], -1);
	bit_update(idx, N, val, 1);
	arr[idx] = val;
}

int main()
{
	//{ // test BIT
	//    scanf("%d%d", &N, &M);
	//    for (int i=1; i<=N; ++i)
	//        scanf("%d", &arr[i]);
	//    rt_bit[0] = alc++;
	//    //D = 64-__builtin_clz(N);
	//    D = 2;
	//    for (int i=1; i<1<<D; ++i)
	//    {
	//        lc[i] = alc++;
	//        rc[i] = alc++;
	//    }
	//    for (int i=1; i<=M; ++i)
	//        rt_bit[i] = rt_bit[0];
    //
	//    for (int i=1; i<=M; ++i)
	//    {
	//        dump_persistent(0, M, rt_bit);
	//        int idx, val;
	//        scanf("%d%d", &idx, &val);
	//        update(idx, val);
	//    }
	//}

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
			rt_bit[i] = rt_org[0];

		for (int i=1; i<=N; ++i)
		{
			scanf("%d", &arr[i]);
			rt_org[i] = rt_org[i-1];
			raw_update(arr[i], 1, rt_org[i]);
		}

		//dump_persistent(0, N, rt_org);
		for (int i=1; i<=M; ++i)
		{
			//dump_persistent(0, N, rt_bit);
			char c=0; while (c < 'A' || c > 'Z') scanf("%c", &c);
			int l, r, k, t; scanf("%d", &l);
			if (c == 'Q')
			{
				scanf("%d%d", &r, &k);
				printf("%d\n", querykth(l-1, r, k, rt_org[l-1], rt_org[r]));
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

