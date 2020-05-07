// 6 may 2020
#include <iostream>
#include <cstring> // FIX: include for memset

using namespace std;
const int MX = 1111; // FIX: 1000 not 100
int N, M, dist[MX][MX], thru[MX][MX];

void printPath(int i, int j) // inc i, exc j
{
	if (thru[i][j]) // don't print thru if its zero
	{
		printPath(i, thru[i][j]);
		printPath(thru[i][j], j);
	}
	else
		printf("%d ", i);
}

int main()
{
	memset(dist, 0x3f, sizeof dist); // FIX: init dist w/ inf!
	int u, v;
	scanf("%d%d", &u, &v);
	scanf("%d%d", &N, &M);
	for (int i=0; i<MX; ++i) dist[i][i] = 0;
	for (int i=0; i<M; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		dist[u][v] = w;
		dist[v][u] = w;
	}
	for (int k=1; k<=N; ++k)
		for (int i=1; i<=N; ++i)
			for (int j=1; j<=N; ++j)
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					thru[i][j] = k;
				}
	printf("%d\n", dist[u][v]); // FIX: print out distance first
	printPath(u, v);
	if (u != v) printf("%d\n", v);
}

/*
3 4
1 2 1
2 3 1
3 1 2
3 2 1
100
*/
