// floyd modified for xjoi 1061
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MX = 1010;
int S, T, N, M, dist[MX][MX], thru[MX][MX];

void printPath(int src, int dst)
{
    if (dist[src][dst] >= 1<<20) // no path
        return;
    if (src == dst)
    {
        printf("%d ", src);
        return;
    }
    printPath(src, thru[src][dst]);
    if (src != thru[src][dst]) printPath(thru[src][dst], dst);
}

int main()
{
    // clear
    memset(dist, 0x30, sizeof(dist));
    memset(thru, 0, sizeof(thru));
    // input
    scanf("%d%d%d%d", &S, &T, &N, &M);
    for (int i=0; i<M; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        dist[u][v] = w;
        thru[u][v] = u;

        dist[v][u] = w;
        thru[v][u] = v;
    }
    // algo
    for (int k=1; k<=N; ++k)
        for (int i=1; i<=N; ++i)
            for (int j=1; j<=N; ++j)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    thru[i][j] = k;
                }

    // output
    printf("%d\n", dist[S][T]);
    printPath(S, T);
    printf("%d\n", T);
}

/*
1 3
3 3
1 2 2
2 3 3
1 3 6
 */

