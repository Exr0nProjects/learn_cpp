/*
TASK: 1218down
LANG: C++14
*/

/*
 * Problem 1218down (oj/pid/1218down)
 * Create time: Sat 28 Mar 2020 @ 09:07 (PDT)
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

void setIO(const std::string &name = "1218down");

using namespace std;
const int MX = 10111;
int N;
list<int> adj[MX];

int op(int src, int pre=0)
{
    int cost=0, ggcost=0;

    TRAV(child, adj[src]) if (child != pre)
    {
        cost += op(child, src);

        TRAV(gchild, adj[child]) if (gchild != src)
            TRAV(ggchild, adj[gchild]) if (ggchild != child)
                ggcost += op(ggchild, gchild);
    }

    int ret = 1 + min(cost, ggcost);
    return ret;
}

int main()
{
    setIO();
    while (scanf("%d", &N) == 1)
    {
        FOR(i, MX) adj[i].clear();

        FOR(i, N-1)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].pb(v);
            adj[v].pb(u);
        }

        // find a leaf
        int leaf=0;
        FOR_(i, 1, N+1)
            if (adj[i].size() == 1)
            {
                leaf = i;
                break;
            }

        printf("%d\n", min(op(leaf), op(*adj[leaf].begin())));

        scanf("%d", &N);
        if (N < 0) break;
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
