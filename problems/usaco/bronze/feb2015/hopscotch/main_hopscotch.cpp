/*
ID: spoytie2
TASK: hopscotch
LANG: C++14                 
*/

/*
 * Problem hopscotch (usaco/bronze/feb2015/hopscotch)
 * Created Sun 01 Dec 2019 @ 11:49 (PST)
 * Accepted [!meta:end!]
 * 
 * first attempt: dfs with tabulation
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
FILE* fin = fopen("hopscotch.in", "r");
FILE* fout = nullptr;

const int MAXSZ = 15; // todo
bool grid[MAXSZ+10][MAXSZ+10];
int store[MAXSZ+10][MAXSZ+10];
int r, c;

int dfs(cn y, cn x, cn ways=0)
{
  if (store[y][x] >= 0) return store[y][x];
  if (y == r || x == c) return 0;

  int ret = 0;
  for (int i=y+1; i<=r; ++i)
  {
    for (int j=x+1; j<=c; ++j)
    {
      if (grid[i][j] != grid[y][x]) // different color
      {
        ret += dfs(i, j);
      }
    }
  }
  store[y][x] = ret;
  return ret;
}

int main ()
{
  if (fin) { fout = fopen("hopscotch.out", "w+"); } else { fin = stdin; fout = stdout; }
  fscanf(fin, "%d%d", &r, &c);
  for (int i=1; i<=r; ++i)
  {
    fscanf(fin, "\n"); // consume newlines
    for (int j=1; j<=c; ++j)
    {
      store[i][j] = -1;
      fscanf(fin, "%c", &grid[i][j]);
    }
  }

  for (int i=0; i<=r; ++i)
  {
    for (int j=0; j<= c; ++j)
    {
      printf("%3d", grid[i][j]);
    }
    printf("\n");
  }

  fprintf(fout, "%d\n", dfs(1, 1));

  return 0;
}
