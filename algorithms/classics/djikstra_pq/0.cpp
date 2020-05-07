// 6 may 2020

#include <iostream>
#include <cstring> // FIX: include for memset
#include <queue>
#include <list>

using namespace std;
const int MX = 1000111;
int N, M, dist[MX], pre[MX];
list<pair<int, int> > head[MX];

int main()
{
	memset(dist, 0x3f, sizeof dist); // FIX: init dist to inf
	int S, T;
	scanf("%d%d", &T, &S); // source
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		head[u].push_back(make_pair(w, v));
		head[v].push_back(make_pair(w, u)); // FIX: bidirectional edges
	}

	// djikstra
	priority_queue<pair<int, int>, deque<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, S));
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top(); pq.pop();
		if (dist[cur.second] < cur.first) continue; // FIX: skip if less, not greater
		if (cur.second == T) break;

		for (list<pair<int, int> >::iterator it=head[cur.second].begin(); it!=head[cur.second].end(); ++it)
			if (dist[it->second] > cur.first + it->first)
			{
				dist[it->second] = cur.first + it->first;
				pre[it->second] = cur.second;
				pq.push(make_pair( cur.first + it->first, it->second ));
			}
	}
	printf("%d\n", dist[T]);
	int count=0;
	for (int c=T; ++count<10 && c!=S; c=pre[c])
		printf("%d ", c);
	printf("%d\n", S);
}

