#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MX = 10010;
int N, M, dist[MX][MX];

int main()
{
    // clear
    memset(dist, 0x7f, sizeof(dist));
    // input
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        dist[u][v] = w;
    }
    // algo
    for (int k=0; k<N; ++k)
        for (int i=0; i<N; ++i)
            for (int j=0; j<N; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
