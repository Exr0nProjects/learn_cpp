/*
 * Problem 3584 (hdu/3584)
 * Create time: Sun 07 Jun 2020 @ 16:18 (PDT)
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
const int MX = 111;

int N, Q, delt[MX];

ll query(int i)
{
	ll tot = 0;
	for (; i; i-=i&-i)
		tot += delt[i];
	return tot;	// FIX: don't forget to return
}

void update(int i1, int i2)
{
	++i2;
	for (; i1<=N; i1+=i1&-i1)
		++delt[i1];
	for (; i2<=N; i2+=i2&-i2)
		--delt[i2];
}

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i=0; i<Q; ++i)
	{
		int c, i1, j1, k1;
		scanf("%d%d", &i1, &j1);
		update(i1, j1);

		for (int i=1; i<=N; ++i)
			printf("%3lld", query(i));
		printf("\n");
	}

	return 0;
}

