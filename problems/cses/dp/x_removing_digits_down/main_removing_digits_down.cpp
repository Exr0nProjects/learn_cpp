/*
 * Problem removing_digits_down (cses/dp/removing_digits_down)
 * Create time: Sat 29 Aug 2020 @ 17:34 (PDT)
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

int kdp(int n)
{
    if (!n) return 0;
    int &ret = dp[n];
    if (ret) return ret;
    ret = 1e9;  // FIX: init--ret start at inf
    for (int j=n; j; j/=10)
        ret = min(ret, kdp(n-j%10)+1); // FIX: typo--call kdp instead of accessing dp array
    return ret;
}

int main()
{
    scanf("%d", &N);
    printf("%d\n", kdp(N));

	return 0;
}

