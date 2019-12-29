/*
ID: spoytie2
TASK: cowtip
LANG: C++14
*/

/*
 * Problem cowtip (usaco/bronze/2017jan/cowtip)
 * Created Sun 29 Dec 2019 @ 12:51 (PST)
 * Accepted [!meta:end!]
 *
 */

#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <cmath>
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
FILE *fin = fopen("cowtip.in", "r");
FILE *_ = stderr;

const int MAXSZ = 10; // todo
int N;
bool grid[MAXSZ+4][MAXSZ+4];

void toggle(cn y, cn x)
{
  if (y < 1 || x < 1 || y > N || x > N) return;
  for (int i=1; i<=y; ++i)
    for (int j=1; j<=x; ++j)
    {
      grid[i][j] = !grid[i][j];
    }
}

void debug()
{
  fprintf(_, "  "); for (int i=1; i<=N; ++i) fprintf(_, "%3d", i);
  for (int i=1; i<=N; ++i)
  {
    fprintf(_, "\n%2d", i);
    for (int j=1; j<=N; ++j)
    {
      fprintf(_, "%3c", (grid[i][j] ? 'X' : '.'));
    }
  }
  fprintf(_, "\n");
}

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("cowtip.out", "w+"); }
  scanf("%d", &N);
  for (int i=1; i<=N; ++i)
  {
    scanf("\n");
    for (int j=1; j<=N; ++j)
    {
      char c;
      scanf("%c", &c);
      grid[i][j] = c-'0';
    }
  }
  
  int ret = 0;
  for (int i=N; i>0; --i)
  {
    for (int j=N; j>0; --j)
    {
      if (grid[i][j])
      {
        toggle(i, j);
        ++ret;
      }
    }
  }
  
  printf("%d\n", ret);

  return 0;
}
