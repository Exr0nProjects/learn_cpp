// 7 May 2020
#include <iostream>
#include <cstring> // FIX: include for memset

#define s second
#define f first

using namespace std;
const int MX = 1111;
int T, S, N, M, dist[MX], pre[MX];
pair<int, pair<int, int> > edges[MX];

int main()
{
	memset(dist, 0x3f, sizeof dist); // FIX: init dist to inf
	scanf("%d%d%d%d", &T, &S, &N, &M);
	
	for (int i=0; i<M; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edges[2*i] = make_pair(w, make_pair(u, v));
		edges[2*i+1] = make_pair(w, make_pair(v, u));
	}

	dist[S] = 0; // FIX: start at S
	for (int k=0; k<N; ++k)
		for (int e=0; e<2*M; ++e)
			if (dist[edges[e].s.s] > dist[edges[e].s.f] + edges[e].f)
			{
				dist[edges[e].s.s] = dist[edges[e].s.f] + edges[e].f;
				pre[edges[e].s.s] = edges[e].s.f;
			}
	printf("%d\n", dist[T]);
	for (int c=T; c!=S; c=pre[c])
		printf("%d ", c);
	printf("%d\n", S);
}

