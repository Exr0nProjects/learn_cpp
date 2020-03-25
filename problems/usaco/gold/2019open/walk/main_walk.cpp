/*
TASK: walk
LANG: C++14
*/

/*
 * Problem walk (usaco/gold/2019open/walk)
 * Create time: Tue 24 Mar 2020 @ 17:22 (PDT)
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

void setIO(const std::string &name = "walk");

using namespace std;
const int MX = 7511;
ll N, K;

inline ll dist(ll i, ll j)
{
    // return (2019201913*i%2019201997+2019201949*j%2019201997) % 2019201997;
    return (2019201913*i+2019201949*j) % 2019201997;
}

ll djf[MX], djs[MX];
ll find(ll n)
{
    if (djf[n] != n) djf[n] = find(djf[n]);
    return djf[n];
}
void merge(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (djs[a] < djs[b]) swap(a, b);
    djs[a] += djs[b];
    djf[b] = a;
}

bool check(ll mindist)
{
    iota(djf, djf+MX, 0);
    FOR(i, MX) djs[i] = 1;
    ll groups = N;

    FOR_(i, 1, N+1) FOR_(j, 1, i) // FIX: one index
    {
        // printf("checking %d against %d\n", i, j);
        if (dist(i, j) < mindist && find(i) != find(j))
        {
            merge(i, j);
            --groups;
        }
    }

    return K < groups;
}

int main()
{
    setIO();
    scanf("%lld%lld", &N, &K);

    FOR(i, N) FOR(j, N) printf("%d %d: %lld\n", i, j, dist(i, j));

    ll l=0, r=(ll)1<<40;
    FOR(i, 45)
    {
        // ll m = l/2 + r/2 + (l%2&r%2);
        ll m = (l+r)/2;
        if (check(m)) l=m;
        else r=m;
    }

    printf("%lld %lld\n", l, r);

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
