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
    setIO();
    while (scanf("%d%d", &N, &M) > 0)
    {
        vector<pair<int, pii> > edges;
        set<int> weights;

        iota(djs_f, djs_f+N, 1);
        FOR(i, N) djs_s[i] = 1;

        FOR(i, M)
        {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            edges.emplace_back(w, MP(a, b));
            weights.insert(w);
        }

        int ret = 1<<30;
        TRAV(w, weights)
        {
            sort(edges.begin(), edges.end(), [&](pair<int, pii> l, pair<int, pii> r){ return abs(l.F-w) < abs(r.F-w); });
            int cnt=1, wmin=1<<30, wmax=0;
            TRAV(e, edges)
            {
                if (find(e.S.F) == find(e.S.S)) continue;
                ++cnt;
                merge(e.S.S, e.S.F);
                wmin = min(wmin, e.F);
                wmax = max(wmax, e.F);
                if (cnt == N) break;
            }
            if (cnt < N) {ret = -1; break;}
            ret = min(ret, wmax-wmin);
        }
        printf("%d\n", ret);
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
