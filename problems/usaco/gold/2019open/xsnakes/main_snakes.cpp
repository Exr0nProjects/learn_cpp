/*
TASK: snakes
LANG: C++14
*/

/*
 * Problem snakes (usaco/gold/2019open/snakes)
 * Create time: Tue 24 Mar 2020 @ 16:18 (PDT)
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

void setIO(const std::string &name = "snakes");

using namespace std;
const int MX = 411;
ll N, K, size[MX];

ll tab[MX][MX]; // MLE

int main()
{
    setIO();
    scanf("%d%d", &N, &K);

    ll tot=0, premax=0;
    // dp
    FOR_(n, 1, N+1)
    {
        scanf("%d", &size[n]); // one index groups, the zero is a dummy index
        tot += size[n];
        premax = max(premax, size[n]);
        tab[n][0] = n * premax;
        FOR_(k, 1, K+1)
        {
            ll mx=size[n];
            tab[n][k] = (ll) 1<<60;
            FORR(i, n)
            // for (int i=n-1; i>=0; --i)
            {
                tab[n][k] = min(tab[n][k], tab[i][k-1]+(n-i)*mx);
                mx = max(mx, size[i]);
            }
        }
    }

    // FOR(n, N+1) { FOR(k, K+1) printf("%5d", tab[n][k]); printf("\n"); }

    printf("%lld\n", tab[N][K] - tot);

    return 0;
}

/*
2 1 3 5
=> 0

2 0 3 5
=> 2
*/

void setIO(const string &name)
{
    ios_base::sync_with_stdio(0);
    // cin.tie(0); // fast cin/cout
    if (fopen((name + ".in").c_str(), "r") != nullptr)
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w+", stdout);
    }
}
