/*
ID: spoytie2
TASK: bcount
LANG: C++14
*/

/*
 * Problem bcount (usaco/silver/2015dec/bcount)
 * Create time: Fri 10 Jan 2020 @ 16:10 (PST)
 * Accept time: Fri 10 Jan 2020 @ 16:33 (PST)
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
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <string>
#include <vector>
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
FILE *fin = fopen("bcount.in", "r");
FILE *_ = stderr;

const int MAXSZ = 100010; // todo
int N, Q;
int bcount[MAXSZ][5];

void debug()
{
  fprintf(_, "\n");
  for (int i = 0; i <= N; ++i)
    fprintf(_, "%3d", i);
  fprintf(_, "\n");
  for (int j = 1; j < 4; ++j)
  {
    for (int i = 0; i <= N; ++i)
      fprintf(_, "%3d", bcount[i][j]);
    fprintf(_, "\n");
  }
}

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("bcount.out", "w+"); }
  scanf("%d%d", &N, &Q);
  for (int i=1; i<=N; ++i)
  {
    // fprintf(_, "\n\n------\n");
    for (int j = 0; j < 5; ++j)
    {
      bcount[i][j] = bcount[i - 1][j];
      // fprintf(_, "    %d, %d reads %d\n", i, j, bcount[i][j]);
    }

    int b;
    scanf("%d", &b);
    ++bcount[i][b];

    // fprintf(_, "%d: %d\n", i, b);

    // debug();
  }

  for (int i=0; i<Q; ++i)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    for (int i=1; i<4; ++i)
    {
      printf("%d%c", bcount[r][i]-bcount[l-1][i], i==3?'\n':' ');
    }
  }

  return 0;
}
