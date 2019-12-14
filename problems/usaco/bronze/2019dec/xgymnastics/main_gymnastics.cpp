/*
ID: spoytie2
TASK: gymnastics
LANG: C++14
*/

/*
 * Problem gymnastics (usaco/bronze/2019dec/gymnastics)
 * Created Sat 14 Dec 2019 @ 11:13 (PST)
 * Accepted [!meta:end!]
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
FILE *fin = fopen("gymnastics.in", "r");
FILE *fout = nullptr;

const int MAXSZ = 30;      // todo
int ranking[MAXSZ][MAXSZ]; // i = cow id, j = session id
int n, k;

int main()
{
  if (fin)
  {
    fout = fopen("gymnastics.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }
  fscanf(fin, "%d%d", &k, &n);

  if (n < 2)
  {
    fprintf(fout, "%d\n", n);
    return 0;
  }
  for (int j = 1; j <= k; ++j)
  {
    for (int i = 1; i <= n; ++i)
    {
      int c;
      fscanf(fin, "%d", &c);
      ranking[c][j] = i;
    }
  }

  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= k; ++j)
    {
      printf("%3d", ranking[i][j]);
    }
    printf("\n");
  }

  ll ret = 0;
  // for all pairs of cows
  for (int c1 = 1; c1 <= n; ++c1)
  {
    for (int c2 = c1 + 1; c2 <= n; ++c2)
    {
      if (k < 2)
      {
        ++ret;    // all pairs are consistent therefore this one must be too
        continue; // no need to do math.
      }
      bool which = ranking[c1][1] < ranking[c2][1];
      for (int j = 2; j <= k; ++j)
      {
        if ((ranking[c1][j] < ranking[c2][j]) != which)
          break;
        if (j == k)
          ++ret; // this pair works if we checked all sessions
      }
    }
  }

  fprintf(fout, "%lld\n", ret);

  return 0;
}

/*
 
1 1
1
 => 1
 
5 1
1
1
1
1
1
=> 1
 
5 2
1 2
1 2
2 1
1 2
1 2
 => 0
 
4 2
1 2
1 2
1 2
1 2
 => 1

1 3
1 3 2
 => 3
 
 */
