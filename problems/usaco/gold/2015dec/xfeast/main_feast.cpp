/*
TASK: feast
LANG: C++14
*/

/*
 * Problem feast (usaco/gold/2015dec/feast)
 * Create time: Thu 26 Mar 2020 @ 16:28 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
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
#include <iterator>
#include <exception>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define g(t, i) get<i>(t)
#define mt make_tuple

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

void setIO(const std::string &name = "feast");

using namespace std;
const int MX = 5000111;
int T, A, B, dp[MX];

int main()
{
    setIO();
    scanf("%d%d%d", &T, &A, &B);

    FOR_(i, 1, T+1) // FIX: go through T for when T == A && A == B
    {
        dp[i] = dp[i-1];
        if (i-A >= 0) dp[i] = max(dp[i], dp[i-A] + A);
        if (i-B >= 0) dp[i] = max(dp[i], dp[i-B] + B);
    }
    // printf("\n"); FOR(i, T) printf("%3d", dp[i]); printf("\n");

    int ret=0;
    FOR(k, T)
    {
        ret = max(ret, dp[k]); // FIX: allow not drinking at all
        ret = max(ret, dp[k]/2 + dp[T-dp[k]/2]);
    }

    printf("%d\n", ret);

    return 0;
}

void setIO(const string &name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // fast cin/cout
    if (fopen((name + ".in").c_str(), "r") != nullptr)
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w+", stdout);
    }
}
