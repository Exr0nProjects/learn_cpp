#include <iostream>

using namespace std;
const int MX = 1111;
int N, M, dist[MX][MX];

int main()
{
	memset(dist, 0x3f, sizeof dist);
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; ++i)
	{
		int u, v, w;
		scanf("%d%d", &u, &v, &w);
		dist[u][v] = w;
	}

	for (int k=1; k<=N; ++k)
		for (int i=1; i<=N; ++i)
			for (int j=1; j<=N; ++j)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	for (int i=1; i<=N; ++i)
	{
		for (int j=1; j<=N; ++j)
			printf("%3d", dist[i][j]);
		printf("\n");
	}
}

