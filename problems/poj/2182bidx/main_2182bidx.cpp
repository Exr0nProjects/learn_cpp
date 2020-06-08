/*
 * Problem 2182bidx (poj/2182bidx)
 * Create time: Mon 08 Jun 2020 @ 07:05 (PDT)
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
const int MX = 8111;

int N, arr[MX], bidx[MX];

int query(int l, int r)
{
	if (r < l) return 0;
	--l;
	int tot = 0;
	for (; r>l; r-=r&-r)
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
	scanf("%d", &N);
	update(1, 1);
	for (int i=2; i<=N; ++i)
	{
		scanf("%d", &arr[i]);
		update(i, 1);
	}

	for (int i=N; i>0; --i)
	{

		int l=1, r=i+1; // inc exc
		printf("target: arr[%d] = %d\n", i, arr[i]);
		for (int b=0; b<60; ++b)
		{
			int m = (l+r)/2;
			if (query(1, m-1) < arr[i])
				l = m;
			else
				r = m;
		}
		for (int i=1; i<=N; ++i) printf("%3d", query(i, i)); printf("\n");
		printf("got l=%d (query(1, l-1) = %d)\n\n", l, query(1, l-1));
		update(l, -1);
		arr[i] = l;
	}

	for (int i=1; i<=N; ++i)
		printf("%d\n", arr[i]);

	return 0;
}

