// 6 may 2020

#include <iostream>
#include <queue>
#include <list>

using namespace std;
const int MX = 1000111;

int N, M, dist[MX], vis[MX], pre[MX];
list<pair<int, int> > head[MX];

int main()
{
	memset(dist, 0x3f, sizeof dist);
	int S, T;
	scanf("%d%d", &S, &T);
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		head[u].push_back(make_pair(w, v));
	}

	dist[S] = 0;
	int viscount=1;
	while (viscount < N)
	{
		int cur = 0;
		for (int i=1; i<=N; ++i)
			if (dist[cur] > dist[i] && !vis[i])
				cur = i;
		vis[cur] = true;
		++viscount;
		
		for (list<pair<int, int> >::iterator it=head[cur].begin(); it!=head[cur].end(); ++it)
			dist[it->second] = min(dist[it->second], dist[cur] + it->first);
	}
	for (int i=1; i<=N; ++i)
		printf("%3d", dist[i]);
	printf("\n");
}

