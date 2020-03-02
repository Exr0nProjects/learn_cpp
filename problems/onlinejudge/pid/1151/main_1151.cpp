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

using namespace std;
const int MX = 10010;
vector<int> posx, posy;
vector<pair<int, pair<int, int> > > edges, mst;

int N, Q;
vector<int> networks[10];
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
        for (int i=0; i<indent; ++i) printf("    ");
        printf("%d (size %d):", p.first, djs_s[find(p.first)]);
        for (auto &n : p.second)
        {
            printf("%3d", n);
        }
        printf("\n");
    }
}

long long MST(int groups, const vector<pair<int, pair<int, int> > > &edges, vector<pair<int, pair<int, int> > > &mst)
{
    // FIX: don't reset MST because we might start in the middle
    int cost=0;
    for (auto &p : edges)
    {
        if (find(p.second.first) == find(p.second.second)) continue;
        merge(p.second.first, p.second.second);
        cost += p.first;
        mst.push_back(p);
        --groups;
        if (groups == 1) break;
    }
    printf("    MST ended, cost = %d\n", cost);
    if (groups == 1) return cost;
    return -1;
}

long long solve()
{
    long long ret=(long long)1<<60;
    for (int chosen=0; chosen<1<<Q; ++chosen)
    {
        //printf("checking with cities");
        //FOR(i, 10) if (chosen & 1 << i) printf("%3d", i);
        //printf("\n");


        // reset djs
        iota(djs_f, djs_f+N+5, 0);
        for (int i=0; i<N+5; ++i) djs_s[i] = 1;

        int cost=0, groups=N;
        // add the existing networks
        for (int i=0; i<10; ++i) if (chosen & 1<<i)
        {
            cost += network_cost[i];
            for (auto &c : networks[i])
            {
                if (find(c) != find(networks[i][0])) --groups;
                merge(c, networks[i][0]);
            }
        }
        printf("\n    added networks, cost is %d\n", cost);
        debug_djs(3);
        sort(edges.begin(), edges.end());
        iota(djs_f, djs_f+N+5, 0);
        vector<pair<int, pair<int, int> > > dummy;
        ret = min(ret, (long long)cost + MST(groups, mst, dummy));
    }
    return ret;
}

int main()
{
    int kases;
    scanf("%d", &kases);
    for (int kase=0; kase<kases; ++kase)
    {
        posx.clear();
        posy.clear();
        edges.clear();
        mst.clear();
        // input
        scanf("%d%d", &N, &Q);
        for (int q=0; q<Q; ++q)
        {
            int n;
            scanf("%d%d", &n, &network_cost[q]);
            networks[q].clear();
            for (int i=0; i<n; ++i)
            {
                int city;
                scanf("%d", &city);
                networks[q].push_back(city-1);
            }
        }
        for (int n=0; n<N; ++n)
        {
            int tx, ty;
            scanf("%d%d", &tx, &ty);
            for (int o=0; o<posx.size(); ++o)
            {
                edges.emplace_back((int) pow(tx-posx[o], 2) + (int) pow(ty-posy[o], 2), make_pair(n, o));
            }
            posx.push_back(tx);
            posy.push_back(ty);
        }

        // first MST
        sort(edges.begin(), edges.end());
        iota(djs_f, djs_f+N+5, 0);
        for (int i=0; i<N+5; ++i) djs_s[i] = 1;
        MST(N, edges, mst);
        sort(mst.begin(), mst.end());

        if (kase) printf("\n");
        printf("%lld\n", solve());
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

1
7 3
2 4 1 2
3 3 3 6 7
3 9 2 4 5
0 3000
2999 0
2 0
0 1
1 2
99 97
4 4
=> 21

*/
