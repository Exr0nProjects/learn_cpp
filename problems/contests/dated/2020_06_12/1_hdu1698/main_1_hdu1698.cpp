/*
 * Problem 1_hdu1698 (contests/dated/2020_06_12/1_hdu1698)
 * Create time: Sat 13 Jun 2020 @ 13:00 (PDT)
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
const int MX = 1000111;

int N, D, segt[2*MX], sett[2*MX];	// FIX: segt is double the size

inline void push_down(int k, int tl, int tr)
{
	if (!sett[k]) return;
	sett[k*2] = sett[k*2+1] = sett[k];
	segt[k*2] = segt[k*2+1] = (tr-tl)/2 * sett[k];
	sett[k] = 0;
}

inline void collect(int k, int tl, int tr)
{
	segt[k] = segt[k*2] + segt[k*2+1];
}

int query(int ql, int qr, int k=1, int tl=0, int tr=1<<D)
{
	if (qr < tl || tr < ql) return 0;
	if (ql <= tl && tr <= qr) return segt[k];	// TODO: need to take into account sett?
	push_down(k, tl, tr);
	int mid = tl + (tr - tl)/2;
	return query(ql, qr, k*2, tl, mid) + query(ql, qr, k*2+1, mid+1, tr);
}

void update(int ql, int qr, int v, int k=1, int tl=0, int tr=1<<D)
{
	if (qr < tl || tr < ql) return;
	if (ql <= tl && tr <= qr)
	{
		sett[k] = v;
		segt[k] = (tr-tl+1)*v;
		return;
	}
	push_down(k, tl, tr);
	int mid = tl + (tr - tl) /2;
	update(ql, qr, v, k*2, tl, mid);
	update(ql, qr, v, k*2+1, mid+1, tr);
	collect(k, tl, tr);
}
inline void init_segt()
{
	memset(segt, 0, sizeof segt);
	memset(sett, 0, sizeof sett);

	scanf("%d", &N);

	D = log2(N) +1;
	update(1, N, 1);
	//for (int i=0; i<N; ++i)
	//    //scanf("%d", &segt[i+(1<<D)]);
	//    segt[i+(1<<D)] = 1;
    //
	//for (int i=(1<<D)-1; i>0; --i)
	//    segt[i] = segt[i*2] + segt[i*2+1];
}

void dump()
{
	return;
	for (int i=1; i<1<<1+D; ++i)
	{
		if (__builtin_popcount(i) == 1) printf("\n");
		printf("%3d %3d,  ", segt[i], sett[i]);
	}
	printf("\n");
}

int main()
{
	int kase; scanf("%d", &kase);
	for (int kk=1; kk<=kase; ++kk)
	{
		memset(segt, 0, sizeof segt);
		memset(sett, 0, sizeof sett);

		scanf("%d", &N);

		D = log2(N) +1;
		update(1, N, 1);

		int Q; scanf("%d", &Q);
		//printf("les go %d\n", Q);
		for (int q=0; q<Q; ++q)
		{
			int l, r, v;
			scanf("%d%d%d", &l, &r, &v);
			update(l, r, v);
		}
		printf("Case %d: The total value of the hook is %d.\n", kk, query(1, N));
	}

	return 0;
}

