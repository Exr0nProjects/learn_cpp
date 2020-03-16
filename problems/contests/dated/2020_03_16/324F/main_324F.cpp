/*
TASK: 324F
LANG: C++14
*/

/*
 * Problem 324F (contests/dated/2020_03_16/324F)
 * Create time: Mon 16 Mar 2020 @ 14:11 (PDT)
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

void setIO(const std::string &name = "324F");

using namespace std;
const int MX = 211;
ll N, A, B, height[MX];
ll contact[MX]; // contact[i] = contact between board i and board i-1
ll total[MX]; // prefix sum over area
pair<ll, bool> tab[MX][MX]; // (pair<unattractiveness, whether this board is red>)tab[i][j] rep best looks by board i having used j red paint

pair<ll, bool> best(int i, int r)
{
    if (tab[i][r].F) return tab[i][r];
    pair<ll, bool> ret = {(ll)1<<60, true};
    if (i < 1 || r < 0) return ret;

    if (r <= A && total[i] - r <= B) ret = min(ret,
            make_pair(best(i-1, r).F + contact[i]*best(i-1, r).S, false ));

    if (r-height[i] <= A && total[i] - r+height[i] <= B) ret = min(ret,
            make_pair(best(i-height[i], r).F + contact[i]*best(i-1, r).S, false ));

    tab[i][r] = ret;
    return ret;
}

int main()
{
    FOR(i, MX) FOR(j, MX) tab[i][j].F = 1<<30;
    // setIO();
    scanf("%lld%lld%lld", &N, &A, &B);
    FOR(i, N) { scanf("%lld", &height[i]); total[i] = total[i-1] + height[i]; }
    FOR(i, N) contact[i+1] = min(height[i+1], height[i]);

    // tab[0][0] = {0, 0};
    // FOR_(i, 1, N+1)
    // {
    //     FOR_(j, 0, total_area)
    //     {
    //         // tab[i+1][j  ] = { tab[i][j].F + contact[i]*( tab[i][j].S), 0};
    //         // tab[i+1][j+height[i]] = { tab[i][j].F + contact[i]*(!tab[i][j].S), 1};
    //         if (j <= A && total_area-j <= B)
    //             tab[i][j] = min(tab[i][j],
    //                     make_pair( tab[i-1][j  ].F
    //                              + contact[i]*(bool)(tab[i-1][j  ].S), false ));

    //         if (j-1 <= A && total_area-j+1 <= B)
    //             tab[i][j] = min(tab[i][j],
    //                     make_pair( tab[i-1][j-height[i]].F
    //                              + contact[i]*!(bool)(tab[i-1][j-height[i]].S), true ));
    //     }
    // }

    // FOR(i, N+5) { FOR(j, total_area+10) if (tab[i][j].F < 1<<29) printf("%3lld", tab[i][j].F); else printf("  ."); printf("\n"); }

    // ll ret=(ll)1<<60;
    // FOR(j, total_area+1)
    //     if (j <= A && total[N-1] - j <= B)
    //     {
    //         printf("j: %d, tot-j: %d\n", j, total[N-1]-j);
    //         ret = min(ret, tab[N][j].F);
    //     }

    pair<ll, bool> ret = {(ll) 1<<60, true};
    FOR(i, N) ret = min(ret, best(N, total[i]));
    printf("%lld\n", ret.F);

    FOR(i, N+5) { FOR(j, total[N-1]+10) if (tab[i][j].F < 1<<29) printf("%3lld", tab[i][j].F); else printf("  ."); printf("\n"); }

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
