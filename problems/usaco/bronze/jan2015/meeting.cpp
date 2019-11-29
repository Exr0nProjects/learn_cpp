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

const int MAXSZ = 20; // todo

int adj1[MAXSZ][MAXSZ];
int adj2[MAXSZ][MAXSZ];

int vis1[MAXSZ];
int vis2[MAXSZ];

set<int> btimes;
int n, m, gmin = -1;

void addEdge(cn a, cn b, cn w1, cn w2)
{
  adj1[a][b] = w1;
  adj2[a][b] = w2;
}

void first_dfs(cn s, cn d, cn cost=0)
{
  if (s == d) // base case
  {
    btimes.insert(cost);
    return;
  }
  for (int i=1; i<=n; ++i)
  {
    if (adj1[s][i] <= 0 || vis1[i]) continue; // already visited this field
    vis1[i] = true;
    first_dfs(i, d, cost+adj1[s][i]);
    vis1[i] = false;
  }
}

void second_dfs(cn s, cn d, cn cost=0)
{
  //d*/ printf("second dfs: %d %d %d\n", s, d, cost);
  if (s == d)
  {
    //d*/ printf("second dfs made it! %d\n", cost);
    if (btimes.find(cost) != btimes.end())
    {
      if (gmin < 0 || gmin > cost)
        gmin = cost;
    } // else it was not a viable meeting time
    return;
  }
  for (int i=1; i<=n; ++i)
  {
    //d*/ printf("  going from %d->%d\n", s, i);
    if (adj2[s][i] <= 0 || vis2[i]) continue; // not a path or already visited
    vis2[i] = true;
    second_dfs(i, d, cost + adj2[s][i]);
    vis2[i] = false;
  }
}

int main ()
{
  fscanf(fin, "%d%d", &n, &m);
  for (int i=0; i<m; ++i)
  {
    int a, b, w1, w2;
    fscanf(fin, "%d%d%d%d", &a, &b, &w1, &w2);
    addEdge(a, b, w1, w2);
  }

  first_dfs(1, n);
  //d*/ for (int t: btimes) printf("%3d", t); printf("\n");
  
  second_dfs(1, n);
  
  if (gmin < 0) fprintf(fout, "IMPOSSIBLE");
  else fprintf(fout, "%d", gmin);
  fprintf(fout, "\n");

  return 0;
}

/*
4 5
1 3 1 2
1 2 1 2
2 3 1 2
3 4 1 1
2 4 6 6
 */
