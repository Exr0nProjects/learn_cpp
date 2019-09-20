/*
 19 Sep 2019
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 110;
struct Edge
{
  int from, to, next, weight;
} edges[MAXSZ * 2];
int head[MAXSZ];

bool vis[MAXSZ];

int n, m;

void addEdge(const int a, const int b, const int w)
{
  static int next = 1;
  edges[next].from = a;
  edges[next].to = b;
  edges[next].weight = w;
  edges[next].next = head[a];
  head[a] = next;
  ++next;
}

int main()
{
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; ++i)
  {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    addEdge(a, b, w);
    addEdge(b, a, w);
  }

  auto cmp = [](const int l, const int r) { return edges[l].weight < edges[r].weight; };
  priority_queue<int, vector<int>, function<bool(int,int)> > pq(cmp);

  for (int e=head[1], m=head[1]; true; e=edges[e].next)
  {
    if (!e)
    {
      pq.push(m);
      vis[1] = true;
      break;
    }
    if (edges[e].weight < edges[m].weight) m = e;
  }

  for (; !pq.empty(); pq.pop())
  {
    Edge c = pq.top();
    if (vis[c.to]) continue;
    // output that this edge is used
    printf("%d->%d\n", c.from, c.to);
    for (int e=head[c.to], m=head[c.to]; true; e=edges[e].next)
    {
      if (!e)
      {
        pq.push(m);
        vis[c.to] = true;
        break;
      }
      if (edges[e].weight < edges[m].weight) m = e;
    }
  }

  return 0;
}

/*
2 1
1 2 1

4 3
1 3 1
3 2 1
2 4 2


4 3
1 2 2
2 3 -1
3 4 1

2 2
1 2 1
2 1 -2

4 4
1 2 5
1 3 3
2 3 -3
3 4 1
 */
