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
int N, K, size[MX];

// ll mem[MX][1000010][MX]; // MLE

map<pair<ll, pair<ll, ll> >, ll> mem; // FIX: mem type needs to be ll

ll op(ll i, ll s, ll c, int layer=0)
{
    if (mem.count(mp(i, mp(s, c)))) return mem[mp(i, mp(s, c))];
    // FOR(i, layer) printf("|   "); printf("i %d, s %d, c %d\n", i, s, c);
    if (i > N) // FIX: lt not le
    {
        return 0;
    }

    ll ret=(ll)1<<60;
    // FOR(i, layer) printf("|   "); printf("> %lld\n", ret);
    if (s >= size[i]) // if we can grab this group with this size
    {
        ret = min(ret, op(i+1, s, c, layer+1) + s-size[i]); // don't change
    }
    // FOR(i, layer) printf("|   "); printf("> %lld\n", ret);
    FOR_(j, i, N+1)
    {
        if (size[j] < size[i] || size[j] == s) continue; // new size must be atleast size of this group
        if (c > 0) // if we can afford the change
        {
            ret = min(ret, op(i+1, size[j], c-1, layer+1) + size[j] - size[i]);
        }
    // FOR(i, layer) printf("|   "); printf("|> %lld\n", ret);
    }
    // FOR(i, layer) printf("|   "); printf("=> %lld\n", ret);
    mem[mp(i, mp(s, c))] = ret;
    return ret;
}

int main()
{
    setIO();
    scanf("%d%d", &N, &K);
    FOR(i, N)
        scanf("%d", &size[i+1]); // one index groups, the zero is a dummy index

    printf("%lld\n", op(0, 0, K+1)); // K+1 to auto-select first size

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
    cin.tie(0); // fast cin/cout
    if (fopen((name + ".in").c_str(), "r") != nullptr)
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w+", stdout);
    }
}
