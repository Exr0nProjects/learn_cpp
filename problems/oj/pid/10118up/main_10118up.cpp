/*
TASK: 10118up
LANG: C++14
*/

/*
 * Problem 10118up (oj/pid/10118up)
 * Create time: Sat 14 Mar 2020 @ 08:18 (PDT)
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

void setIO(const std::string &name = "10118up");

using namespace std;
const int MX = 51;
const int PILES = 4;
typedef array<int, PILES> State;
int N, piles[PILES+1][MX];
map<State, int> tab, basket;

int main()
{
    // setIO();
    while (scanf("%d", &N) == 1)
    {
        if (!N) break;
        memset(piles, 0, sizeof(piles));
        tab.clear();
        basket.clear();

        FOR(i, N) FOR(b, PILES) scanf("%d", &piles[b][i]);

        FOR(layer, N) FOR_(mod, 1, 1<<(PILES+1)) // `mod` starts at 1 because the previous iter of `layer` takes care of the zero case
        {
            State state;
            FOR(i, PILES) state[i] = layer + (bool)(mod & (1<<i));
            printf("    "); TRAV(n, state) printf("%3d", n); printf("\n");
        }
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
