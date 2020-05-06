// 6 may 2020
#include <iostream>

using namespace std;
const int MX = 10111;
int N, M, dist[MX][MX], thru[MX][MX];

void printPath(int i, int j)
{ // TODO: hecka scuffed
	printf("%3d", i);
	if (thru[i][j]) // don't print thru if its zero
	{
		printPath(i, thru[i][j]);
		printf("%3d", thru[i][j]);
		printPath(thru[i][j], j);
	}
	printf("%3d", j);
}

int main()
{
	memset(dist, 0x3f, sizeof dist); // FIX: init dist w/ inf!
	scanf("%d%d", &N, &M);
	for (int i=0; i<MX; ++i) dist[i][i] = 0;
	for (int i=0; i<M; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		dist[u][v] = w; // construct graph backwards for path reconstruction
	}
	for (int k=1; k<=N; ++k)
		for (int i=1; i<=N; ++i)
			for (int j=1; j<=N; ++j)
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					thru[i][j] = k;
				}
	int Q; // num queries
	scanf("%d", &Q);
	for (int i=0; i<Q; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		printPath(u, v);
		printf("\n");
	}
}

/*
3 4
1 2 1
2 3 1
3 1 2
3 2 1
100
*/
