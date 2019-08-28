/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem #8120
 * Tue 27 Aug 2019 @ 19:22 PDT)
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

const int MAXSZ = 25; // todo
char mat[MAXSZ][MAXSZ];

int dfs (const int i, const int j)
{
  int sum = 0;
  mat[i][j] = '#';
  if (mat[i+1][j] == '.') sum += dfs(i+1, j);
  if (mat[i][j+1] == '.') sum += dfs(i, j+1);
  if (i > 0 && mat[i-1][j] == '.') sum += dfs(i-1, j);
  if (j > 0 && mat[i][j-1] == '.') sum += dfs(i, j-1);
  return sum + 1;
}

int main ()
{
  int a=1, b=1, si, sj;
  scanf("%d%d", &a, &b);
  while (a+b)
  {
    for (int i=0; i<a; ++i)
    {
      for (int j=0; j<b; ++j)
      {
        scanf("%c", mat[i]+j);
        if (mat[i][j] == '@')
        {
          si = i;
          sj = j;
        }
      }
    }

    printf("%d\n", dfs(si, sj));
    scanf("%d%d", &a, &b);
  }

  return 0;
}

/*
3 3
.#.
#..
..@
2 2
.#
#@
0 0
*/

/*
6 9
....#.
.....#
......
......
......
......
......
#@#...
.###..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
0 0
*/