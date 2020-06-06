/*
TASK: 1001
LANG: C++14
*/

/*
 * Problem 1001 (oj/pid/1001)
 * Create time: Sun 19 Apr 2020 @ 12:45 (PDT)
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

void setIO(const std::string &name = "1001");

using namespace std;
const int MX = 111;
int N, x[MX], y[MX], z[MX], r[MX];
dl dist[MX];
dl tween(int u, int v)
{
    return max((dl)0, sqrt(pow(x[u]-x[v], 2) + pow(y[u]-y[v], 2) + pow(z[u]-z[v], 2)) - r[u] - r[v]) * 10;
}

int main()
{
    for (int kase=1;; ++kase)
    {
	scanf("%d", &N);
	if (N < 0) break;
	memset(x, 0, sizeof x);
	memset(y, 0, sizeof y);
	memset(z, 0, sizeof z);
	memset(r, 0, sizeof r);
	FOR(n, N+2)	// the Nth entry is the destination, N+1th is source
	{
	    scanf("%d%d%d", &x[n], &y[n], &z[n]);
	    if (n < N)
		scanf("%d", &r[n]);
	}

	/*
	for(;;)
	{
	    int u, v;
	    scanf("%d%d", &u, &v);
	    printf("%lf\n", tween(u, v));
	}
	*/
    
	FOR(i, N+1) dist[i] = 1<<30;	// FIX: init dist
	priority_queue<pair<dl, int>, deque<pair<dl, int> >, greater<pair<dl, int> > > pq; // <time, id>
	pq.emplace(0, N+1);
	while (!pq.empty())
	{
	    pair<dl, int> cur = pq.top(); pq.pop();
	    // printf("at node %d (%d %d %d) after %lf\n", cur.S, x[cur.S], y[cur.S], z[cur.S], cur.F);
	    if (dist[cur.S] < cur.F) continue;

	    if (cur.S == N)
	    {
		printf("Cheese %d: Travel time = %.0lf sec\n", kase, cur.F);
		break;
	    }

	    FOR(i, N+1)
	    {
		if (i != cur.S && dist[i] > cur.F + tween(cur.S, i))
		{
		    dist[i] = cur.F + tween(cur.S, i);
		    pq.emplace(dist[i], i);
		}
	    }
	}
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
