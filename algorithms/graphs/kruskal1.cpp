#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
const int MX = 100111;
int N, M;
vector<pair<int, pair<int, int> > > edges;

int djf[MX], djs[MX];
int find(int n)
{
    if (djf[n] != n) djf[n] = find(djf[n]);
    return djf[n];
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (a < b) swap(a, b);
    djs[a] += djs[b];
    djf[b] = a;
}

int main()
{
    // clear
    edges.clear();
    iota(djf, djf+MX, 0);
    for (int i=0; i<MX; ++i) djs[i] = 1;
    // input
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges.emplace_back(w, make_pair(u, v));
    }
    // algo
    sort(edges.begin(), edges.end());
    int groups=N, cost=0;
    for (int i=0; i<M && groups; ++i)
    {
        if (find(edges[i].second.first) == find(edges[i].second.second))
            continue;
        else
        {
            merge(edges[i].second.second, edges[i].second.first);
            --groups;
            cost += edges[i].first;
        }
    }
    printf("%d", cost);
}

