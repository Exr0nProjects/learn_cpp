/*
ID: spoytie2
TASK: crosswords
LANG: C++14                 
*/

/*
 * Problem crosswords (usaco/bronze/crosswords)
 * Created Wed 27 Nov 2019 @ 11:31 (PST)
 * Accepted [!meta:end!]
 * problem # 488
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
// auto fin = fopen("crosswords.in", "r");
// auto fout = fopen("crosswords.out", "w+");

const int MAXSZ = 70; // todo
char map[MAXSZ][MAXSZ];
int sx, sy, total = 0;

void checkh(cn i, cn j)
{
  if (map[i-1][j] == '#'
   && map[i  ][j] == '.'
   && map[i+1][j] == '.'
   && map[i+2][j] == '.')
    return true;
  return false;
}

void checkv(cn i, cn j)
{
  return (
      map[i][j-1] == '#'
   && map[i][j  ] == '.'
   && map[i][j+1] == '.'
   && map[i][j+2] == '.'
  );
}

int main ()
{
  scanf("%d%d", &sy, &sx);
  for (int i=0; i<=sy+1; ++i) for (int j=0; j<=sx+1; ++j) map[i][j] = '#';
  for (int i=1; i<=sy; ++i)
  {
    for (int j=1; j<=sx; ++j)
    {
      scanf("%c", &map[i][j]);
    }
  }

  string out;
  for (int i=0; i<=sy; ++i)
  {
    for (int j=0; j<=sx; ++j)
    {
      if (checkh(i, j) || checkv(i, j))
      {
        total += 1;
        out = out + "\n" + i + " " + j;
      }
    }
  }

  printf("%d%s\n", total, out.c_str());

  return 0;
}
