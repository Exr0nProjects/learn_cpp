/*
ID: spoytie2
TASK: 1395
LANG: C++14
*/

/*
 * Problem 1395 ([!meta:srcpath!])
 * Create time: Sun 23 Feb 2020 @ 20:34 (PST)
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
#define cn const int
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define MP make_pair
#define EB emplace_back
#define PB push_back
#define F first
#define S second
#define INF 0x7FFFFFFF

#define FOR_(i, b, e) for (int i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (int i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define SORT(a, n) std::sort((a), (a) + (n))
#define TRAV(a, x) for (auto &a : x)
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)
#define SORTV(v) std::sort((v).begin(), (v).end())

void setIO(const std::string &name = "1395");

using namespace std;
const int MX = 110;
int N, M;

int djs_f[MX];
int djs_s[MX];
int find(int n)
{
    //printf("finding father of %d\n", n);
    if (djs_f[n] != n)
    {
        djs_f[n] = find(djs_f[n]);
    }
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

int main()
{
    //setIO();


    while (scanf("%d%d", &N, &M) > 0)
    {
        if (!N && !M) break;

        vector<pair<int, pii> > edges;
        set<int> weights;


        FOR(i, M)
        {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            edges.emplace_back(w, MP(a, b));
            weights.insert(w);
        }

        // sort edges for kruskal
        sort(edges.begin(), edges.end());

        int ret = 1<<30;
        for (int mn=0; mn<edges.size(); ++mn)
        {
            // FIX: reset djs each time we build a new MST
            iota(djs_f, djs_f+MX, 0); // FIX: start iota at zero for index zero, even if everything else is one indexed
            FOR(i, N) djs_s[i] = 1;

            //printf("checking with w=%d\n", w);
            int cnt=1, e;
            for (e=mn; e < edges.size(); ++e)
            {
                //printf("edge endpoints = %d, %d with weight %d\n", edges[e].S.F, edges[e].S.S, edges[e].F);
                if (find(edges[e].S.F) == find(edges[e].S.S)) continue;
                //printf("merging groups %d (from %d) and %d (from %d), %d nodes total\n", find(e.S.S), e.S.S, find(e.S.F), e.S.F, cnt+1);
                ++cnt;
                merge(edges[e].S.S, edges[e].S.F);
                if (cnt == N) ret = min(ret, edges[e].F - edges[mn].F);
            }
        }
        printf("%d\n", ret == 1<<30 ? -1 : ret); // FIX: output -1
        //printf("%d\n", ret);
    }

    return 0;
}

/*
3 2
1 2 1
2 3 2
=> 1



4 5
1 2 3
1 3 5
1 4 6
2 4 6
3 4 7
4 6
1 2 10
1 3 100
1 4 90
2 3 20
2 4 80
3 4 40
2 1
1 2 1
3 0
3 1
1 2 1
3 3
1 2 2
2 3 5
1 3 6
5 10
1 2 110
1 3 120
1 4 130
1 5 120
2 3 110
2 4 120
2 5 130
3 4 120
3 5 110
4 5 120
5 10
1 2 9384
1 3 887
1 4 2778
1 5 6916
2 3 7794
2 4 8336
2 5 5387
3 4 493
3 5 6650
4 5 1422
5 8
1 2 1
2 3 100
3 4 100
4 5 100
1 5 50
2 5 50
3 5 50
4 1 150
0 0
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
