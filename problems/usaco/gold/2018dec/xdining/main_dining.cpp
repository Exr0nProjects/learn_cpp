/*
TASK: dining
LANG: C++14
*/

/*
 * Problem dining (usaco/gold/2018dec/dining)
 * Create time: Thu 26 Mar 2020 @ 08:34 (PDT)
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

void setIO(const std::string &name = "dining");

using namespace std;
const int MX = 50111;
int N, M, K;

list<pair<int, int> > head[MX];

void djikstra(int src, map<int, int> &dist)
{
    set<pair<int, int> > pq;
    pq.insert(mp(0, src));
    while (!pq.empty())
    {
        pair<int, int> top = *pq.begin();
        pq.erase(pq.begin());
        if (dist[top.S] && dist[top.S] < top.F) continue;

        dist[top.S] = top.F;

        TRAV(n, head[top.S])
        {
            if (!dist[n.S] || top.F + n.F < dist[n.S])
                pq.insert(mp(top.F + n.F, n.S));
        }
    }
    dist[src] = 0;
}

int main()
{
    setIO();
    scanf("%d%d%d", &N, &M, &K);
    FOR(i, M)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        head[u-1].pb(mp(w, v-1));
        head[v-1].pb(mp(w, u-1));
    }

    map<int, int> og_dist;
    djikstra(N-1, og_dist);

    // TRAV(p, og_dist) printf("%d: %d\n", p.F, p.S);
    // return 0;

    FOR(i, K)
    {
        int v, w;
        scanf("%d%d", &v, &w);
        w = og_dist[v-1] - w;
        head[N].pb(mp(w, v-1));
    }

    map<int, int> hay_dist;
    djikstra(N, hay_dist); // replace barn (n-1) with barn through hay (n)

    FOR(i, N-1) printf("%d\n", hay_dist[i] <= og_dist[i]);

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
