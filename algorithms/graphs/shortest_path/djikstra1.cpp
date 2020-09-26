// https://dev.xjoi.net/problem/1061 on 15 Mar 2020
#include <iostream>
#include <cstring>
#include <queue>
#include <list>
#include <stack>

using namespace std;
typedef pair<int, pair<int, int> > Edge;

const int MX = 1010;
int N, M, S, T;
list<Edge> head[MX];
int pred[MX], dist[MX];

int main()
{
    // reset
    for (int i=0; i<MX; ++i) head[i].clear();
    memset(pred, 0, sizeof(pred));
    memset(dist, 0x7F, sizeof(dist));
    // input
    scanf("%d%d%d%d", &S, &T, &N, &M);
    for (int i=0; i<M; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
      head[u].emplace_back(w, make_pair(u, v));
      head[v].emplace_back(w, make_pair(v, u));
    }
    // algo
    priority_queue<Edge, deque<Edge>, greater<Edge> > pq; // pair<dist, node>
  for (pq.emplace(0, make_pair(S, S)); !pq.empty();)
    {
        Edge v = pq.top();
        pq.pop();
        if (v.first > dist[v.second.second]) continue;
        dist[v.second.second] = v.first;
        pred[v.second.second] = v.second.first;
        for (Edge e : head[v.second.second])
            pq.emplace(v.first + e.first, e.second);
    }
    printf("%d\n%d", dist[T], S);
    stack<int> path;
    for (int n=T; n!=S; n=pred[n]) path.push(n);
    for (; !path.empty(); path.pop()) printf(" %d", path.top());
    printf("\n");
}

