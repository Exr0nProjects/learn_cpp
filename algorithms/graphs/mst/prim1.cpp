#include <cstdio>
#include <list>
#include <cstring>
#include <queue>

using namespace std;
const int MX = 100111;
int N, M, vis[MX];
list<pair<int, int> > head[MX];

int main()
{
    // clear
    memset(vis, 0, sizeof(vis));
    for (int i=0; i<MX; ++i) head[i].clear();
    // input
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        head[u].emplace_back(w, v);
        head[v].emplace_back(w, u);
    }
    // algo
    long long  cost=0;
    priority_queue<pair<int, int>, deque<pair<int, int> >, greater<pair<int, int> > > pq; // pq(edge) (pq(pair<dist, v>))
    for (pq.emplace(0, 1); !pq.empty();)
    {
        pair<int, int> next = pq.top(); pq.pop();
        if (vis[next.second]) continue;

        vis[next.second] = 1;
        cost += next.first;

        for (auto &e : head[next.second])
            pq.push(e);
    }
    printf("%lld", cost);
}
