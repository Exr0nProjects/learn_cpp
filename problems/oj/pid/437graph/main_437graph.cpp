/*
TASK: 437graph
LANG: C++14
*/

/*
 * Problem 437graph (oj/pid/437graph)
 * Create time: Sat 18 Apr 2020 @ 11:59 (PDT)
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

void setIO(const std::string &name = "437graph");

using namespace std;
const int MX = 3*31;
typedef pair<pair<ll, ll>, ll> Block;
vector<Block> blocks;
int N;
ll tab[MX];
int pre[MX];

ll longestPath(int i)
{
    if (tab[i]) return tab[i];
    for (int j=0; j<blocks.size(); ++j)
	if (blocks[j].F.F > blocks[i].F.F && blocks[j].F.S > blocks[i].F.S)
	    if (longestPath(j) + blocks[i].S > tab[i])
	    {
		tab[i] = longestPath(j) + blocks[i].S;
		pre[i] = j;
	    }
    return tab[i];
}
    
int main()
{
    int kase=0;
    while (scanf("%d", &N) == 1)
    {
	if (!N) break;

	blocks.clear();
	blocks.reserve(3*N+10);
	memset(tab, 0, sizeof tab);

	blocks.eb(mp(1<<30, 1<<30), 0); // big base

	FOR(i, N)
	{
	    int a, b, c;
	    scanf("%d%d%d", &a, &b, &c);
	    blocks.eb(mp(a, b), c);
	    blocks.eb(mp(a, c), b);
	    blocks.eb(mp(b, a), c);
	    blocks.eb(mp(b, c), a); // FIX: need to try all combos
	    blocks.eb(mp(c, a), b);
	    blocks.eb(mp(c, b), a);
	}

	ll ret=0;
	FOR(i, blocks.size())
	    ret = max(ret, longestPath(i));

	// printf("\n");
	FOR(i, blocks.size())
	{
	    // printf("%2d <- %2d tot %15lld (%11lld %11lld %11lld)\n", i, pre[i], longestPath(i), blocks[i].F.F, blocks[i].F.S, blocks[i].S);
	}

	printf("Case %d: maximum height = %lld\n", ++kase, ret);
    }

    return 0;
}

/*
differing test case:
2
900000000 100000000 300000000
500000000 600000000 1000000000
mine 24...
ans  19...

24 should work, (6 10) (5 6) (1 3)
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
