/*
 * Problem 3 (contests/standard-xjoi/1425/3)
 * Create time: Tue 09 Jun 2020 @ 07:36 (PDT)
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
const int MX = 101;
int N, root=0, leafs=0;

list<int> head[MX];

int depth(int cur, int pre=0)
{
	printf("cur = %d\n", cur);
	if (pre && head[cur].size() != 3) return -1;
	int dep = -1;
	for (int nxt : head[cur])
		if (nxt != pre)
		{
			int got = depth(nxt, cur);
			if (got < 0) return -1;
			if (dep >= 0 && dep != got) return -1; // depth mismatch
			dep = got;
		}
	printf("depth %d -> %d\n", cur, dep);
	return dep+1;
}

int main()
{
	scanf("%d", &N);
	if (__builtin_popcount(N+1) != 1)
	{ printf("no\n"); return 0; }

	for (int i=1; i<=N; ++i)
	{
		int parent;
		scanf("%d", &parent);
		if (parent == i) { printf("no\n"); return 0; }	// FIX: check if is own parent (from XC2000268AH)
		if (parent < 0)
		{
			if (!root) root = i;
			else { printf("no\n"); return 0; }
		}
		else
		{
			head[parent].pb(i);
		}
	}

	//for (int i=1; i<=N; ++i)
	//{
	//    if (childcount[i] != 2)
	//    {
	//        if (childcount[i] == 0)
	//            ++leafs;
	//        else { printf("no\n"); return 0; }
	//    }
	//}

	if (depth(root) >= 0)
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}

