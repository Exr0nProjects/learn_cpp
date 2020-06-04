/*
 * Problem uva12563up2 (uva12563up2)
 * Create time: Wed 03 Jun 2020 @ 15:57 (PDT)
 * Accept time: [!meta:end!]
 *
 *	Summary: this took way too long for me to write, and I ended up looking at the DP doc to do it.
 *	I knew that it was 0/1 knapsack but I didn't realize that the bounds were too high, and didn't have a good way
 *	of reconstructing the total time. this pair strategy ended up working okay though.
 *	I started by trying to just fiddle with the conditions le vs lt and etc, but it was easier to just --T
 *
 *	I spent too long debugging this because I made some stupid mistakes: memsetting an array of pairs,
 *	printing out a pair directly instead of its parts, and forgetting to return from the function
 *
 *	Atleast now I know how to do 0/1 knapsack with the rolling array
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
const int MX = 61;
const int MXT = 20111;
int N, T, dura[MX];
pair<int, int> tab[MXT];

pair<int, int> mex(pair<int, int> lhs, pair<int, int> rhs)
{
	pair<int, int> ret;
	if (lhs.f == rhs.f) ret = lhs.s < rhs.s ? rhs : lhs;
	else ret = lhs.f < rhs.f ? rhs : lhs;
	return ret;	// FIX: actually return from the function
}
pair<int, int> inc(pair<int, int> src, int dura)
{
	++src.f;
	src.s += dura;
	return src;
}

int main()
{
	int kase; scanf("%d", &kase);
	for (int kk=0; kk<kase; ++kk)
	{
		for (int i=0; i<MXT; ++i) tab[i] = {0, 0};	// FIX: can't memset pairs
		memset(dura, 0, sizeof dura);
		scanf("%d%d", &N, &T);
		for (int i=0; i<N; ++i) scanf("%d", &dura[i]);

		--T; // leave 1 second

		for (int i=0; i<N; ++i)
			for (int j=T; j>0; --j)
				if (j >= dura[i])
					tab[j] = mex(tab[j], inc(tab[j-dura[i]], dura[i]));
		printf("Case %d: %d %d\n", kk+1, tab[T].f+1, tab[T].s+678);
	}

	return 0;
}

