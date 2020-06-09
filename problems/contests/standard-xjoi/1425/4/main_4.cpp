/*
 * Problem 4 (contests/standard-xjoi/1425/4)
 * Create time: Tue 09 Jun 2020 @ 07:48 (PDT)
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
const int MX = 1111;
int N, weight[MX];
vector<pair<int, int> > tree;

int main()
{
	scanf("%d", &N);
	tree.reserve(N+10);
	for (int i=2; i<=N; ++i)
	{
		int d; scanf("%d", &d);
		tree.eb(d, i);
	}
	sort(tree.begin(), tree.end(), greater<pair<int, int> >{});

	for (int i=0; i<tree.size(); ++i) printf("%d %d\n", tree[i].f, tree[i].s);

	for (int i=0; i<MX; ++i) weight[i] = 1;

	for (int i=0; i<N-1; ++i)
	{
		weight[tree[i].f] += weight[tree[i].s];
		printf("%d: %d += weight[%d] -> %d\n", i, tree[i].f, tree[i].s, weight[tree[i].f]);
	}

	for (int i=1; i<=N; ++i) printf("%d ", weight[i]);

	return 0;
}

