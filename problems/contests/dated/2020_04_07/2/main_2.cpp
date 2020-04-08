/*
TASK: 2
LANG: C++14
*/

/*
 * Problem 2 (contests/dated/2020_04_07/2)
 * Create time: Wed 08 Apr 2020 @ 07:53 (PDT)
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

void setIO(const std::string &name = "2");

using namespace std;
const int MX = 50111;
int N, pepl[MX];
list<int> head[MX];

int dist[MX];
pair<int, int> calcDist(int cur, int pre=-1, int stp=0)
{
    // FOR(i, stp) printf("|   "); printf("calc %d: %d (%d)\n", stp, cur, pre);
    dist[cur] = stp;
    pair<int, int> ret = {stp, cur}; // <dist, idx> of furthest
    TRAV(nxt, head[cur])
    {
	if (nxt == pre) continue;
	ret = max(ret, calcDist(nxt, cur, stp+1));
    }
    // FOR(i, stp) printf("|   "); printf("=> %d\n", ret.F);
    return ret;
}


int main()
{
    scanf("%d", &N);
    FOR(i, N) scanf("%d", &pepl[i+1]); // FIX: i+1 because it's one indexed
    FOR(i, N-1)
    {
	int u, v;
	scanf("%d%d", &u, &v);
	head[u].pb(v);
	head[v].pb(u);
    }

    int ret=0;
    int p, q; // diameter of tree
    p = calcDist(1).S;
    FOR_(i, 1, N+1) // first half of try all `pepl[x] * max(dist[x, y]) for all x`
	ret = max(ret, dist[i] * pepl[i]);
    q = calcDist(p).S;
    FOR_(i, 1, N+1) 
	ret = max(ret, dist[i] * pepl[i]);

    // FOR(i, N+1) printf("%3d", dist[i]); printf("\n");
    printf("diameter: %d - %d (dist %d)\n", p, q, dist[q]);

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
