/*
TASK: my1025down
LANG: C++14
*/

/*
 * Problem my1025down (oj/pid/my1025down)
 * Create time: Sun 05 Apr 2020 @ 10:13 (PDT)
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

void setIO(const std::string &name = "my1025down");

using namespace std;
const int MX = 61;
int N, T, memo[MX][MX];
int dist[MX], pref[MX]; // pref[i] (prefix dist)= time to get from first station to [i]
set<int> first, last; // train departures

int op(const int i, const int t, int lay=0) // N^2 log N
{
    // FOR(i, lay) printf("|   "); printf("op %d %d\n", i, t);
    // if (memo[i][t] < 1<<30) return memo[i][t];
    if (!i && !t) return 0; // FIX: start
    if (t <= 0) return 1<<30;

    int ret=1<<30;
    // from trains
    if (i && first.count(t-pref[i])) // not at first station && exists a train from first station : arrives here now
	ret = min(ret, op(i-1, t-dist[i], lay+1));
    if (i < N-1 && last.count(t-pref[N-1]+pref[i])) // not at last station && exists train from last : arrives here now
	// FIX: need the `t-` ^^
	ret = min(ret, op(i+1, t-dist[i+1], lay+1));
    // waited at this station
    ret = min(ret, op(i, t-1, lay+1)+1); // FIX: +1 to cost because we waited

    // FOR(i, lay) printf("|   "); printf("=> %d\n", ret);
    memo[i][t] = ret;
    return ret;
}

int main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w+", stdout);
    int kase=0;
    while (scanf("%d%d", &N, &T) == 2)
    {
	if (!N) break;
	memset(dist, 0, sizeof(dist));
	memset(memo, 0x40, sizeof(memo));
	first.clear();
	last.clear();
	
	// input
	FOR_(i, 1, N)
	{
	    scanf("%d", &dist[i]);
	    pref[i] = dist[i] + pref[i-1];
	}
	int m, dep;
	scanf("%d", &m);
	FOR(i, m)
	{
	    scanf("%d", &dep);
	    first.insert(dep);
	}
	scanf("%d", &m);
	FOR(i, m)
	{
	    scanf("%d", &dep);
	    last.insert(dep);
	}

	// top down
	int ret = op(N-1, T);

	++kase;
	// output
	printf("Case Number %d: ", kase);
	if (ret < 1<<30)
	    printf("%d\n", ret);
	else
	    printf("impossible\n");
    }

    return 0;
}

/*
6
26
1 2 3 4 5
2
0 10
2
0 15

3
40
6 4
3
0 20 28
2
10 30

0

12 200
1 5 5 6 7 8 9 10 11 13 19
12
1 26 36 71 88 90 91 97 99 143 147 171
15
1 38 62 68 83 88 129 130 133 134 139 141 168 178 190
0
=> 16















// total dist: sum to 94
12 200
1 5 5 6 7 8 9 10 11 13 19
11
1 26 36 71 88 90 97 99 143 147 171
15
1 38 62 68 83 88 129 130 133 134 139 141 168 178 190
0
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
