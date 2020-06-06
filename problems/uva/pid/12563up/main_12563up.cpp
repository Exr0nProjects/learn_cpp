/*
 * Problem 12563up (oj/pid/12563up)
 * Create time: Wed 03 Jun 2020 @ 12:11 (PDT)
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
const int MX = 51;
const int MXT = 20111;	// 50 * 180
ll kase, N, T, len=0, tab[MX][MXT], dura[MX];
vector<ll> best;

int main()
{
	scanf("%lld", &kase);
	for (int kek=0; kek<kase; ++kek)
	{
		scanf("%lld%lld", &N, &T);
		memset(tab, 0, sizeof tab);
		best.clear();

		for (int i=1; i<=N; ++i)
			scanf("%lld", &dura[i]);
		
		printf("mkay %lld %lld\n", N, T);

		//for (int i=0; i<T; ++i)
			//if (i > dura[0])
				//tab[0][i] = 1;

		for (int i=1; i<=N; ++i)
			for (int j=0; j<T; ++j)
			{
				tab[i][j] = tab[i-1][j];
				if (j > dura[i])
					tab[i][j] = max(tab[i][j], tab[i-1][j-dura[i]]+1);

				if (tab[i][j] > len)
				{
					len = tab[i][j];
					best.clear();
				}
				if (tab[i][j] == len)
					best.pb(j);
			}
		sort(best.begin(), best.end(), greater<ll>{});
		for (int i=0; i<best.size(); ++i) printf("%3d", best[i]); printf("\n");
		printf("Case %d: %lld %lld\n", kek+1, len+1, best[0]+678);
	}


	return 0;
}

