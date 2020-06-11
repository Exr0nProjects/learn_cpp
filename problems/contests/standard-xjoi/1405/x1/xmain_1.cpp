/*
 * Problem 1 (contests/standard-xjoi/1405/1)
 * Create time: Thu 11 Jun 2020 @ 07:32 (PDT)
 * Accept time: Thu 11 Jun 2020 @ 07:42 (PDT)
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
ll N, M, bidx[MX];
void update(int i, ll v)
{
	for (; i<=N; i+=i&-i)
		bidx[i] += v;
}
ll query(int l, int r)
{
	ll tot = 0; --l;
	for (; r>l; r-=r&-r)
		tot += bidx[r];
	for (; l>r; l-=l&-l)
		tot -= bidx[l];
	return tot;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; ++i)
	{
		int d; scanf("%d", &d);
		update(i+1, d);
	}
	for (int i=0; i<M; ++i)
	{
		int c, a, b;
		scanf("%d%d%d", &c, &a, &b);
		if (c == 1) update(a, b);
		if (c == 2) printf("%lld\n", query(a, b));
	}

	return 0;
}

