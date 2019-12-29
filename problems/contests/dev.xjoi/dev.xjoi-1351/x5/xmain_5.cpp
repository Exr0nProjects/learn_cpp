/*
ID: spoytie2
TASK: 5
LANG: C++14
*/

/*
 * Problem 5 (contests/dev.xjoi/dev.xjoi-1351/5)
 * Created Sat 28 Dec 2019 @ 18:19 (PST)
 * Accepted Sat 28 Dec 2019 @ 20:41 (PST)
 * dfs maze
 */

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
#define ll long long
#define cl const long long
#define UN unsigned
#define ST static
#define CN const
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 60; // todo
int maze[MAXSZ][MAXSZ];
int n, shortest = -1, ccount = 0;

void dfs(cn i, cn j, cn s = 0)
{
  if (i == n && j == n)
  {
    //printf("success after %d steps\n", s);
    if (shortest < 0 || s < shortest)
    {
      shortest = s;
      ccount = 0; // gets incremented soon
    }
    if (s == shortest)
    {
      ++ccount;
    }
  }
  int dirs[] = {1, -1};
  for (int _i : dirs)
  {
    //printf("mod: (%d, %d)\n", i+_i, j);
    if (!maze[i + _i][j])
    {
      maze[i + _i][j] = 1;
      dfs(i + _i, j, s + 1);
      maze[i + _i][j] = 0;
    }
    if (!maze[i][j + _i])
    {
      maze[i][j + _i] = 1;
      dfs(i, j + _i, s + 1);
      maze[i][j + _i] = 0;
    }
  }
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n + 2; ++i)
  {
    for (int j = 0; j < n + 2; ++j)
    {
      if (i > 0 && i <= n && j > 0 && j <= n) // in bounds
      {
        scanf("%d", &maze[i][j]);
      }
      else
      {
        maze[i][j] = 1;
      }
      //printf("%3d", maze[i][j]);
    }
    //printf("\n");
  }

  dfs(1, 1, 1);
  printf("%d\n%d", ccount, shortest);

  return 0;
}

/*
 5
 0 0 0 0 0
 0 1 1 1 0
 0 1 0 0 0
 0 1 0 1 0
 0 0 0 0 0
 
 */
