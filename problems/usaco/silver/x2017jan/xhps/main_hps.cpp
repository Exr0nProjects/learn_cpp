/*
ID: spoytie2
TASK: hps
LANG: C++14
*/

/*
 * Problem hps (usaco/silver/2017jan/hps)
 * Create time: Fri 17 Jan 2020 @ 16:40 (PST)
 * Accept time: [!meta:end!]
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
#include <cstring>
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
FILE *fin = fopen("hps.in", "r");
FILE *_ = stderr;

const int MAXSZ = 100010; // todo
int N;
int num[MAXSZ][5];

inline int conv(const char &c)
{
  int ret = 0;
  if (c == 'H') ret = 1;
  if (c == 'P') ret = 2;
  if (c == 'S') ret = 3;
  return ret;
}

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("hps.out", "w+"); }
  int N;
  scanf("%d", &N);
  for (int i=1; i<=N; ++i)
  {
    char c;
    scanf("\n%c", &c);
    ++num[i][conv(c)];

    for (int j=1; j<4; ++j)
    {
      num[i][j] += num[i-1][j];
//      printf("%3d", num[i][j]);
    }
//    fprintf(_, "\n");
  }

  int ret = 0;
  for (int i=1; i<=N; ++i) // see if switching at this one would be helpful
  {
    int t=0;
    for (int a=1; a<4; ++a)
    {
      for (int b=1; b<4; ++b)
      {
        t = max(t, num[N][b]-num[i][b] + num[i][a]);
      }
    }
//    printf("swapping at %d yields %d\n", i, t);
    ret = max(ret, t); // could just put ret in the triple nested loop but i wanted to be able to have debug output
  }

  printf("%d\n", ret);

  return 0;
}
