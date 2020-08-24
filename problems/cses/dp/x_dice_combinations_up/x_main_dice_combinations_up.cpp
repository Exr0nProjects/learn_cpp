/*
 * Problem dice_combinations_up (cses/dp/dice_combinations_up)
 * Create time: Mon 24 Aug 2020 @ 16:37 (PDT)
 * Accept time: Mon 24 Aug 2020 @ 16:43 (PDT)
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

int N, dp[MX];  // dp[i] = # of ways to produce value i

int main()
{
    scanf("%d", &N);
    dp[0] = 1;  // FIX: base case
    for (int i=1; i<=N; ++i)
        for (int v=1; v<=6 && v <= i; ++v)  // FIX: condition--v <= i not v >= i
            dp[i] = (dp[i] + dp[i-v]) % (int)(1e9+7);
    printf("%d\n", dp[N]);

	return 0;
}

