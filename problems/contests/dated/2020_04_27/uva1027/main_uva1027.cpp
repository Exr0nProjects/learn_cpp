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

#define f first
#define s second

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
		for (int i=0; i<MX; ++i) head[i].clear();

		for (int i=0; i<N; ++i)
		{
			char u, v;
			scanf("\n%c %c", &u, &v);
			head[u].push_back(v);
			head[v].push_back(u);
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

			int eta;
			if (cur.s < 90) // upper case; FIX: cur.s not cur.f
				eta = (20*cur.f + 20)/19;
			else
				eta = cur.f + 1;
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
