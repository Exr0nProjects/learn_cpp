// jan 2015 bronze meeting

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
 auto fin = fopen("meeting.in", "r");
 auto fout = fopen("meeting.out", "w+");

const int MAXSZ = 16; // todo
struct Edge
{
  int f, t, w1, w2, n;
} edges[MAXSZ*MAXSZ];
int head[MAXSZ];

int vis1[MAXSZ];
int vis2[MAXSZ];

set<int> btimes;
int n, m, eept=1; // edge end pointer

void addEdge(cn a, cn b, cn w1, cn w2)
{
  edges[eept].f = a;
  edges[eept].t = b;
  edges[eept].w1 = w1;
  edges[eept].w2 = w2;
  edges[eept].n = head[a];
  head[a] = eept;
  ++eept;
  printf("added edge %d->%d: %d, %d\n", a, b, w1, w2);
}

void first_dfs(cn s, cn d, cn steps=0)
{
  if (s == d) // base case
  {
    btimes.insert(steps);
    return;
  }
  vis1[s] = true;
  for (int e = head[s]; e; e = edges[e].n)
  {
    if (vis1[edges[e].t]) continue; // already visited this field
    first_dfs(edges[e].t, d, steps+1);
  }
  vis1[s] = false;
}

int main ()
{
  scanf("%d%d", &n, &m);
  for (int i=0; i<m; ++i)
  {
    int a, b, w1, w2;
    scanf("%d%d%d%d", &a, &b, &w1, &w2);
    addEdge(a, b, w1, w2);
  }
  
  /*/d*/ printf("idx:   "); for (int i=1; i<=m; ++i) printf("%3d", i); printf("\nhead:  "); for (int i=1; i<=m; ++i) printf("%3d", head[i]); printf("\ndest:  "); for (int i=0; i<m; ++i) printf("%3d", edges[i].t); printf("\nnext:  "); for (int i=0; i<m; ++i) printf("%3d", edges[i].n); printf("\n\n");

  first_dfs(1, n);
  
  /*/d*/ for (int t : btimes) printf("%3d", t); printf("\n"); // so far so good

  return 0;
}

/*
4 6
1 3 1 2
1 2 1 2
2 3 1 2
3 4 1 1
2 4 6 6
2 1 100 100
 */
