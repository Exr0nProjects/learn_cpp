/*
 * Problem guard (usaco/gold/2014dec/guard)
 * Create time: Sat 08 Aug 2020 @ 09:30 (PDT)
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
const ll MX = 20;
ll N, H, h[MX], w[MX], s[MX], mx=-1;
pair<ll, ll> dp[1<<MX];

pair<ll, ll> calc(int cows) // < saftey factor, weight >
{
    if (!cows) return mp(1ll<<50, 0ll);
    pair<ll, ll> &ret = dp[cows];
    if (ret.s) return ret;
    ll sum=0;
    for (int i=0; i<MX; ++i)
        if (cows & 1<<i)
        {
            sum += h[i];
            ret.s += w[i];
            pair<ll, ll> got = calc(cows^(1<<i));
            ret.f = max(ret.f, min(s[i]-got.s, got.f));
        }
    if (sum >= H) mx = max(mx, ret.f);
    return ret;
}

int main()
{
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w+", stdout);

    scanf("%lld%lld", &N, &H);
    for (int i=0; i<N; ++i)
        scanf("%lld%lld%lld", h+i, w+i, s+i);
    calc((1<<N)-1);
    if (mx <= 0) printf("Mark is too tall\n");  // FIX: mark is too tall if its le zero not just lt zero
    else printf("%lld\n", mx);

	return 0;
}

