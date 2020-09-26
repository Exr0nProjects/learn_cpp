// Bellman ford, negative loop detection removed for submission to 1061
#include <cstdio>
#include <cstring>
#include <utility>
#include <list>
#include <string>

using namespace std;
const int MX = 10010;

int S, T, N, M, dist[MX], pred[MX];
list<pair<int, pair<int, int> > > edges;

int main()
{
    // clear
    memset(dist, 0x7f, sizeof(dist));
    memset(pred, 0, sizeof(pred));
    edges.clear();
    // input
    scanf("%d%d%d%d", &S, &T, &N, &M);
    for (int i=0; i<M; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
      edges.emplace_back(w, make_pair(u, v));
      edges.emplace_back(w, make_pair(v, u));
    }
    // algo
    dist[T] = 0; // run bellman ford backwards so that predecesor is actually the path in the right order
    for (int k=1; k<N; ++k)
        for (auto e : edges)
            if (dist[e.second.first] + e.first < dist[e.second.second])
            {
                dist[e.second.second] = dist[e.second.first] + e.first;
                pred[e.second.second] = e.second.first;
            }
    // output
    printf("%d\n", dist[S]);
    for (int n=S; n!=T; n=pred[n]) printf("%d ", n);
    printf("%d\n", T);
    return 0;
}

