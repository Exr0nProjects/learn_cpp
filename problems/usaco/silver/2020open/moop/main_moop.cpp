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

int main()
{
    setIO();
    scanf("%d", &N);
    locs.reserve(N);
    FOR(i, N)
    {
	ll a, b;
	scanf("%lld%lld", &a, &b);
	locs.eb(a, b);
    }

    sort(locs.begin(), locs.end());
    TRAV(p, locs) printf("(%d %d) ", p.F, p.S); printf("\n");
    ll active = -1 * (ll) 1<<50;
    ll count = 0;
    FORR(i, N)
    {
	if (locs[i].S <= active) continue; // ignore particles that would be interacted
	printf("new immune particle %d: (%d %d)\n", i, locs[i].F, locs[i].S);
	active = locs[i].S;
	++count;
    }

    printf("%lld\n", count);


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
