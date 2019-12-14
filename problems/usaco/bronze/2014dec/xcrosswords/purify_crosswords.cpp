/*
ID: spoytie2
TASK: crosswords
LANG: C++14
*/

/*
 * Problem crosswords (usaco/bronze/crosswords)
 * Created Thu 12 Dec 2019 @ 19:02 (PST)
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
auto fin = fopen("crosswords.in", "r");
auto fout = fopen("crosswords.out", "w+");

const int MAXSZ = 70; // todo
char _map[MAXSZ][MAXSZ];
int sx, sy, total = 0;

void debug()
{
  bool t = true;
  //d*/ t = false;
  if (t)
    return;
  printf("\n   ");
  for (int i = 0; i <= sx + 1; ++i)
  {
    printf("%3d", i);
  }
  printf("\n");

  for (int i = 0; i <= sy + 1; ++i)
  {
    printf("%3d", i);
    for (int j = 0; j <= sx + 1; ++j)
    {
      printf("%3c", _map[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

bool checkv(cn i, cn j)
{
  bool ret = (_map[i - 1][j] == '#' && _map[i][j] == '.' && _map[i + 1][j] == '.' && _map[i + 2][j] == '.');
  //d*/printf("checkv called on %d, %d: %d\n", i, j, ret);
  return ret;
}

bool checkh(cn i, cn j)
{
  bool ret = (_map[i][j - 1] == '#' && _map[i][j] == '.' && _map[i][j + 1] == '.' && _map[i][j + 2] == '.');
  //d*/printf("checkh called on %d, %d: %d\n", i, j, ret);
  return ret;
}

int main()
{
  fscanf(fin, "%d%d", &sy, &sx);
  for (int i = 0; i <= sy + 1; ++i)
    for (int j = 0; j <= sx + 1; ++j)
      _map[i][j] = '#';

  for (int i = 1; i <= sy; ++i)
  {
    fscanf(fin, "\n");
    for (int j = 1; j <= sx; ++j)
    {
      fscanf(fin, "%c", &_map[i][j]);
    }
  }

  debug();

  string out;
  for (int i = 1; i <= sy; ++i)
  {
    for (int j = 1; j <= sx; ++j)
    {
      if (checkh(i, j) || checkv(i, j))
      {
        total += 1;
        //d*/ printf("%d %d\n", i, j);
        out = out + "\n" + to_string(i) + " " + to_string(j);
      }
    }
  }

  fprintf(fout, "%d%s\n", total, out.c_str());

  return 0;
}
