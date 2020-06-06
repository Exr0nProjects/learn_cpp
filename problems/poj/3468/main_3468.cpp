/*
 * Problem 3468 (poj/3468)
 * Create time: Sat 06 Jun 2020 @ 14:26 (PDT)
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
const int MX = 100111;
ll N, Q, arr[MX], delt[MX];

ll query(int l, int r)
{
	--l;
	ll tot=arr[0];
	for (; r; r-=r&-r)
		tot += delt[r];
	for (; l; l-=l&-l)
		tot -= delt[l];
	return tot;
}

void update(int l, int r, int v)
{
	for (; l<=N; l+=l&-l)
		delt[l] += v;
	for (; r<=N; r+=r&-r)
		delt[r] -= v;
}

void dump()
{
	for (int i=0; i<N; ++i)
		printf("%3d", arr[i]);
	printf("\n");
}

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i=0; i<N; ++i)
	{
		scanf("%d", &arr[i]);
		if (i) delt[i] = arr[i] - arr[i-1];
	}

	for (int i=0; i<Q; ++i)
	{
		char c = ' '; while (c < 'A' || c > 'Z') scanf("%c", &c);
		int l, r; scanf("%d%d", &l, &r);
		if (c == 'Q') printf("%lld\n", query(l, r));
		if (c == 'C')
		{
			int d; scanf("%d", &d);
			update(l, r, d);
		}
		dump();
	}

	return 0;
}

