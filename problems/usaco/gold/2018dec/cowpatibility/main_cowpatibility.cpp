/*
TASK: cowpatibility
LANG: C++14
*/

/*
 * Problem cowpatibility (usaco/gold/2018dec/cowpatibility)
 * Create time: Wed 25 Mar 2020 @ 18:04 (PDT)
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

void setIO(const std::string &name = "cowpatibility");

using namespace std;
const int MX = 50111;
ll N;
map<vector<int>, int> common[6];

void incSubsets(int fav[])
{
    // FOR(i, 6) printf("%3d", fav[i]); printf("\n");
    vector<int> sub;
    // for (int ii=0; ii<5; ++ii)
    // {
    //     printf("%3d", ii);
    // }
    // printf("\n");
    FOR_(s, 1, 32) // every subset
    {
        sub.clear();
        // FOR(i, 5)
        for (int ii=0; ii<5; ++ii)
        {
            if ((1<<ii) & s)
            {
                // printf("%3d", fav[ii]);
                sub.pb(fav[ii]);
            }
        }
        // TRAV(a, sub) if (a==0) printf("%3d", a); printf("\n");
        // bool wtf=0;
        // TRAV(a, sub) if (!a) wtf=1;
        // if (wtf) { FOR(i, 5) printf("%3d", fav[i]); printf("\n"); }
        ++common[sub.size()][sub];
    }
}

int main()
{
    setIO();
    scanf("%lld", &N);
    // printf("\n");
    ll tot=0;
    FOR(i, N)
    {
        int fav[6] = {};
        FOR(f, 5) // FIX: there are five flavors not four
        {
            // scanf("%d", &fav[f]);
            cin >> fav[f];
            // if (i == 49999) printf("%d ", fav[f]);
        }
        // if (!fav[4]) printf("wtf i: %d\n", i);
        sort(fav, fav+5);
        incSubsets(fav);
    }

    // FOR_(i, 1, 6)
    // {
    //     printf("============\nsize %d\n", i);
    //     TRAV(p, common[i])
    //     {
    //         printf("(");
    //         TRAV(a, p.F) printf("%3d", a);
    //         printf(") %d\n", p.S);
    //     }
    // }

    ll ret=0, include=1;
    FOR_(i, 0, 6)
    {
        TRAV(p, common[i])
            ret += include * (p.S*(p.S-1)/2); // add/subtract number of pairs
        include *= -1;
        // printf("%lld (%d)\n", ret, inc);
    }

    printf("%lld\n", N*(N-1)/2 - ret);

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
