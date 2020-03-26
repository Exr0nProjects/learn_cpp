/*
TASK: teamwork
LANG: C++14
*/

/*
 * Problem teamwork (usaco/gold/2018dec/teamwork)
 * Create time: Wed 25 Mar 2020 @ 18:17 (PDT)
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

void setIO(const std::string &name = "teamwork");

using namespace std;
const int MX = 10111; // FIX: 10^4 not 10^3
int N, K, skill[MX];
int best[MX][MX], tab[MX];

int main()
{
    setIO();
    scanf("%d%d", &N, &K);
    FOR(i, N) scanf("%d", &skill[i]);

    FOR_(j, 1, N+1) FOR(i, j) // inc i, exc j
    {
        if (i+1 == j) best[i][j] = skill[i];
        else best[i][j] = max(best[i][j-1], skill[j-1]);
    }

    // FOR(i, N) { FOR(j, N) printf("%3d", best[i][j]); printf("\n"); }

    FOR(i, N+1)
        FOR_(k, 1, K+1)
        {
            if (i-k < 0) break;
            tab[i] = max(tab[i], tab[i-k]+(int)k*best[i-k][i]); // FIX: forgot to multiply
        }

    // FOR(i, N) printf("%3d", tab[i]); printf("\n");

    printf("%d\n", tab[N]);

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
