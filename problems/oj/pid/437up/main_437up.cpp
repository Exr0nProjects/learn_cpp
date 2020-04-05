/*
TASK: 437up
LANG: C++14
*/

/*
 * Problem 437up (oj/pid/437up)
 * Create time: Sun 05 Apr 2020 @ 12:48 (PDT)
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

void setIO(const std::string &name = "437up");

using namespace std;
const int MX = 3*31; // three ways to reorient
struct Block
{
    int l, r, h;
    Block(int l, int r, int h): l(l), r(r), h(h)
    {
	if (l > r) swap(l, r); // assert l <= r
    }
    bool operator< (const Block &o) const
    { return l < o.l && r < o.r; }
    bool operator> (const Block &o) const
    { return (o < *this); }
};
int N, tabl[MX];
vector<Block> blocks;

int main()
{
    setIO();
    while (scanf("%d", &N) == 1)
    {
	if (!N) break;
	memset(tabl, 0, sizeof(tabl));
	blocks.clear();
	blocks.reserve(MX);
	blocks.eb(1<<30, 1<<30, 0); // FIX: inf sized base

	FOR(i, N)
	{
	    int a, b, c;
	    scanf("%d%d%d", &a, &b, &c);
	    blocks.eb(a, b, c);
	    blocks.eb(a, c, b);
	    blocks.eb(b, c, a);
	}

	sort(blocks.begin(), blocks.end(), greater<Block>{});

	printf("blocks: %d\n", blocks.size()-1);
	
	// longest increasing sub
	int ret=0;
	FOR(i, blocks.size()) // FIX: not N, it should be 3*N (orientations) +1 (base)
	{
	    FOR(j, i) if (blocks[j] > blocks[i])
	    {
		tabl[i] = max(tabl[i], tabl[j] + blocks[i].h); 
	    }
	    ret = max(ret, tabl[i]);
	    printf("i %d, ret %d\n", i, ret);
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
