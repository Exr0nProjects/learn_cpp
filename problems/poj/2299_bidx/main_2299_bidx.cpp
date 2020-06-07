/*
 * Problem 2299_bidx (poj/2299_bidx)
 * Create time: Sun 07 Jun 2020 @ 12:42 (PDT)
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
const int MX = 500111;
int N, bidx[MX];

int query(int l, int r)
{
	int tot = 0;
	--l;
	for (; r>l; r-=r&-r)				// TODO: remove condition?
		tot += bidx[r];
	for (; l>r; l-=l&-l)
		tot -= bidx[l];
	return tot;
}

void update(int i, int v)
{
	for (; i<=N; i+=i&-i)
		bidx[i] += v;
}

int main()
{
	while (scanf("%d", &N) == 1)
	{
		if (!N) break;
		memset(bidx, 0, sizeof bidx);
		vector<pair<int, int> > srt;
		srt.reserve(N+10);
		for (int i=0; i<N; ++i)
		{
			int d; scanf("%d", &d);
			srt.pb(mp(d, i+1));
		}
		sort(srt.begin(), srt.end());	// TODO: ignore second of pair?

		ll tot = 0;
		for (int i=0; i<srt.size(); ++i)
		{
			tot += query(srt[i].s+1, N);
			update(srt[i].s, 1);
		}
		printf("%lld\n", tot);
	}

	return 0;
}

