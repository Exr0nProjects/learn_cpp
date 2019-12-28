/*
ID: spoytie2
TASK: pails
LANG: C++14
*/

/*
 * Problem pails (usaco/bronze/2016feb/pails)
 * Created Sat 28 Dec 2019 @ 13:40 (PST)
 * Accepted [!meta:end!]
 *
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
FILE *fin = fopen("pails.in", "r");
FILE *fout = nullptr;

const int MAXSZ = 1019; // todo
int X, Y, M;
int tabu[MAXSZ][MAXSZ];

int recurse(cn x, cn y)
{
  if (tabu[x][y] >= 0)
    return tabu[x][y];
  int ret = x * X + y * Y;
  if (ret > M)
    return 0;
  ret = max(max(recurse(x + 1, y), recurse(x, y + 1)), ret);
  tabu[x][y] = ret;
  return ret;
}

int main()
{
  if (fin)
  {
    fout = fopen("pails.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }
  for (int i = 0; i < MAXSZ; ++i)
    for (int j = 0; j < MAXSZ; ++j)
      tabu[i][j] = -1;
  fscanf(fin, "%d%d%d", &X, &Y, &M);
  fprintf(fout, "%d\n", recurse(0, 0));

  return 0;
}
