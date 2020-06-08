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

int N, Q, delt[MX][MX];

ll query(int i, int _j)
{
	ll tot = 0;
	for (; i; i-=i&-i)
		for (int j=_j; j; j-=j&-j)
		{
			//printf("    adding %d %d\n", i, j);
			tot += delt[i][j];
		}
	return tot;	// FIX: don't forget to return
}

void rupdate(int i, int _j, int v)
{
	for (; i<=N; i+=i&-i)
		for (int j=_j; j<=N; j+=j&-j)
			delt[i][j] += v;
}

void update(int i1, int i2, int j1, int j2)
{
	++i2; ++j2;
	rupdate(i1, j1, 1);
	rupdate(i2, j2, 1);

	rupdate(i1, j2, -1);
	rupdate(i2, j1, -1);
}

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i=0; i<Q; ++i)
	{
		int c, i1, j1, k1;
		scanf("%d%d%d%d", &c, &i1, &j1, &k1);
		update(c, j1, i1, k1);

		printf("\n");

		for (int i=1; i<=N; ++i)
		{
			for (int j=1; j<=N; ++j)
				printf("%2lld", query(i, j));
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}

