/*
TASK: walk
LANG: C++14
*/

/*
 * Problem walk (usaco/gold/2019open/walk)
 * Create time: Tue 24 Mar 2020 @ 17:22 (PDT)
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

void setIO(const std::string &name = "walk");

using namespace std;
const int MX = 7511;
ll N, K, dist[MX][MX];
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

    FOR_(i, 1, N+1) FOR_(j, 1, N+1) dist[i][j] = calcDist(i, j);

    // prim
    vector<ll> edges;
    priority_queue<pair<ll, ll>, deque<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    pq.push(mp(0, 1));
    while (!pq.empty())
    {
        pair<ll, ll> next = pq.top();
        pq.pop();

        edges.pb(next.F);
        vis[next.S] = 1;

        FOR_(i, 1, N+1)
            if (!vis[i])
                pq.push(mp(calcDist(next.S, i), i));
    }

    sort(edges.begin(), edges.end());
    // TRAV(e, edges) printf("%11d", e); printf("\n");

    printf("%d\n", edges[N-K+1]);
    // printf("%lld\n", r);

    // FOR(i, 10)
    // {
    //     ll mdst;
    //     scanf("%lld", &mdst);
    //     printf("%d\n", check(mdst));
    // }

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
