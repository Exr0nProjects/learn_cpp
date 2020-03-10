/*
TASK: 3276down
LANG: C++14
*/

/*
 * Problem 3276down (xjoi.net/3276down)
 * Create time: Mon 09 Mar 2020 @ 19:04 (PDT)
 * Accept time: Mon 09 Mar 2020 @ 20:06 (PDT)
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

void setIO(const std::string &name = "3276down");

using namespace std;
const int MX = 1111;
int N, dp[MX], seq[MX];

int td(int i) // longest subseq up to (but not including) index i
{
    if (dp[i]) return dp[i];
    int ret=1;
    FOR(j, i) if (seq[j] < seq[i])
    {
        ret = max(ret, td(j) + 1);
    }
    dp[i] = ret;
    return ret;
}

int main()
{
    // setIO();
    scanf("%d", &N);
    FOR(i, N) scanf("%d", &seq[i]);

    int ret=0;
    FOR(i, N) ret = max(ret, td(i)); // this basically makes it bottom up, but this is a really jank dp anyways

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
