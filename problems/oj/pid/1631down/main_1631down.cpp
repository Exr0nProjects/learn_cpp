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

#define FOR_(i, b, e) for (int i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (int i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

void setIO(const std::string &name = "1631down");

using namespace std;
const int MX = 1111;
const int MAXROT = 3;

typedef array<int, MAXROT> State;

int N, tab[MX][1000];
string src, dst;

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

inline int dist(int s, int d)
{ return (d-s +10) % 10; }

int match(const State &s, const State &d, int dir=1)
{
    dir = 2*(bool)dir-1;
    int ret = -1 * (1<<30);
    // FOR(i, MAXROT)
	// printf("    %d\n", (dir * dist(s[i], d[i]) + 10) % 10);
    FOR(i, MAXROT)
	ret = max(ret, (dir * dist(s[i], d[i]) + 10) % 10);
    return ret;
}

int op(int idx, int nxt, int lay=0)
{
    if (tab[idx][nxt]) return tab[idx][nxt];
    // FOR(i, lay) printf("|   "); printf("%d (%d)\n", idx, nxt);

    int ret = 1<<30;

    State d = { dst[idx], nxt/10, nxt%10 };
    if (idx == 0)
    {
	State s{ src[0], src[1], src[2] }; // could be cleaner w/ for loop
	if (idx == 0 && nxt == 11)
	{
	    printf("s:"); FOR(i, MAXROT) printf("%3d", s[i]); printf("\n");
	    printf("d:"); FOR(i, MAXROT) printf("%3d", d[i]); printf("\n");
	}

	ret = min(match(s, d, 0), match(s, d, 1));
    }
    else
    {
	FOR(pre, (int)pow(10, MAXROT-1))
	{
	    State s{ pre/10, pre%10, src[idx] };
	    const int minrot = min(match(s, d, 0), match(s, d, 1));
	    ret = min(ret, op(idx-1, pre, lay+1) + minrot);
	}
    }

    // FOR(i, lay) printf("|   "); printf("=> %d\n", ret);
    tab[idx][nxt] = ret;
    return ret;
}

int main()
{
    while (cin >> src >> dst)
    {
	N = src.length();
	cout << src << " " << dst << " " << N << endl;

	FOR(i, N)
	{
	    src[i] -= '0';
	    dst[i] -= '0';
	}

	// State s, d;
	// copy(src, src+MAXROT, s.begin());
	// copy(dst, dst+MAXROT, d.begin());
	// FOR(i, MAXROT) printf(" %d", s[i]); printf("  ");
	// FOR(i, MAXROT) printf(" %d", d[i]); printf("\n");
	// printf("distance %d\n", min(match(s, d, 1), match(s, d, 0)));
	// continue;
	
	printf("=> %d\n", op(N-1, 0));

	// int ret=1<<30;
	// FOR(i, (int)pow(10, MAXROT-1))
	// {
	//     ret = min(ret, op(N, i));
	// }
	// printf("%d\n", ret);
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
