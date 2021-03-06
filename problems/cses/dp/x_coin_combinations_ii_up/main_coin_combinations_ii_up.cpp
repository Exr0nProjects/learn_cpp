/*
 * Problem coin_combinations_ii_up (cses/dp/coin_combinations_ii_up)
 * Create time: Mon 24 Aug 2020 @ 17:57 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
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
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 1e6+10;

int N, X, v[MX], dp[MX];

int main()
{
    scanf("%d%d", &N, &X);
    for (int i=0; i<N; ++i) scanf("%d", v+i);
    dp[0] = 1;
    for (int j=0; j<N; ++j)
        for (int i=1; i<=X; ++i)
            if (v[j] <= i)
                dp[i] = (dp[i] + dp[i-v[j]]) % (int)(1e9+7);
    printf("%d\n", dp[X]);

	return 0;
}

