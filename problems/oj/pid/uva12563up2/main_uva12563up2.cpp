/*
 * Problem uva12563up2 (uva12563up2)
 * Create time: Wed 03 Jun 2020 @ 15:57 (PDT)
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
const int MX = 61;
const int MXT = 20111;
int N, T, dura[MX];
pair<int, int> tab[MXT];

pair<int, int> inc(pair<int, int> src, int dura)
{
	++src.f;
	src.s += dura;
	return src;
}

int main()
{
	int kase; scanf("%d", &kase);
	for (int kk=0; kk<kase; ++kk)
	{
		//memset(tab, 0, sizeof tab);
		for (int i=0; i<MXT; ++i) tab[i] = {0, 0};
		memset(dura, 0, sizeof dura);
		scanf("%d%d", &N, &T);
		for (int i=1; i<=N; ++i) scanf("%d", &dura[i]);

		--T;

		//for (int i=1; i<=N; ++i)
		//{
		//    for (int j=0; j<T; ++j)
		//    {
		//        dp[i][j] = dp[i-1][j];
		//        if (j >= dura[i])
		//            dp[i][j] = max(dp[i][j], dp[i-1][j-dura[i]] + 1);
		//        printf("%3d", dp[i][j]);
		//    }
		//    printf("\n");
		//}
		//printf("\n\n");

		for (int i=1; i<=N; ++i)
		{
			for (int j=T; j>0; --j)
			{
				if (j >= dura[i])
					tab[j] = max(tab[j], inc(tab[j-dura[i]], dura[i]));
				printf("    (%2d %2d)", tab[j]);
			}
			printf("\n");
		}
		//tab[T] = inc({0, 0}, 60);
		printf("%d %d\n", tab[T].f, tab[T].s);
	}

	return 0;
}

