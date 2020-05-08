// 7 May 2020

#include <iostream>
#include <vector>

#define f first
#define s second

using namespace std;
const int MX = 1111;
int N, M, S, T, dist[MX];
pair<int, pair<int, int> > edges[MX];

int main()
{
	memset(dist, 0x3f, sizeof dist);

	scanf("%d%d%d%d", &S, &T, &N, &M);
	for (int i=0; i<M; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edges[2*i] = make_pair(w, make_pair(u, v));
		edges[2*i+1] = make_pair(w, make_pair(v, u));
	}
	
	dist[S] = 0;
	for (int i=0; i<N; ++i)
		for (int e=0; e<2*M; ++e)
			if (dist[edges[e].s.s] > dist[edges[e].s.f] + edges[e].f)
				dist[edges[e].s.s] = dist[edges[e].s.f] + edges[e].f;
	
	for (int i=1; i<=N; ++i)
	{
		printf("to %d: %d\n", i, dist[i]);
	}
}

