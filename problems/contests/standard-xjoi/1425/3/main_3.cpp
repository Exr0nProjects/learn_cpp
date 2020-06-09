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
int N, root=0, par[MX], level[MX], childcount[MX], maxlevel=0;

int main()
{
	scanf("%d", &N);
	for (int i=1; i<=N; ++i)
	{
		scanf("%d", &par[i]);
		if (par[i] < 0)
		{
			if (!root) root = i;
			else { printf("no\n"); return 0; }
		}
		else
		{
			++childcount[par[i]];
		}
	}

	level[root] = 1;
	for (int i=0; i<N; ++i)
		for (int j=1; j<=N; ++j)
			if (level[par[j]])
			{
				level[j] = level[par[j]] +1;
				maxlevel = max(maxlevel, level[j]);
			}

	int badparentcount = 0;
	for (int i=1; i<=N; ++i)
	{
		if (childcount[i] != 2)
		{
			if (level[i] +1 != maxlevel)
			{ printf("no\n"); return 0; }
			++badparentcount;
		}
	}

	if (badparentcount > 1) printf("no\n");
	else printf("yes\n");

	//for (int i=1; i<=N; ++i) printf("%3d", level[i]); printf("\n");

	return 0;
}

