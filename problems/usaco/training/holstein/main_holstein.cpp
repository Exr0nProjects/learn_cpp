/*
TASK: holstein
LANG: C++14
*/

/*
 * Problem holstein (usaco/training/holstein)
 * Create time: Wed 26 Feb 2020 @ 19:49 (PST)
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

void setIO(const std::string &name = "holstein");

using namespace std;
const int MX = 30;
int V, G;
int required[MX];
int value[MX][MX];

pii dfs(int idx, int feeds=0)
{
    FOR(i, idx) printf("    ");
    printf("dfs %d: feeds=...", idx);
    FOR(i, G) if (feeds & 1<<20-i) printf(" %d", i);
    printf("\n");


    if (idx == G)
    {
        int nutrition[MX] = {};
        int cnt=0;
        FOR(i, G)
        {
            if (feeds & 1<<20-i)
            {
                FOR(v, V) nutrition[v] += value[i][v];
                ++cnt;
            }
        }

        FOR(i, V)
            if (nutrition[i] < required[i]) return MP(1<<30, 0);
        return MP(feeds, cnt);
    }
    return min(dfs(idx+1, feeds), dfs(idx+1, feeds | 1<<20-idx));
}

int main()
{
    setIO();
    scanf("%d", &V);
    FOR(i, V) scanf("%d", &required[i]);
    scanf("%d", &G);
    FOR(i, G) FOR(j, V) scanf("%d", &value[i][j]);

    pii ans = min(dfs(0), dfs(0, 1));
    printf("%d", ans.S);
    FOR(i, G)
    {
        if (ans.F & 1<<20-i) printf(" %d", i);
    }
    printf("\n");

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
