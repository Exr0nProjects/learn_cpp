/*
TASK: 3276up
LANG: C++14
*/

/*
 * Problem 3276up (xjoi.net/3276up)
 * Create time: Mon 09 Mar 2020 @ 20:06 (PDT)
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
#include <exception>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define MP make_pair
#define PB push_back
#define EB emplace_back
#define F first
#define S second

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

void setIO(const std::string &name = "3276up");

using namespace std;
const int MX = 1111;
int N, seq[MX], dp[MX];

int main()
{
    // setIO();
    scanf("%d", &N);
    FOR(i, N) scanf("%d", &seq[i]);

    int ret=0;
    FOR(i, N)
    {
        FOR(j, i)
            if (seq[j] < seq[i])
                dp[i] = max(dp[i], dp[j] +1);
        ret = max(ret, dp[i]);
    }

    printf("%d\n", ret+1);

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
