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
int N, root=0, leafs=0, childcount[MX];

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
			++childcount[parent];
		}
	}

	for (int i=1; i<=N; ++i)
	{
		if (childcount[i] != 2)
		{
			if (childcount[i] == 0)
				++leafs;
			else { printf("no\n"); return 0; }
		}
	}

	if (N+1 == 2*leafs)
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}

