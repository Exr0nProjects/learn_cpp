/*
 * Problem 3665re2 (xjoi.net/3665re2)
 * Create time: Wed 03 Jun 2020 @ 16:26 (PDT)
 * Accept time: Wed 03 Jun 2020 @ 16:32 (PDT)
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
const int MX = 201;
int N, M, wei[MX], val[MX], tab[MX];

int main()
{
	scanf("%d%d", &M, &N);
	for (int i=0; i<N; ++i)
		scanf("%d%d", &wei[i], &val[i]);

	for (int i=0; i<N; ++i)
		for (int j=M; j>0; --j)
			if (j >= wei[i])
				tab[j] = max(tab[j], tab[j-wei[i]]+val[i]);

	printf("%d\n", tab[M]);

	return 0;
}

