/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem #8112
 * Tue 27 Aug 2019 @ 18:52 PDT)
 * 
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

#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 110; // todo
int matrix[MAXSZ][MAXSZ];

void dfs (const int y, const int x)
{
  matrix[i][j] = -1;
  if (matrix[i+1][j] == 1) bfs(i+1, j);
  if (matrix[i][j+1] == 1) bfs(i, j+1);
  if (i > 0 && matrix[i-1][j] == 1) bfs(i-1, j);
  if (j > 0 && matrix[i][j-1] == 1) bfs(i, j-1)
}

int main ()
{
  int m, n;
  scanf("%d%d", &m, &n);
  for (int i=0; i<m; ++i)
  {
    for (int j=0; j<n; ++j)
    {
      char t;
      scanf("%1c", &t);
      if (t == '0') matrix[i][j] = 0;
      else matrix[i][j] = 1;
    }
  }

  int ret; 
  for (int i=0; i<m; ++i)
  {
    for (int j=0; j<n; ++j)
    {
      if (matrix[i][j] == 1) dfs(i, j);
      ++ ret;
    }
  }

  printf("%d", ret);

  return 0;
}
