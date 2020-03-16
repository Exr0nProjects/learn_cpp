#include <cstdio>
#include <cstring>
#include <utility>
#include <list>
#include <string>

using namespace std;
const int MX = 10010;

int N, M, dist[MX];
list<pair<int, pair<int, int> > > edges;

int main()
{
    // clear
    edges.clear();
    memset(dist, 0x7f, sizeof(dist));
    // input
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
      edges.emplace_back(w, make_pair(u, v));
    }
    // algo
    dist[1] = 0;
    for (int k=1; k<N; ++k)
        for (auto e : edges)
            dist[e.second.second] = min(dist[e.second.second], dist[e.second.first] + e.first);
    //     check for negative loops
    for (auto e : edges)
        if (dist[e.second.second] > dist[e.second.first] + e.first)
        {
            printf("Error!\n");
            return 0;
        }
    // output
    for (int i=1; i<=N; ++i)
    {
        if (dist[i] > 1<<30) printf("inf ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
    return 0;
}

