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
list<int> in[MX];
list<int> out[MX];

int djs[MX], djf[MX];
int find(int n)
{
    if (djf[n] != n) djf[n] = find(djf[n]);
    return djf[n];
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (djs[a] < djs[b]) swap(a, b);
    djs[a] += djs[b];
    djf[b] = a;
}

int main()
{
    setIO();
    FOR(i, MX) djs[i] = 1; // FIX: init djs!
    iota(djf, djf+MX, 0);
    scanf("%d%d", &N, &M);
    FOR(i, M)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        out[a].pb(b);
        in[b].pb(a);
    }

    FOR_(i, 1, N+1)
    {
        int admirer = *(out[i].begin());
        for (auto it=next(out[i].begin()); it != out[i].end(); ++it)
        {
            int a = admirer, b=*it;
            // printf("out merge %d %d thru %d\n", a, b, i);
            if (a < b) swap(a, b); // merge into the larger index
            merge(a, b);
            out[a].splice(out[a].end(), out[b]);
        }

        admirer = *(in[i].begin());
        for (auto it=next(in[i].begin()); it != in[i].end(); ++it)
        {
            int a = admirer, b=*it;
            // printf("in merge %d %d thru %d\n", a, b, i);
            if (a < b) swap(a, b);
            merge(a, b);
            in[a].splice(in[a].end(), in[b]);
        }
    }

    // FOR_(i, 1, N+1)
    // {
    //     printf("(%2d) %d:", find(i), i);
    //     TRAV(n, out[i]) printf("%3d", n);
    //     printf(" : ");
    //     TRAV(n, in[i]) printf("%3d", n);
    //     printf("\n");
    // }

    int nextcolor=1;
    FOR_(i, 1, N+1)
    {
        if (color[find(i)]) continue;
        color[find(i)] = nextcolor;
        ++nextcolor;
    }

    FOR_(i, 1, N+1)
        printf("%d\n", color[find(i)]);

    return 0;
}

/*
5 4
2 1
3 2
3 4
4 5
=> 1 2 3 2 1
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
