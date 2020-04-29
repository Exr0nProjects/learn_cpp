/*
TASK: uva1027
LANG: C++14
*/

/*
 * Problem uva1027 (contests/dated/2020_04_27/uva1027)
 * Create time: Wed 29 Apr 2020 @ 12:00 (PDT)
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
#define f first
#define s second
#define g(t, i) get<i>(t)
#define mt make_tuple

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

using namespace std;
const int MX = 130;
list<char> head[MX];
int dist[MX];
int N, K, S, T;

int main()
{
	int kase=0;
	while (++kase)
	{
		scanf("%d", &N);
		if (N < 0) break;
		memset(dist, 0x40, sizeof dist);
		FOR(i, MX) head[i].clear();

		FOR(i, N)
		{
			char u, v;
			scanf("\n%c %c", &u, &v);
			head[u].pb(v);
			head[v].pb(u);
		}
		scanf("%d %c %c", &K, &T, &S);
		//printf("got input\n");

		// djikstra
		priority_queue<pair<int, char>, deque<pair<int, char> >, greater<pair<int, char> > > pq;
		pq.emplace(K, S);
		dist[S] = K;
		while (!pq.empty())
		{
			pair<int, char> cur = pq.top(); pq.pop();
			if (dist[cur.s] < cur.f) continue;
			//printf("at %c after %d -> |%d|\n", cur.s, cur.f, head[cur.s].size());

			if (cur.s == T)
			{
				printf("Case %d: %d\n", kase, cur.f);
				break;
			}

			int eta = cur.f + 1;
			if (cur.f < 90) // upper case
				eta += cur.f/20;
			for (char n : head[cur.s])
			{
				//printf("    can go to %c (%d vs %d)\n", n, eta, dist[n]);
				if (dist[n] > eta)
				{
					dist[n] = eta;
					pq.emplace(eta, n);
				}
			}
		}
		//printf("pq empty!\n");
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
