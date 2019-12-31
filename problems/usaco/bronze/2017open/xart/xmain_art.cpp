/*
ID: spoytie2
TASK: art
LANG: C++14
*/

/*
 * Problem art (usaco/bronze/2017open/art)
 * Created Mon 30 Dec 2019 @ 15:34 (PST)
 * Accepted Mon 30 Dec 2019 @ 16:13 (PST)
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
FILE *fin = fopen("art.in", "r");
FILE *_ = stderr;

const int MAXSZ = 12; // todo
int N;
bool urbaaad[MAXSZ];
bool exists[MAXSZ];
int top[MAXSZ];
int bot[MAXSZ];
int lft[MAXSZ];
int rig[MAXSZ];
int painting[MAXSZ][MAXSZ];

int at(cn y, cn x)
{
  if (y >= 0 && y < N && x >= 0 && x < N) return painting[y][x];
  return 0;
}

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("art.out", "w+"); }
  
  for (int i=0; i<MAXSZ; ++i)
  {
    top[i] = lft[i] = 0x7FFFFFF; // prep for min-ing later on
  }
  
  scanf("%d", &N);

  for (int i=0; i<N; ++i)
  {
    scanf("\n");
    for (int j=0; j<N; ++j)
    {
      char c;
      scanf("%c", &c);
      c -= '0';
      exists[c] = true; // we can see this color on the painting
      painting[i][j] = c;
      
      top[c] = min(top[c], i);
      bot[c] = max(bot[c], i);
      lft[c] = min(lft[c], j);
      rig[c] = max(rig[c], j);
    }
  }
  
  for (int c=1; c<=9; ++c)
  {
    for (int i=top[c]; i<=bot[c]; ++i)
    {
      for (int j=lft[c]; j<=rig[c]; ++j)
      {
        if (painting[i][j] != c) // covered
          urbaaad[painting[i][j]] = true; // that one can't be first
      }
    }
  }
  
  int ret = 0;
  for (int c=1; c<=9; ++c)
  {
    if (exists[c] && ! urbaaad[c]) ++ret;
  }
  
  printf("%d\n", ret);

  return 0;
}
