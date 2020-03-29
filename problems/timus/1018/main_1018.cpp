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
ll N, Q, knapsack[MX][MX][MX]; // knapsack[root][child_id][remaining_capacity]
vector<ll> head[MX]; // edge = pair<w, v>
ll value[MX][MX]; // value of branch that holds `i`

ll op(ll root, ll prev, ll idx, const ll rem, int layer=0) // best value with root = `root`, need to leave `rem` and pruning from `idx` and onwards
{
    FOR(i, layer) printf("|   "); printf("root %d, prev %d, idx %d, rem %d\n", root, prev, idx, rem);
    if (rem <= 0) return 0;
    if (idx >= head[root].size())
    {
        FOR(i, layer) printf("|   "); printf("=> %d\n", value[prev][root]);
        return value[prev][root];
    }
    if (root[head][idx] == prev) return op(root, prev, idx+1, rem, layer); // skip the previous
    ll ret=0;

     // if this is the absolute root (root == prev), then the parent branch doesn't exist so we don't subtract its cost
    FOR(k, rem-(1*(prev!=root))) // rem-1 because one of the rem is used to keep the branch between prev and root
    {
        ret = max(ret, op(root, prev, idx+1, rem-k, layer+1) + op(head[root][idx], root, 0, k, layer+1));
        FOR(i, layer) printf("|   "); printf("======== %d\n", ret);
    }
    FOR(i, layer) printf("|   "); printf("=> %d\n", ret + value[prev][root]);
    return ret + value[prev][root];
}

ll op2(ll root, ll prev, ll keep)
{
    if (head[root].size() == 1) return 0; // leaf node
    // jankily get children
    vector<int> child;
    TRAV(n, head[root]) if (n != prev) child.pb(n);

    int ret=0;
    FOR(k, keep+1)
    {
        ret = max(ret, op2(child[0], k) + op2(child[1], k) + value[prev][root]);
    }
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
    FOR(i, N+1) { FOR(j, N+1) printf("%3d", value[i][j]); printf("\n"); };

    printf("%lld\n", op(1, 1, 0, Q+1));

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
