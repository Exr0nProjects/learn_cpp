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
map<vector<int>, int> common[6]; // FIX: this doesn't need to be ll, but then i would have to cast it later

void incSubsets(int fav[])
{
    vector<int> sub;
    sub.reserve(6);
    FOR_(s, 1, 32) // every subset
    {
        sub.clear();
        for (int ii=0; ii<5; ++ii)
            if ((1<<ii) & s)
                sub.pb(fav[ii]);
        ++common[__builtin_popcount(s)][sub]; // FIX: use popcount instead of size() to fix TLE
    }
}

int main()
{
    setIO();
    scanf("%lld", &N);
    ll tot=0;
    FOR(i, N)
    {
        int fav[5] = {};
        FOR(f, 5) // FIX: there are five flavors not four
            scanf("%d", &fav[f]); // FIX: can't just cin into an array
        sort(fav, fav+5);
        incSubsets(fav);
    }

    ll ret=0, include=1;
    FOR_(i, 1, 6)
    {
        TRAV(p, common[i])
            ret += include * ((ll)p.S*((ll)p.S-1LL)/2LL); // add/subtract number of pairs
        include *= -1;
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
