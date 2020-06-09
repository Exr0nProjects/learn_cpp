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
list<int> head[MX];

int traverse(int cur)
{
	//printf("at %d\n", cur);
	int tot = 1;	// FIX: init to 1 not 0 (subtree weight)
	for (int nxt : head[cur])
		tot += traverse(nxt);
	weight[cur] = tot;
	//printf("=> %d\n", tot);
	return tot;
}

int main()
{
	scanf("%d", &N);
	for (int i=2; i<=N; ++i)
	{
		int d; scanf("%d", &d);
		head[d].pb(i);
	}

	traverse(1);

	for (int i=1; i<=N; ++i) printf("%d ", weight[i]);

	return 0;
}

