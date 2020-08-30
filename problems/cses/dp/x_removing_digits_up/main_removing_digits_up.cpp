/*
 * Problem removing_digits_up (cses/dp/removing_digits_up)
 * Create time: Sat 29 Aug 2020 @ 17:29 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
#include <vector>
#include <random>
#include <map>
#include <set>
#include <string>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <chrono>
#include <functional>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 1e6+11;

int N, dp[MX];

int main()
{
    scanf("%d", &N);

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i=1; i<=N; ++i)
        for (int j=i; j; j/=10)
            dp[i] = min(dp[i], dp[i-j%10]+1);
    printf("%d\n", dp[N]);

	return 0;
}

