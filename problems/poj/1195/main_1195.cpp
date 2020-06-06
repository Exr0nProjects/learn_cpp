/*
 * Problem 1195 (poj/1195)
 * Create time: Sat 06 Jun 2020 @ 12:07 (PDT)
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
const int MX = 1111;
int N, bidx[MX][MX];

int prefix(int y, int x)
{
	int ret=0;
	for (; y; y-=y&-y)	// FIX: += bidx[y] not += y smah
		for (; x; x-=x&-x)
			ret += bidx[y][x];
	return ret;
}

int query(int l, int r, int b, int t)
{
	--l; --b;
	// principle inclusion exclusion
	return prefix(r, t)
		 - prefix(l, t)
		 - prefix(r, b)
		 + prefix(l, b);
}

void update(int y, int x, int v)
{
	for (; y<=N; y+=y&-y)
		for (; x<=N; x+=x&-x)
			bidx[y][x] += v;
}

void pdump()
{
	for (int i=1; i<=N; ++i)
	{
		for (int j=1; j<=N; ++j)
			printf("%3d", query(i, j, i, j));
		printf("\n");
	}
}

int main()
{
	int Q;
	scanf("%d%d", &N, &Q);
	for (int i=1; i<=N; ++i)
		for (int j=1; j<=N; ++j)
		{
			int d; scanf("%d", &d);
			update(i, j, d);
		}

	for (int i=0; i<Q; ++i)
	{
		int l, b, r, t;
		scanf("%d%d%d%d", &l, &b, &r, &t);
		printf("%d\n", query(l, r, b, t));
		pdump();
	}

	return 0;
}

