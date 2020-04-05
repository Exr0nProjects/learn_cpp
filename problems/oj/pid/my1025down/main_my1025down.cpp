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
int N, T, M1, M2, dist[MX], memo[MX][MX];

inline int getDist(int a, int b)
{ return dist[max(a, b)] - dist[min(a, b)]; }

int op(int i, int t, int lay=0)
{
    FOR(i, lay) printf("|   "); printf("op %d %d\n", i, t);
    if (memo[i][t] < 1<<30) return memo[i][t];
    if (t <= 0) return 1<<30;

    int ret=1<<30;
    // from trains
    if (i) ret = min(ret, op(i-1, t-dist[i-1], lay+1));
    if (i < N-1) ret = min(ret, op(i+1, t-dist[i], lay+1));
    // waited at this station
    ret = min(ret, op(i, t-1, lay+1));

    FOR(i, lay) printf("|   "); printf("=> %d\n", ret);
    memo[i][t] = ret;
    return ret;
}

int main()
{
    // setIO();
    freopen("test.in", "r", stdin);
    int kase=0;
    while (scanf("%d%d", &N, &T) == 2)
    {
	if (!N) break;
	memset(dist, 0, sizeof(dist));
	memset(memo, 0x40, sizeof(memo));
	
	// input
	FOR(i, N-1)
	{
	    scanf("%d", &dist[i]);
	    if (i) dist[i] += dist[i-1];
	}
	scanf("%d", &M1);
	FOR(i, M1)
	{
	    int dep;
	    scanf("%d", &dep);
	    memo[0][dep] = dep;
	}
	scanf("%d", &M2);
	FOR(i, M2)
	{
	    int dep;
	    scanf("%d", &dep);
	    memo[N-1][dep] = dep;
	}

	// top down
	int ret = 1<<30;
	FOR(t, T+1) // FIX: T+1 because we can get there at time T also
	    ret = min(ret, op(N-1, t));

	// output
	printf("Case Number %d: ", ++kase);
	if (ret < 1<<30)
	    printf("%d\n", ret);
	else
	    printf("impossible\n");
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
