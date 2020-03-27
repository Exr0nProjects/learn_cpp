/*
TASK: closing
LANG: C++14
*/

/*
 * Problem closing (usaco/gold/2016open/closing)
 * Create time: Fri 27 Mar 2020 @ 11:37 (PDT)
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

void setIO(const std::string &name = "closing");

using namespace std;
const int MX = 200111;
int N, M, closings[MX];
list<int> head[MX];


int djf[MX], djs[MX];
int find(int n)
{
    if (djf[djf[n]] != djf[n]) djf[n] = find(djf[n]);
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
    scanf("%d%d", &N, &M);
    FOR(i, M)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        head[u].pb(v);
        head[v].pb(u);
    }

    FORR(i, N) // input it backwards
        scanf("%d", &closings[i]);

    iota(djf, djf+MX, 0);
    FOR(i, MX) djs[i] = 1;

    bool res[MX] = {}, vis[MX] = {};
    int components = 0;

    FOR(i, N)
    {
        ++components;
        vis[closings[i]] = 1; // FIX: vis, only merge two barns if both are open
        TRAV(v, head[closings[i]])
        {
            if (vis[v] && find(closings[i]) != find(v))
            {
                // printf("merging %d %d\n", closings[i], v);
                --components;
                merge(closings[i], v);
            }
        }

        // printf("size: %d    >= %d;      comps %d\n", djs[find(closings[i])], i+1, components);
        // res[i] = djs[find(closings[i])] >= i+1;
        res[i] = components <= 1;
    }

    FORR(i, N) if (res[i]) printf("YES\n"); else printf("NO\n");

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
