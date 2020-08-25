/*
 * Problem coin_combinations_i_down (cses/dp/coin_combinations_i_down)
 * Create time: Mon 24 Aug 2020 @ 17:52 (PDT)
 * Accept time: Mon 24 Aug 2020 @ 17:56 (PDT)
 * TLE :/
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
int kdp(int x)
{
    if (x == 0) return 1;
    int &ret = dp[x];
    if (ret) return ret;
    for (int i=0; i<N; ++i)
        if (v[i] <= x)
            ret = (ret + kdp(x-v[i])) % (int)(1e9+7);
    return ret;
}

int main()
{
    scanf("%d%d", &N, &X);
    for (int i=0; i<N; ++i) scanf("%d", v+i);
    printf("%d\n", kdp(X));

	return 0;
}

