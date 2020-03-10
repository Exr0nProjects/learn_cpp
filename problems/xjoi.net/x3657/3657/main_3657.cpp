/*
TASK: 3657
LANG: C++14
*/

/*
 * Problem 3657 (xjoi.net/3657)
 * Create time: Mon 09 Mar 2020 @ 17:34 (PDT)
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

void setIO(const std::string &name = "3657");

using namespace std;
const int MX = 111;
int N, triangle[MX][MX];

int recurse(int i, int j)
{
    if (i >= N || j >= N) return 0;
    return triangle[i][j] + max(recurse(i+1, j), recurse(i+1, j+1));
}

int main()
{
    //setIO();
    scanf("%d", &N);
    FOR(n, N) FOR(i, n+1)
    {
        scanf("%d", &triangle[n][i]);
    }
    //FOR(i, N) { FOR(j, N) printf("%3d", triangle[i][j]); printf("\n"); }

    printf("%d\n", recurse(0, 0));

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
