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
#define cl const long long
#define ll long long
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
FILE* fin = fopen("meeting.in", "r");
FILE* fout = nullptr;

const int MAXSZ = 20; // todo

int adj[MAXSZ][MAXSZ];

int vis[MAXSZ];

set<ll> btimes;
set<ll> etimes;
int n, m, gmin = -1;

void addEdge(cn a, cn b, cn w1, cn w2)
{
  adj[a][b] = w1;
  adj[a][b] = w2;
}

void dfs(int adj[MAXSZ][MAXSZ], int vis[], set<ll>& end, cl s, cl d, cl cost=0)
{
  if (s == d)
  {
    end.insert(cost);
    return;
  }
  else
  {
    for (int i=1; i<=n; ++i)
    {
      if (adj[s][i] <= 0 || vis[i]) continue;
      vis[i] = true;
      dfs(adj, vis, end, i, d, cost+adj[s][i]);
      vis[i] = false;
    }
  }
}

int main()
{
  if (fin) { fout = fopen("meeting.out", "w+"); } else { fin = stdin; fout = stdout; }
  fscanf(fin, "%d%d", &n, &m);
  for (int i = 0; i < m; ++i)
  {
    int a, b, w1, w2;
    fscanf(fin, "%d%d%d%d", &a, &b, &w1, &w2);
    addEdge(a, b, w1, w2);
  }

  dfs(adj, vis, btimes, 1, n);
  dfs(adj, vis, etimes, 1, n);
  //d*/ for (int t: btimes) printf("%3d", t); printf("\n");
  
  for (auto t : btimes) {printf("%3d", t);}
  for (auto t : etimes) {printf("%3d", t);}
  printf("\n");

  for (auto i1 = btimes.begin(), i2 = etimes.begin(); i1 != btimes.end() && i2 != etimes.end();)
  {
    if (*i1 == *i2)
    {
      fprintf(fout, "%lld\n", *i1);
      return 0;
    }
    else if (*i1 < *i2)
    {
      ++i1;
    }
    else if (*i1 > *i2)
    {
      ++i2;
    }
  }

  fprintf(fout, "IMPOSSIBLE");
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
