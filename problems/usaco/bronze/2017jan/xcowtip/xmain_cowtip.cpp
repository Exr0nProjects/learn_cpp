/*
ID: spoytie2
TASK: cowtip
LANG: C++14
*/

/*
 * Problem cowtip (usaco/bronze/2017jan/cowtip)
 * Created Sun 29 Dec 2019 @ 12:51 (PST)
 * Accepted Sun 29 Dec 2019 @ 13:27 (PST)
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

pair<int, int> farthest(pair<int, int> src)
{
  if (grid[src.first][src.second]) return src;
  if (src.first == 1 && src.second == 1) return make_pair(-1, -1);

  // step
  if (src.first == N || src.second == 1) // on a teleport edge (bottom and left)
  {
    if (src.second == 1) // left edge
    {
      src.second = src.first-1;
      src.first = 1;
    }
    else if (src.first == N) // bottom edge but not corner
    {
      src.first = src.second-1;
      src.second = N;
    }
  }
  else
  {
    ++src.first;
    --src.second;
  }
  fprintf(_, "  check: (%d, %d)\n", src.first, src.second);
  return farthest(src);
}

void toggle(pair<int, int> spot)
{
  if (spot.first < 1 || spot.second < 1 || spot.first > N || spot.second > N) return;
  for (int i=1; i<=spot.first; ++i)
    for (int j=1; j<=spot.second; ++j)
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
  fprintf(_, "n=%d\n", N);
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
  for (int i=0; i<N*N; ++i)
  {
    ca p = farthest(make_pair(N, N));
    if (p.first < 0 && p.second < 0)
    {
      printf("%d\n", ret);
      return 0;
    }
    toggle(p);
    debug();
    ++ret;
  }
  
  printf("1\n");

  return 0;
}
