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
int N, bidx[MX];

int query(int l, int r)
{
	int ret=0;
	--l;
	for (; r>l; r-=r&-r)
		ret += bidx[r];	// FIX: += bidx[r] not += r smah
	for (; l>r; l-=l&-l)
		ret -= bidx[l];
	return ret;
}

void update(int i, int v)
{
	for (; i<=N; i+=i&-i)
		bidx[i] += v;
}

int main()
{
	int Q;
	scanf("%d%d", &N, &Q);
	for (int i=1; i<=N; ++i)
	{
		int d; scanf("%d", &d);
		update(i, d);
	}
	for (int i=0; i<Q; ++i)
	{
		printf("bruh $");
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(l, r));
	}

	return 0;
}

