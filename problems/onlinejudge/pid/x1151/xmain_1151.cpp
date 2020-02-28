/*
TASK: 1151
LANG: C++14
*/

/*
 * Problem 1151 (onlinejudge/pid/1151)
 * Create time: Thu 27 Feb 2020 @ 17:50 (PST)
 * Accept time: Thu 27 Feb 2020 @ 19:44 (PST)
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

#define MP make_pair
#define PB push_back
#define EB emplace_back
#define F first
#define S second

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

void setIO(const std::string &name = "1151");

using namespace std;
const int MX = 1010;
vi posx, posy;
vector<pair<int, pii> > edges, mst;

int N, Q;
vi networks[10];
int network_cost[10];

int djs_f[MX];
int djs_s[MX];
int find(int n)
{
    if (djs_f[n] != n) djs_f[n] = find(djs_f[n]);
    return djs_f[n];
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (djs_s[a] < djs_s[b]) swap(a, b);
    djs_s[a] += djs_s[b];
    djs_f[b] = a;
}

void debug_djs()
{
    return;
    map<int, set<int> > belongs;
    for (int i=0; i<MX; ++i)
    {
      if (find(i) != i) belongs[find(i)].insert(i);
    }
    for (auto &p : belongs)
    {
      printf("    %d (size %d):", p.first, djs_s[find(p.first)]);
      for (auto &n : p.second)
      {
        printf("%3d", n);
      }
      printf("\n");
    }
}

int dfs(int city_idx=0, int chosen=0)
{
    if (city_idx == Q)
    {
        //printf("checking with cities");
        //FOR(i, 10) if (chosen & 1 << i) printf("%3d", i);
        //printf("\n");


        // reset djs
        iota(djs_f, djs_f+MX, 0);
        FOR(i, MX) djs_s[i] = 1;
        djs_s[MX-1] = 0; // FIX: this one doesn't count as a city

        int cost=0;
        // add the existing networks
        FOR(i, 10) if (chosen & 1 << i)
        {
            cost += network_cost[i];
            TRAV(c, networks[i])
            {
                merge(c, MX-1);
            }
        }
        TRAV(e, mst)
        {
            if (find(e.S.F) == find(e.S.S)) continue;
            merge(e.S.F, MX-1); // FIX: need to combine with "final" node manually too, not just in the existing networks
            merge(e.S.S, MX-1);
            cost += e.F;
            if (djs_s[find(MX-1)] >= N) break;
        }
        //printf("    cost = %d, found all? %d >= %d\n\n", cost, djs_s[find(MX-1)], N);
        debug_djs();
        if (djs_s[find(MX-1)] >= N) return cost;
        return 1<<30;
    }

    return min(dfs(city_idx+1, chosen), dfs(city_idx+1, chosen | 1<<city_idx));
}

int main()
{
    setIO();
    int kases;
    scanf("%d", &kases);
    FOR(kase, kases)
    {
        // input
        scanf("%d%d", &N, &Q);
        FOR(q, Q)
        {
            int n;
            scanf("%d%d", &n, &network_cost[q]);
            FOR(i, n)
            {
                int city;
                scanf("%d", &city);
                networks[q].PB(city-1);
            }
        }
        FOR(n, N)
        {
            int tx, ty;
            scanf("%d%d", &tx, &ty);
            FOR(o, posx.size())
            {
                edges.EB((int) sqrt(pow(abs(tx-posx[o]), 2) + pow(abs(ty-posy[o]), 2)), MP(n, o));
            }
            posx.PB(tx);
            posy.PB(ty);
        }

        // first MST
        sort(edges.begin(), edges.end());
        int cnt=0, cost=0;
        iota(djs_f, djs_f+MX, 0);
        FOR(i, MX) djs_s[i] = 1;
        TRAV(e, edges)
        {
            if (find(e.S.F) == find(e.S.S)) continue;
            merge(e.S.F, e.S.S);
            mst.PB(e);
            ++cnt;
            cost += e.F;
            if (cnt >= N) break;
        }
        sort(mst.begin(), mst.end());
        //printf("first mst found (%d):\n", cost);
        //TRAV(e, mst) printf("%d %d\n", e.S.F, e.S.S);

        printf("%d\n\n", dfs());
    }

    return 0;
}

/*
1
3 1
2 1 1 2
0 0
0 4
0 8
=> 5

1
3 1
2 10 1 2
0 0
0 4
0 8
=> 8

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
