/*
TASK: 1151
LANG: C++14
*/

/*
 * Problem 1151 (onlinejudge/pid/1151)
 * Create time: Thu 27 Feb 2020 @ 17:50 (PST)
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

using namespace std;
const int MX = 10010;
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

void debug_djs(int indent=1)
{
    return;
    map<int, set<int> > belongs;
    for (int i=0; i<N; ++i)
    {
        if (find(i) != i) belongs[find(i)].insert(i);
    }
    for (auto &p : belongs)
    {
        FOR(i, indent) printf("    ");
        printf("%d (size %d):", p.first, djs_s[find(p.first)]);
        for (auto &n : p.second)
        {
            printf("%3d", n);
        }
        printf("\n");
    }
}

int MST(int groups, const vector<pair<int, pii> > &edges, vector<pair<int, pii> > &mst)
{
    // reset djs
    iota(djs_f, djs_f+N+5, 0);
    FOR(i, N+5) djs_s[i] = 1;

    int cost=0;
    TRAV(p, edges)
    {
        if (find(p.S.F) == find(p.S.S)) continue;
        merge(p.S.F, p.S.S);
        cost += p.F;
        mst.PB(p);
        --groups;
        if (groups == 1) break;
    }
    //printf("    MST ended, cost = %d\n", cost);
    if (groups == 1) return cost;
    return -1;
}

int solve()
{
    int ret=1<<30;
    FOR(chosen, 1<<Q)
    {
        //printf("checking with cities");
        //FOR(i, 10) if (chosen & 1 << i) printf("%3d", i);
        //printf("\n");


        // reset djs
        iota(djs_f, djs_f+N+5, 0);
        FOR(i, N+5) djs_s[i] = 1;

        int cost=0, groups=N;
        // add the existing networks
        FOR(i, 10) if (chosen & 1 << i)
        {
            cost += network_cost[i];
            TRAV(c, networks[i])
            {
                if (find(c) != find(networks[i][0])) --groups;
                merge(c, networks[i][0]);
            }
        }
        //printf("    added networks, cost is %d\n", cost);
        debug_djs(3);
        vector<pair<int, pii> > dummy;
        ret = min(ret, cost + MST(groups, mst, dummy));
    }
    return ret;
}

int main()
{
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
                edges.EB((int) pow(abs(tx-posx[o]), 2) + pow(abs(ty-posy[o]), 2), MP(n, o));
            }
            posx.PB(tx);
            posy.PB(ty);
        }

        // first MST
        sort(edges.begin(), edges.end());
        iota(djs_f, djs_f+N+5, 0);
        FOR(i, N+5) djs_s[i] = 1;
        MST(N, edges, mst);
        sort(mst.begin(), mst.end());

        if (kase) printf("\n");
        printf("%d\n", solve());
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
=> 17

1
3 1
2 200 1 2
0 0
0 4
0 8
=> 32

// provided sample
1
7 3
2 4 1 2
3 3 3 6 7
3 9 2 4 5
0 2
4 0
2 0
4 2
1 3
0 5
4 4
=> 17

*/
