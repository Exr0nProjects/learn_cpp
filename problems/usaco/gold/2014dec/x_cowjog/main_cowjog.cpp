/*
 * Problem cowjog (usaco/gold/2014dec/cowjog)
 * Create time: Sat 08 Aug 2020 @ 09:53 (PDT)
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
const ll MX = 100111;
ll N, T, len=0, lis[MX];

int main()
{
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w+", stdout);
    scanf("%lld%lld", &N, &T);
    for (ll i=0; i<N; ++i)
    {
        ll x, v; scanf("%lld%lld", &x, &v); // FIX: bounds--ll smah
        x += T*v;
        if (!len || lis[len-1] >= x) lis[len++] = x;    // FIX: need `!len ||` else won't ever add first one
        else *upper_bound(lis, lis+len, x, greater<ll>{}) = x;  // FIX: typo--end is lis+len not lis+N
    }
    printf("%lld\n", len);  // FIX: bounds-- remember to convert ll format strings smah
	return 0;
}

