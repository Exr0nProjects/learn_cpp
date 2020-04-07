/*
TASK: socdist
LANG: C++14
*/

/*
 * Problem socdist (usaco/silver/2020open/socdist)
 * Create time: Mon 06 Apr 2020 @ 16:06 (PDT)
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

void setIO(const std::string &name = "socdist");

using namespace std;
const int MX = 100111;
ll N, M;
vector<pair<ll, ll> > grass;

bool check(ll sep)
{
    ll pre=0, idx=0, tot=1;
    for (; tot<N; ++tot)
    {
	for (; pre+sep > grass[idx].S; ++idx) 	// increment grass_idx until we can place a cow
	    if (idx+1 >= grass.size()) 		// if this is the last grass patch
		return false;			// then we are out of patches, return false
	pre = max(pre+sep, grass[idx].F);
    }
    return true; 
}

int main()
{
    setIO();
    scanf("%lld%lld", &N, &M);
    grass.reserve(M);
    FOR(i, M)
    {
	ll a, b;
	scanf("%lld%lld", &a, &b);
	grass.eb(a, b);
    }
    sort(grass.begin(), grass.end());

    // bin search on D
    ll l=0, r=(ll)1<<60; // inc l exc r
    FOR(i, 61)
    {
	ll m = l/2 + r/2 + (l%2 & r%2);
	if (check(m))
	    l = m;
	else
	    r = m;
    }

    printf("%lld\n", l);

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
