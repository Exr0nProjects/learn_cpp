/*
ID: spoytie2
TASK: 1062
LANG: C++14
*/

/*
 * Problem 1062 (xjoi.net/1062)
 * Created Sun 24 Nov 2019 @ 15:12 (PST)
 * Accepted [!meta:end!]
 * floyd print out path
 */

#include <bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <math.h>
#include <random>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

#define cn const int
#define ca const auto &
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
// auto fin = fopen("1062.in", "r");
// auto fout = fopen("1062.out", "w+");

const int MAXSZ = 310; // todo
int b1, e1, b2, e2, n, m;
LL dist[MAXSZ][MAXSZ][MAXSZ];
LL dis[MAXSZ][MAXSZ];

int nx[MAXSZ][MAXSZ];

// int edgecount = 1;
// struct Edge
// {
//   int f, t, w, n;
// } edges[40010];
// int head[MAXSZ];
// void addEdge(a, b, w)
// {
//   edges[edgecount].f = a;
//   edges[edgecount].t = b;
//   edges[edgecount].w = w;
//   edges[edgecount].n = head[a];
//   head[a] = edgecount;
//   ++edgecount;
// }

int main ()
{
  scanf("%d%d%d%d%d%d", &b1, &e1, &b2, &e2, &n, &m);

  for (int i=1; i<=n; ++i)
  {
    for (int j=1; j<=n; ++j)
    {
      if (i == j)
      {
        dist[0][i][j] = 0;
        dis[i][j] = 0;
        nx[i][j] = j;
      }
      else
      {
        dist[0][i][j] = pow(10, 9) + 1;
        dis[i][j] = pow(10, 9) + 1;
      }
    }
  }

  for (int i=1; i<=m; ++i)
  {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    dist[0][a][b] = dist[0][b][a] = c;
    nx[a][b] = b; nx[b][a] = a;
    
    dis[a][b] = dis[b][a] = c;
  }
  
  // debug
//  for (int i=1; i<=n; ++i)
//  {
//    for (int j=1; j<=n; ++j)
//    {
//      printf("%12d", dist[0][i][j]);
//    }
//    printf("\n");
//  }

  for (int k=1; k<=n; ++k)
  {
    for (int i=1; i<=n; ++i)
    {
      for (int j=1; j<=n; ++j)
      {
        if (i==k || j==k || i==j) continue; // from teacher's code... oofu
        if (dist[k-1][i][j] > dist[0][i][k] + dist[k-1][k][j])
        {
          dist[k][i][j] = dist[0][i][k] + dist[k-1][k][j];
          nx[i][j] = k;
        }
        else if (dist[k-1][i][j] == dist[0][i][k] + dist[k-1][k][j]  &&  nx[i][j] > nx[i][k]) // lex compare, also from teachers code
        {
          nx[i][j] = nx[i][k];
        }
        else
        {
          dist[k][i][j] = dist[k-1][i][j];
        }
        
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
      }
    }
  }

  printf("%d\n", dist[n][b1][e1]);
  for (int i=b1; true; i = nx[i][e1])
  {
    printf("%d ", i);
    if (i == e1) break;
  } printf("\n");
  printf("%d\n", dist[n][b2][e2]);
  for (int i=b2; true; i = nx[i][e2])
  {
    printf("%d ", i);
    if (i == e2) break;
  } printf("\n");
  
  
 // printf("%d\n_\n%d\n_\n", dis[b1][e1], dis[b2][e2]);

  return 0;
}
