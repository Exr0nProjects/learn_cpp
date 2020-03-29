/*
TASK: fcolor
LANG: C++14
*/

/*
 * Problem fcolor (usaco/gold/2020open/fcolor)
 * Create time: Sun 29 Mar 2020 @ 10:04 (PDT)
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

void setIO(const std::string &name = "fcolor");

using namespace std;
const int MX = 200111;
int N, M, admired[MX], color[MX];
set<int> shared[MX];

int main()
{
    setIO();
    scanf("%d%d", &N, &M);
    FOR(i, M)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        shared[a].insert(b);
        admired[b] = a;
    }
    FOR_(i, 1, N+1) printf("%d: %d\n", i, admired[i]);

    int nextcolor = 1;
    FOR_(i, 1, N+1)
    {
        // printf("i: %d, colo[i]: %d\n", i, color[i]);
        if (color[i]) continue;
        color[i] = nextcolor; // FIX: incase this cow doesn't admire anybody
        TRAV(c, shared[admired[i]])
        {
            // printf("assigning %d colo %d\n", c, nextcolor);
            color[c] = nextcolor; // FIX: assign color[c], not color[i]
        }
        ++nextcolor;
    }

    FOR_(i, 1, N+1)
        printf("%d\n", color[i]);

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
