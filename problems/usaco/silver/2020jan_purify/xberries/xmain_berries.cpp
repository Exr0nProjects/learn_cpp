/*
ID: spoytie2
TASK: berries
LANG: C++14
*/

/*
 * Problem berries ([!meta:srcpath!])
 * Create time: Sun 23 Feb 2020 @ 09:37 (PST)
 * Accept time: Sun 23 Feb 2020 @ 09:55 (PST)
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

#define cn const int
#define ll long long
#define cl const long long
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define MP make_pair
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

void setIO(const std::string &name = "berries");

using namespace std;
const int MX = 1010;
int N, K, trees[MX];

int simulate(cn x)
{
    int full=0;
    FOR(i, N)
    {
        full += trees[i]/x;
    }
    if (full >= K) return x*K/2;
    sort(trees, trees+N, [&](cn l, cn r){ return (l%x) > (r%x); }); // FIX: l and r are values, not indicies
    //FOR(i, N) printf("%3d", trees[i]%x); printf("\n");
    int ret=(full-K/2)*x;
    FOR(i, K-full)
    {
        ret += trees[i]%x;
    }
    return ret;
}
int main()
{
    setIO();
    scanf("%d%d", &N, &K);
    FOR(i, N)
    {
        scanf("%d", &trees[i]);
    }

    int ret=0;
    FOR(i, MX-10)
    {
        ret = max(ret, simulate(i+1));
    }

    printf("%d\n", ret);

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
