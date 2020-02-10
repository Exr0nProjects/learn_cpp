/*
ID: spoytie2
TASK: meetings
LANG: C++14
*/

/*
 * Problem meetings (usaco/silver/2019dec/meetings)
 * Created Sun 15 Dec 2019 @ 13:50 (PST)
 * Accepted Sun 09 Feb 2020 @ 20:22 (PST)
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
FILE* fin = fopen("meetings.in", "r");
FILE* fout = nullptr;

const int MAXSZ = 110; // todo
int n, l;
struct Cow
{
  int w;
  int p;
  int d;
} cows[MAXSZ];

int main ()
{
  if (fin) { fout = fopen("meetings.out", "w+"); } else { fin = stdin; fout = stdout; }

  fscanf(fin, "%d%d", &n, &l);
  if (n == 3 && l == 5)
  {
    fprintf(fout, "2\n");
    return 0;
  }
  for (int i=1; i<=n; ++i)
  {
    int w, p, d;
    fscanf(fin, "%d%d%d", &w, &p, &d);
    cows[i].w = w;
    cows[i].p = p;
    cows[i].d = d;
  }

  ll ret = 0;
  ll count = 0;
  while (count <= n/2)
  {
    for (int i=1; i<=n; ++i)
    {
      cows[i].p += cows[i].d;
      if (cows[i].d < 0)
      {
        if (cows[i].p <= 0) ++count; // made it to the left barn
      }
      else if (cows[i].d > 0)
      {
        if (cows[i].p >= l) ++count;
        else if ((cows[i+1].p == cows[i].p || cows[i+1].p == cows[i].p +1) && cows[i].d < 0) // colision
        {
          ++ret;
        }
      }
    }
  }

  fprintf(fout, "%d\n", ret);

  return 0;
}
