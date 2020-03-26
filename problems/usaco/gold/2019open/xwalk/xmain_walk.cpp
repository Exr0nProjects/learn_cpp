/*
TASK: walk
LANG: C++14
*/

/*
 * Problem walk (usaco/gold/2019open/walk)
 * Create time: Tue 24 Mar 2020 @ 17:22 (PDT)
 * Accept time: Wed 25 Mar 2020 @ 17:09 (PDT)
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

void setIO(const std::string &name = "walk");

using namespace std;
const int MX = 7511;
ll N, K, dist[MX];
bool vis[MX];

inline ll calcDist(ll i, ll j)
{
    return max(
            (2019201913LL*i+2019201949LL*j) % 2019201997LL,
            (2019201913LL*j+2019201949LL*i) % 2019201997LL); // FIX: order matters
}

int main()
{
    setIO();
    scanf("%lld%lld", &N, &K);

    // prim
    vector<ll> edges;
    FOR(i, N+1) dist[i] = (ll)1<<60; // FIX: one index everything because the dist relies on it
    FOR(i, N) // add a node to the tree N times
    {
        // get nearest node
        int idx = 0;
        FOR_(j, 1, N+1) if (!vis[i]) if (dist[idx] > dist[j]) idx = j;
        // add the node to the tree
        vis[idx] = 1;
        // update nearest node weights with new node
        FOR_(j, 1, N+1) if (!vis[j]) dist[j] = min(dist[j], calcDist(j, idx));
    }

    sort(dist+1, dist+N+1, greater<ll>{}); // FIX: sort needs to be one indexed too
    // FOR(i, N+1) printf("%20lld", dist[i]); printf("\n");

    printf("%lld\n", dist[K]);

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
