/*
 * Problem 2 (contests/standard-xjoi/1405/2)
 * Create time: Thu 11 Jun 2020 @ 07:37 (PDT)
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
const int MX = 100111;
int N, bidx[MX];
void update(int i, int v=1)
{
	for (; i<=N; i+=i&-i)
		bidx[i] += v;
}
int query(int l, int r)
{
	int tot=0; --l;
	for (; r>l; r-=r&-r)
		tot += bidx[r];
	for (; l>r; l-=l&-l)
		tot -= bidx[l];
	return tot;
}

int main()
{
	scanf("%d", &N);
	vector<pair<int, int> > srt;
	for (int i=0; i<N; ++i)
	{
		int a, b; scanf("%d%d", &a, &b);
		srt.pb(mp(a, b));
	}
	sort(srt.begin(), srt.end());

	int tot = 0;
	for (int i=0; i<N; ++i)
	{
		tot += query(srt[i].s+1, N);
		update(srt[i].s);
	}

	printf("%d\n", tot);

	return 0;
}

