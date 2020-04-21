/*
TASK: 12661
LANG: C++14
*/

/*
 * Problem 12661 (oj/pid/12661)
 * Create time: Mon 20 Apr 2020 @ 12:41 (PDT)
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

void setIO(const std::string &name = "12661");

using namespace std;
const int MX = 311;
int N, M, S, T;
struct Edge
{
    int u, v, w, a, b;
    Edge(int u, int v, int w, int a, int b): u(u), v(v), w(w), a(a), b(b) {}
};
list<Edge> head[MX];
int dist[MX];

int main()
{
    int kase=0;
    while (scanf("%d%d%d%d", &N, &M, &S, &T) == 4)
    {
	FOR(i, MX) head[i].clear();
	memset(dist, 0x40, sizeof dist);

	FOR(i, M)
	{
	    int u, v, w, a, b;
	    scanf("%d%d%d%d%d", &u, &v, &a, &b, &w);
	    head[u].eb(u, v, w, a, b);
	}

	FOR(i, N)
	{
	    printf("head %d:\n", i);
	    TRAV(e, head[i])
		printf("%d -%d-> %d (%d %d)\n", e.u, e.w, e.v, e.a, e.b);
	}

	printf("\nS %d -> T %d\n\n", S, T);

	priority_queue<pair<int, int>, deque<pair<int, int> >, greater<pair<int, int> > > pq;	// <time, node>
	pq.emplace(0, S);
	while (!pq.empty())
	{
	    pair<int, int> cur = pq.top(); pq.pop();
	    printf("at %d after %d\n", cur.S, cur.F);
	    if (cur.S == T)
	    {
		printf("Case %d: %d\n", ++kase, cur.F);
		break;
	    }

	    if (dist[cur.S] < cur.F) continue;
	    dist[cur.S] = cur.F;

	    TRAV(e, head[cur.S])
	    {
		const int enter = cur.F % (e.a + e.b);
		const int exit = (cur.F + e.w) % (e.a + e.b);
		if (enter <= e.a && exit <= e.a && enter / (e.a + e.b) == exit / (e.a + e.b))
		{
		    printf("can go from %d to %d at time %d\n", cur.S, e.v, cur.F);
		    if (dist[e.v] > cur.F + e.w)
			pq.emplace(cur.F + e.w, e.v);
		}
	    }
	    pq.//TODO
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
