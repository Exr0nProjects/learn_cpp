/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 1226 (xjoi.net/1226)
 * Created Fri 06 Sep 2019 @ 19:59 (PDT)
 * Accepted [!meta:end!]
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

const int MAXSZ = 10; // todo
int maze[MAXSZ][MAXSZ];
int a, b, count=0;

void dfs (const int i, const int j)
{
  if (i == a-1 && j == b-1) { count ++; return; }
  if (i > 0 && maze[i-1][j] == 0)
  {
    maze[i-1][j] = maze[i][j]+1;
    dfs(i-1, j);
    maze[i-1][j] = 0;
  }
  if (j > 0 && maze[i][j-1] == 0)
  {
    maze[i][j-1] = maze[i][j]+1;
    dfs(i, j-1);
    maze[i][j-1] = 0;
  }
  if (i < a-1 && maze[i+1][j] == 0)
  {
    maze[i+1][j] = maze[i][j]+1;
    dfs(i+1, j);
    maze[i+1][j] = 0;
  }
  if (j < b-1 && maze[i][j+1] == 0)
  {
    maze[i][j+1] = maze[i][j]+1;
    dfs(i, j+1);
    maze[i][j+1] = 0;
  }
}
int main ()
{
  scanf("%d%d", &a, &b);
  for (int i=0; i<a; ++i)
  {
    scanf("\n");
    for (int j=0; j<b; ++j)
    {
      char t;
      scanf("%c", &t);
      if (t == '#') maze[i][j] = -1;
    }
  }

  dfs(0, 0);
  printf("%d", count);

  return 0;
}
