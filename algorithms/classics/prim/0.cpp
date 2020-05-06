
#include <iostream>
#include <queue>
#include <list>

using namespace std;
const int MX = 100111;
list<pair<int, int> > head[MX];
bool vis[MX];

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		head[u].push_back(make_pair(w, v));
		head[v].push_back(make_pair(w, u));
	}
	int count=0, cost=0;
	priority_queue<pair<int, int>, deque<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, 1)); // <weight, node>
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top(); pq.pop();
		if (vis[cur.second]) continue;
		vis[cur.second] = true;
		++count;
		cost += cur.first;
		if (count == N) break; // FIX: loop over nodes not edges, so count == N not count+1 == N
		for (list<pair<int, int> >::iterator it=head[cur.second].begin(); it!=head[cur.second].end(); ++it)
			pq.push(*it);
	}

	printf("%d\n", cost);
}

