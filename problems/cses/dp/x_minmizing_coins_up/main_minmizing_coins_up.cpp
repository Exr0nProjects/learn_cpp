/*
 * Problem minmizing_coins_up (cses/dp/minmizing_coins_up)
 * Create time: Mon 24 Aug 2020 @ 16:49 (PDT)
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

int N, X, v[110], dp[MX];

int main()
{
    scanf("%d%d", &N, &X);
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i=0; i<N; ++i) scanf("%d", v+i);
    for (int i=1; i<=X; ++i)
        for (int j=0; j<N; ++j)
            if (v[j] <= i)
                //dp[i] = 1+min(dp[i], dp[i-v[j]]);
                dp[i] = min(dp[i], dp[i-v[j]]+1);   // !!! FIX: can't do 1+min because that affects dp[i] for future iters of loop. You have to add one inside the min so that everything is uniform
    if (dp[X] > 1e6) printf("-1\n");    // FIX: output if impossible
    else printf("%d\n", dp[X]);

	return 0;
}

