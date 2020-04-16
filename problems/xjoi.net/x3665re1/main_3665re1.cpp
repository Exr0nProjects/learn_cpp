/*
TASK: 3665re1
LANG: C++14
*/

/*
 * Problem 3665re1 (xjoi.net/3665re1)
 * Create time: Wed 15 Apr 2020 @ 17:04 (PDT)
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

void setIO(const std::string &name = "3665re1");

using namespace std;
const int MX = 211;
int N, K, dp[MX][MX]; // dp[i][j] = most value by item i with remaining weight j
int valu[MX], mass[MX];

int main()
{
    scanf("%d%d", &K, &N);
    FOR_(i, 1, N+1)
	scanf("%d%d", &mass[i], &valu[i]);

    FOR_(i, 1, N+1)
    {
	FOR_(j, 1, K+1)	// FIX: everything is one indexed!
	{
	    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);
	    if (j >= mass[i])
		dp[i][j] = max(dp[i][j], dp[i-1][j-mass[i]]+valu[i]);
	}
    }

    printf("%d\n", dp[N][K]);

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
