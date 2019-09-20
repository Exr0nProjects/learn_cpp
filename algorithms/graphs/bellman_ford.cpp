/*
 18 Sep 2019
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 110;
struct Edge
{
  int to, next, weight;
} edges[MAXSZ * 2];
int head[MAXSZ];

int val[MAXSZ];

int n, m;

void addEdge(const int a, const int b, const int w)
{
  static int next = 1;
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
    if (a == 1)
      val[b] = w;
  }

  printf("\n\n");
  for (int i = 1; i <= m; ++i)
  {
    printf("%d ", i);
    for (int e = head[i]; e; e = edges[e].next)
    {
      printf("%3d ", edges[e].to);
    }
    printf("\n");
  }

  for (int i = 1; i < m - 1; ++i)
  {
    //*d*/for (int j=1; j<=m; ++j) printf("%3d", val[j]); printf("\n\n");
    for (int c = 1; c <= m; ++c)
    {
      printf("  %d", c);
      for (int j = 1; j <= m; ++j)
        printf("%3d", val[j]);
      printf("\n");
      for (int e = head[c]; e > 0; e = edges[e].next)
      {
        printf("    %3d\n", edges[e].to);
        if (!val[edges[e].to] && val[c])
          val[edges[e].to] = val[c] + edges[e].weight;
        else
          val[edges[e].to] = min(val[edges[e].to], val[c] + edges[e].weight);
      }
    }
  }

  for (int c = 1; c <= m; ++c)
  {
    for (int e = head[m]; e > 0; e = edges[e].next)
    {
      if (val[m] + edges[e].weight < val[edges[e].to])
      {
        printf("Negative loop!");
        return -1;
      }
    }
  }

  printf("%d", val[m]);
}

/*
2 1
1 2 1
 
4 3
1 3 1
3 2 1
2 4 2

 
 
5 9
1 2 2
2 3 2
2 1 2
3 2 -1
1 4 1
4 1 3
4 3 -1
4 5 9
3 5 1
*/
