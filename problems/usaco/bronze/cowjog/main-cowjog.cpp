/*
ID: spoytie2
TASK: cowjog
LANG: C++14
*/

/*
 * Problem cowjog (usaco/bronze/cowjog)
 * Created Wed 27 Nov 2019 @ 12:02 (PST)
 * Accepted [!meta:end!]
 * problem # 489
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
 auto fin = fopen("cowjog.in", "r");
 auto fout = fopen("cowjog.out", "w+");

const int MAXSZ = 1; // todo
int n;

int main ()
{
  fscanf(fin, "%d", &n);
  int groups = 0, slowest = -1, prev = -1;
  for (int i=0; i<n; ++i)
  {
    int p, s;
    fscanf(fin, "%d%d", &p, &s);
    // check
    if (s < slowest || slowest == -1)
    {
      groups ++;
      slowest = s;
    }
    else if (s == slowest)
    {
      if (p > prev + 1 || prev == -1) // another group will form
      {
        groups ++;
      }
    }

    // update
    prev = p;
  }

  fprintf(fout, "%d\n", groups);

  return 0;
}
