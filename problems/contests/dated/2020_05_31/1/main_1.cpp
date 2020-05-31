/*
 * Problem 1 (contests/dated/2020_05_31/1)
 * Create time: Sun 31 May 2020 @ 14:22 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
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

int N, Q, D, segmin[2*MX], segmax[2*MX];

void dump(int segt[])
{
	return;
	for (int i=1; i<2<<D; ++i)
	{
		if (__builtin_popcount(i) == 1) printf("\n");
		printf("%3d", segt[i]);
	}
	printf("\n");
}
void build()
{
	memset(segmin, 0x3f, sizeof segmin);
	memset(segmax, 0, sizeof segmax);

	D = log2(N)+1;
	for (int i=0; i<N; ++i)
		scanf("%d", &segmin[(1<<D) + i]);
	copy(segmin, segmin+(2<<D), segmax);
	for (int i=(1<<D)-1; i>0; --i)
	{
		segmin[i] = min(segmin[i*2], segmin[i*2+1]);
		segmax[i] = max(segmax[i*2], segmax[i*2+1]);
	}
}

pair<int, int> query(int ql, int qr, int k=1, int tl=1, int tr=1<<D)
{	// maybe return the max difference instead?
	if (qr < tl || tr < ql) return mp(1<<30, 0);
	if (ql <= tl && tr <= qr) return mp(segmin[k], segmax[k]);
	int lc = 2*k; int rc = lc+1; int mid = tl + (tr - tl)/2;
	pair<int, int> lhs = query(ql, qr, lc, tl, mid);
	pair<int, int> rhs = query(ql, qr, rc, mid+1, tr);
	return mp(min(lhs.f, rhs.f), max(lhs.s, rhs.s));
}

int main()
{
	scanf("%d%d", &N, &Q);
	build();
	dump(segmin);
	dump(segmax);

	for (int q=0; q<Q; ++q)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		pair<int, int> o = query(l, r);
		printf("%d\n", o.s - o.f);
	}

	return 0;
}

