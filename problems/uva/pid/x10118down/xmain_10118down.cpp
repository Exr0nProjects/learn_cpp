/*
TASK: 10118down
LANG: C++14
*/

/*
 * Problem 10118down (oj/pid/10118down)
 * Create time: Fri 13 Mar 2020 @ 16:23 (PDT)
 * Accept time: Fri 13 Mar 2020 @ 20:51 (PDT)
 *
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
#include <array>
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

#define pb push_back
#define eb emplace_back
#define mp make_pair
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
int N, piles[5][MX], basket=0;
map<array<int, 4>, int> mem;

int bestFrom(array<int, 4> state) // returns pair<score, bucket>
{
    if (mem.count(state)) return mem[state];

    int ret=0;
    if (__builtin_popcount(basket) >= 5) return ret; // if we can't add anything then just give up
    FOR(i, 4) if (state[i] <N) // for each pile if can take; FIX: state[i] just has to be <N (not state[i]+1) because state[i] is the next one to take
    {
        int candy = (1<<piles[i][state[i]]);

        basket ^= candy; // add candy to basket
        ++state[i]; // update the pile index array
        int from = bestFrom(state);
        --state[i]; // undo for backtracking
        basket ^= candy;

        if (basket & candy) // if basket already had one of this color
            ret = max(ret, from +1);
        else                // basket didn't have this color
            ret = max(ret, from);
    }

    mem[state] = ret;
    // TRAV(a, state) printf("%3d", a); printf(" -> %d\n", ret);
    return ret;
}

int main()
{
    setIO();
    while (scanf("%d", &N) == 1)
    {
        if (!N) break;
        FOR(i, 5) FOR(j, MX) piles[i][j] = 0;
        mem.clear();
        FOR(i, N) FOR(b, 4) scanf("%d", &piles[b][i]);
        printf("%d\n", bestFrom(array<int, 4>{0, 0, 0, 0}));
    }

    return 0;
}

/*
5
1 2 3 4
1 5 6 7
2 3 3 3
4 9 8 6
8 7 2 1
1
1 2 3 4
3
1 2 3 4
5 6 7 8
1 2 3 4
9
1 2 3 4
4 5 3 6
1 6 5 2
1 2 3 4
5 6 7 7
8 1 1 2
4 2 3 3
3 4 5 6
8 2 8 1
0
*/

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
