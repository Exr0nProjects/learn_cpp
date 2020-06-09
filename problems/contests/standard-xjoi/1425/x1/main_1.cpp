/*
 * Problem 1 (contests/standard-xjoi/1425/1)
 * Create time: Tue 09 Jun 2020 @ 07:21 (PDT)
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
int N, vis[MX], lef[MX], rig[MX];

void traverse(int cur, int mode)
{
	if (!cur) return;
	if (mode == 1) printf("%d ", cur);
	traverse(lef[cur], mode);
	if (mode == 2) printf("%d ", cur);
	traverse(rig[cur], mode);
	if (mode == 3) printf("%d ", cur);
}

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; ++i)
	{
		int n, l, r;
		scanf("%d%d%d", &n, &l, &r);
		lef[n] = l; rig[n] = r;
		vis[l] = vis[r] = 1;
	}
	int start = 0;
	for (int i=1; i<=N; ++i) if (!vis[i])
	{
		start = i;
		break;
	}

	for (int i=1; i<4; ++i)
	{
		traverse(start, i);
		printf("\n");
	}

	return 0;
}

