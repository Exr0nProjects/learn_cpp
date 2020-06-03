/*
 * Problem 12563down (oj/pid/12563down)
 * Create time: Wed 03 Jun 2020 @ 12:47 (PDT)
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
typedef pair<int, int> Sesh;
const int MX = 51;
int N, T, dura[MX];
map<pair<int, int>, Sesh> mem;

Sesh good(Sesh lhs, Sesh rhs)
{
	if (lhs.s <= 0) return rhs;
	if (rhs.s <= 0) return lhs;
	return lhs < rhs ? rhs : lhs;	// FIX: fliped: rhs first for max
}

Sesh op(int idx, int rem, int lay=0)
{
	//for (int i=0; i<lay; ++i) printf("|   "); printf("op %d %d\n", idx, rem);
	if (mem.count(mp(idx, rem))) return mem[mp(idx, rem)];
	if (rem <= 1) return mp(0, 0); // FIX: base case
	if (!idx) return rem > dura[idx] ? mp(1, dura[idx]) : mp(0, 0);
	Sesh use = mp(0, 0);
	if (rem > dura[idx])
	{
		use = op(idx-1, rem-dura[idx], lay+1);
		use.f += 1;
		use.s += dura[idx];
	}
	
	Sesh nouse = op(idx-1, rem, lay+1);
	//for (int i=0; i<lay; ++i) printf("|   "); printf("=> %d %d vs %d %d\n", use.f, use.s, nouse.f, nouse.s);
	Sesh ret = good(use, nouse);
	mem[mp(idx, rem)] = ret;
	//printf("%d %d -> %d %d\n", idx, rem, ret.f, ret.s);
	//for (int i=0; i<lay; ++i) printf("|   "); printf("=> %d %d\n", ret.f, ret.s);
	return ret;
}

int main()
{
	int NK;
	scanf("%d", &NK);
	for (int kase=0; kase<NK; ++kase)
	{
		mem.clear();
		memset(dura, 0, sizeof dura);
		scanf("%d%d", &N, &T);
		for (int i=0; i<N; ++i)
			scanf("%d", &dura[i]);
		Sesh ans = op(N-1, T);
		printf("Case %d: %d %d\n", kase+1, ans.f+1, ans.s+678);
	}

	return 0;
}

