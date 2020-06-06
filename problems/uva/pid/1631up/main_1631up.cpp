/*
TASK: 1631up
LANG: C++14
*/

/*
 * Problem 1631up (oj/pid/1631up)
 * Create time: Sun 12 Apr 2020 @ 09:29 (PDT)
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

void setIO(const std::string &name = "1631up");

using namespace std;
const int MX = 1111;
const int MAXROT = 3; // maximum numbers can rotate at a time

int N, tab[MX][1000];
char src[MX], dst[MX];

// min equals
inline int mineq(int &t, const int o)
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

int main()
{
    /*
    int _src, wid, dir;
    while (scanf("%d%d%d", &_src, &wid, &dir) == 3)
    {
	printf("=> %d\n", rotate(_src, wid, dir));
    }

    return 0;
    */

    while (scanf("%s%n%s\n", src, &N, dst))
    {
	FOR(i, N)
	{
	    src[i] -= '0';
	    dst[i] -= '0';
	}

	// TODO: basecase i=0
	int front = src[0]*10+src[1];
	FOR(dep2, 10)
	{
	    mineq(tab[0][rotate(front, 2,  dep2)], dep2);
	    mineq(tab[0][rotate(front, 2, -dep2)], dep2);
	    FOR(dep1, 10)
	    {
		mineq(tab[0][rotate(rotate(front, 2,  dep2), 1,  dep1)], dep2+dep1);
		mineq(tab[0][rotate(rotate(front, 2, -dep2), 1, -dep1)], dep2+dep1);
		mineq(tab[0][rotate(rotate(front, 2, -dep2), 1,  dep1)], dep2+dep1);
		mineq(tab[0][rotate(rotate(front, 2,  dep2), 1, -dep1)], dep2+dep1);
	    }
	}

	FOR_(i, 1, N)
	{
	    FOR(cur, (int)pow(10, MAXROT-1))
	    {
		int nxt = dst[i]*(int)pow(10, MAXROT-1) + cur/10; // where we are, from perspective of prev (i-1)
		FOR(width, MAXROT)
		{
		    tab[i][cur] = min(tab[i][cur], tab[i-1][rotate(nxt, width, -1)/10] +1); // TODO: last digit of cur isn't accounted for... this is straight up wrong
		    tab[i][cur] = min(tab[i][cur], tab[i-1][rotate(nxt, width,  1)/10] +1);
		}
	    }
	}
    }

    return 0;
}
/*
111111 222222
896521 183995
111111 222222
896521 183995
111111 222222
896521 183995
111111 222222
896521 183995
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
