/*
 18 Sep 2019
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 110;
struct Edge
{
  int to, next, weight;
} edges[MAXSZ*2];
int head[MAXSZ];

int val[MAXSZ];
bool vis[MAXSZ];

int n, m;

void addEdge(const int a, const int b, const int w)
{
  static int next=1;
  edges[next].to = b;
  edges[next].weight = w;
  edges[next].next = head[a];
  head[a] = next;
  ++next;
}

int main()
{
  scanf("%d%d", &m, &n);
  for (int i=0; i<n; ++i)
  {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    if (w < 0) return -1; // negative edge weight
    addEdge(a, b, w);
    addEdge(b, a, w);
  }
  
  val[1] = 0;
  auto cmp = [](const int l, const int r) { return (vis[l]?(vis[r]?vis[l]<vis[r]:true):false); };
  priority_queue<int, vector<int>, function<bool(int,int)> > pq(cmp);
  for (pq.push(1); !pq.empty(); pq.pop())
  {
    int c = pq.top();
    if (c == m) break;
    for (int e=head[c]; e>0; e=edges[e].next)
    { // relax
      if (vis[c]) continue;
      if (val[edges[e].to] == 0) val[edges[e].to] = val[c] + edges[e].weight;
      else val[edges[e].to] = min(val[edges[e].to], val[c] + edges[e].weight);
      pq.push(edges[e].to);
    }
    vis[c] = true;
  }
  
  printf("%d", val[m]);
}

/*
5 5
1 2 2
2 3 2
1 4 1
4 5 9
3 5 1
*/
