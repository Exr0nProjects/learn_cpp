/*
TASK: 1018
LANG: C++14
*/

/*
 * Problem 1018 (timus/1018)
 * Create time: Sun 22 Mar 2020 @ 18:16 (PDT)
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

void setIO(const std::string &name = "1018");

using namespace std;
const int MX = 111;
ll N, Q; // knapsack[root][child_id][remaining_capacity]
vector<ll> head[MX]; // edge = pair<w, v>
ll value[MX][MX]; // value of branch that holds `i`
ll tab[MX][MX];

ll op2(ll root, ll prev, ll keep, ll layer=0) // most from subtree rooted at `root` including branch holding `root` keeping `keep` branches total
{
    // FOR(i, layer) printf("|   "); printf("op %d -> %d, keep %d\n", root, prev, keep);
    if (tab[root][keep]) return tab[root][keep];

    if (keep <= 0) return 0;
    if (root != 1 && head[root].size() == 1) return value[prev][root]; // leaf node; FIX: account for the apples on a leaf branch
    // jankily get children
    vector<int> child;
    TRAV(n, head[root]) if (n != prev) child.pb(n);

    ll ret=0;
    if (child.size() == 2)
    {
	FOR(k, keep)
	{
	    // if (k) printf("\n");
	    ret = max(ret, op2(child[0], root, k, layer+1) + op2(child[1], root, keep-k-1, layer+1));
	}
    }
    else
    {
	ret = op2(child[0], root, keep-1, layer+1);
    }
    ret += value[prev][root];
    // FOR(i, layer) printf("|   "); printf("=> %d\n", ret);
    tab[root][keep] = ret;
    return ret;
}

int main()
{
    // setIO();
    scanf("%lld%lld", &N, &Q);
    FOR(i, N-1)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        head[u].emplace_back(v);
        head[v].emplace_back(u);
        value[u][v] = value[v][u] = w;
    }
    // FOR(i, N+1) { FOR(j, N+1) printf("%3d", value[i][j]); printf("\n"); };

    printf("%lld\n", op2(1, 1, Q+1));

    return 0;
}

/*
2 1
1 2 4
=> 4
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
