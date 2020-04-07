/*
TASK: moop
LANG: C++14
*/

/*
 * Problem moop (usaco/silver/2020open/moop)
 * Create time: Mon 06 Apr 2020 @ 16:25 (PDT)
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

void setIO(const std::string &name = "moop");

using namespace std;
const int MX = 100111;
int N;
vector<pair<ll, ll> > locs;

// djs
int djs[MX], djf[MX], groups=N;
int find(int n)
{
    if (djf[n] != n) djf[n] = find(djf[n]);
    return djf[n];
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    --groups;
    if (djs[a] < djs[b]) swap(a, b);
    djs[a] += djs[b];
    djf[b] = a;
}

// util
bool canInteract(int id, ll x, ll y)
{
    // printf("%d . %d; %d . %d\n", locs[id].F, x, locs[id].S, y);
    // printf("(%d %d) (%d %d)\n", locs[id].F, locs[id].S, x, y);
    return (locs[id].F <= x && locs[id].S <= y) || (locs[id].F >= x && locs[id].S >= y);
}

int main()
{
    setIO();

    // FIX: init djs!!!!
    FOR(i, MX) djs[i] = 1;
    iota(djf, djf+MX, 0);

    scanf("%d", &N);
    groups = N; // FIX: set groups to N *after* N is set
    locs.reserve(N);
    FOR(i, N)
    {
	ll a, b;
	scanf("%lld%lld", &a, &b);
	FOR(j, i)
	    if (canInteract(j, a, b))
		merge(i, j);
	locs.eb(a, b);
    }

    printf("%lld\n", groups);


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
