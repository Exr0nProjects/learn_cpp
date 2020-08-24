/*
 * Problem dice_combinations_down (cses/dp/dice_combinations_down)
 * Create time: Mon 24 Aug 2020 @ 16:44 (PDT)
 * Accept time: Mon 24 Aug 2020 @ 16:48 (PDT)
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

int N, dp[MX];
int kdp(int i)
{
    if (!i) return 1;
    int &ret = dp[i];
    if (ret) return ret;
    for (int v=1; v<=6 && v <= i; ++v)
        ret = (ret + kdp(i-v)) % (int)(1e9+7);  // FIX: forgot mod
    return ret;
}

int main()
{
    scanf("%d", &N);
    printf("%d\n", kdp(N));

	return 0;
}

