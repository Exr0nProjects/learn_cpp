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
const int MX = 31;
struct Block
{
    int l, w, h;
    Block(int l, int w, int h): l(l), w(w), h(h)
    { if (l > w) swap(l, w); /* l <= w */ }
};
vector<Block> blocks;
int N, tab[MX];

int longestPath(int i)
{
    if (tab[i]) return tab[i];
    FOR(j, blocks.size())
	if (blocks[j].l > blocks[i].l && blocks[j].w > blocks[i].w)
	    tab[i] = max(tab[i], longestPath(j) + blocks[i].h);
    return tab[i];
}
    

int main()
{
    while (scanf("%d", &N) == 1)
    {
	if (!N) break;
	printf("n %d\n", N);
	blocks.clear();
	blocks.reserve(3*N);
	memset(tab, 0, sizeof tab);

	blocks.eb(1<<30, 1<<30, 0); // big base

	FOR(i, N)
	{
	    int a, b, c;
	    scanf("%d%d%d", &a, &b, &c);
	    blocks.eb(a, b, c);
	    blocks.eb(a, c, b);
	    blocks.eb(b, c, a);
	}

	int ret=0;
	FOR(i, blocks.size())
	    ret = max(ret, longestPath(i));

	FOR(i, blocks.size())
	{
	    printf("block (%d %d) h %d max %d\n", blocks[i].l, blocks[i].w, blocks[i].h, tab[i]);
	}

	printf("%d\n", ret);
    }

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
