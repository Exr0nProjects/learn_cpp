/*
TASK: 1631down
LANG: C++14
*/

/*
 * Problem 1631down (oj/pid/1631down)
 * Create time: Sun 12 Apr 2020 @ 11:21 (PDT)
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

void setIO(const std::string &name = "1631down");

using namespace std;
const int MX = 1111;
const int MAXROT = 3;

int N, tab[MX][1000];
char src[MX], dst[MX];


inline int mineq(int &t, const int o) // min equals
{ return t = min(t, o); }

inline int rotate(int src, int width, int dir) // rotate the first `width` tumblers in `src` by `dir`
{
    dir = (dir+100)%10;

    int ret = src;
    FOR_(i, MAXROT-1-width, MAXROT-1)
    {
	if (src % (int)pow(10, i+1) / (int)pow(10, i) + dir >= 10)
	    ret -= (10-dir) * pow(10, i);
	else
	    ret +=     dir  * pow(10, i);
    }
    return ret;
}

int op(int idx, int nxt)
{
    if (tab[idx][nxt]) return tab[idx][nxt];
    int ret = 1<<30;
    FOR_(wid, 1, MAXROT+1)
    {
	// TODO: what to put here that's not hella scuffed??
    }
}

int main()
{
    while (scanf("%s%n%s\n", src, &N, dst))
    {
	FOR(i, N)
	{
	    src[i] -= '0';
	    dst[i] -= '0';
	}

	int ret=1<<30;
	FOR(i, (int)pow(10, MAXROT-1))
	{
	    mineq(ret, op(N, i));
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