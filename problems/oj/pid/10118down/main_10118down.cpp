/*
TASK: 10118down
LANG: C++14
*/

/*
 * Problem 10118down (oj/pid/10118down)
 * Create time: Fri 13 Mar 2020 @ 16:23 (PDT)
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

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define F first
#define S second
#define g(t, i) get<i>(t)
#define mt make_tuple
#define tup tuple

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

void setIO(const std::string &name = "10118down");

using namespace std;
const int MX = 51;
int N, baskets[5][MX];

tup<int, int> bestFrom(tup<int, int, int, int> state)
{
    if (g(state, 0)>=N && g(state, 1)>=N && g(state, 2)>=N && g(state, 3)>=N) return mt(0, 0);

    auto ret=mt(0, 0);
    FOR(i, 4) if (g(state, i)+1 <N) // for each pile if can take
    {
        ++g(state, i);
        auto from = bestFrom(state);
        ret = max(ret, mt(g(from, 0) + 2*(bool)(g(from, 1) & (1<<i)), g(from, 2) ^ (1<<i)));
        --g(state, i);
        printf("popcount: %d\n", __builtin_popcount(g(from, 1)));
    }
}

int main()
{
    setIO();
    while (scanf("%d", &N) == 1)
    {
        if (!N) break;
        FOR(i, N) FOR(b, 4) scanf("%d", &baskets[b][i]);
    }

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
