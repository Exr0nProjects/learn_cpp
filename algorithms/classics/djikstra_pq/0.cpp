// 6 may 2020

#include <iostream>
#include <queue>
#include <list>

using namespace std;
const int MX = 1000111;
int N, M, dist[MX];
list<pair<int, int> > head[MX];

int main()
{
	memset(dist, 0x3f, sizeof dist); // FIX: init dist to inf
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		head[u].push_back(make_pair(w, v));
	}

	// djikstra
	int S;
	scanf("%d", &S); // source
	priority_queue<pair<int, int>, deque<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, S));
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top(); pq.pop();
		if (dist[cur.second] < cur.first) continue; // FIX: skip if less, not greater
		dist[cur.second] = cur.first;

		for (list<pair<int, int> >::iterator it=head[cur.second].begin(); it!=head[cur.second].end(); ++it)
			if (dist[it->second] > cur.first + it->first)
			{
				dist[it->second] = cur.first + it->first;
				pq.push(make_pair( cur.first + it->first, it->second ));
			}
	}
	for (int i=1; i<=N; ++i)
		printf("%3d", dist[i]);
	printf("\n");
}

