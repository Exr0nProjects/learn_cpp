/*
TASK: 1347up
LANG: C++14
*/

/*
 * Problem 1347up (oj/pid/1347up)
 * Create time: Sat 18 Apr 2020 @ 13:19 (PDT)
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

void setIO(const std::string &name = "1347up");

using namespace std;
const int MX = -1;
int N;
dl sum=0, curx, cury, origx, origy;

int main()
{
    // TODO: i don't understand the problem
    while (scanf("%d", &N) == 1)
    {
	sum = 0;
	FOR(i, N)
	{
	    dl x, y;
	    scanf("%lf%lf", &x, &y);
	    if (i)
		sum += sqrt(pow(x-curx, 2) + pow(y-cury, 2));
	    else
	    {
		origx = x;
		origy = y;
	    }
	    curx = x;
	    cury = y;
	}
	printf("%.2lf", sum + sqrt(pow(curx-origx, 2) + pow(cury-origy, 2)));
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
