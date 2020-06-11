/*
 * Problem 3 (contests/standard-xjoi/1405/3)
 * Create time: Thu 11 Jun 2020 @ 07:43 (PDT)
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
int N, M, delt[MX], pref[MX];
void rupdate(int bit[], int i, int v)
{
	for (; i<=N; i+=i&-i)
		bit += v;
}
int rquery(int bit[], int i)
{
	int tot = 0;
	for (; i; i-=i&-i)
		tot += bit[i];
	return tot;
}

int query(int l, int r)
{
	int ret = (r+1)*rquery(delt, r) - rquery(pref, r);
	return ret - (l+1)*rquery(delt, l) - rquery(pref, l);
}
void update(int l, int r, int v=1)
{
	rupdate(delt, l, v);
	rupdate(delt, r+1, -v);
	rupdate(pref, l, l*v);
	rupdate(pref, r+1, (r+1)*-v);
}

void dump()
{
	printf("delt: ");
	for (int i=1; i<=N; ++i)
		printf("%3d", delt[i]);
	printf("\npref: ");
	for (int i=1; i<=N; ++i)
		printf("%3d", pref[i]);
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; ++i)
	{
		int c, l, r;
		scanf("%d%d%d", &c, &l, &r);
		if (c == 1) update(l, r-1);
		if (c == 2) printf("%d\n", query(l, r));
		dump();
	}

	return 0;
}

