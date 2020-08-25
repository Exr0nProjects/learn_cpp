/*
 * Problem coin_combinations_ii_down (cses/dp/coin_combinations_ii_down)
 * Create time: Mon 24 Aug 2020 @ 18:00 (PDT)
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

int N, X, v[110], dp[110][MX];
int kdp(int i, int x, int lay=1)
{
    if (x == 0) { dp[i][x] = 1; return 1; }
    if (i == 0) { dp[i][x] = 0; return 0; }
    int &ret = dp[i][x];
    if (ret) return ret;
    ret = kdp(i-1, x, lay+1);   // FIX: logic--simulate += in rolling array carrying over
    if (v[i] <= x)  // FIX: no need to loop over j, just check cuz recursion already does it
        ret = (ret + kdp(i, x-v[i], lay+1)) % (int)(1e9+7);  // FIX: its top down dp, so call kdp instead of accessing dp array
    return ret;
}

int main()
{
    scanf("%d%d", &N, &X);
    for (int i=1; i<=N; ++i) scanf("%d", v+i);
    printf("%d\n", kdp(N, X));

	return 0;
}

