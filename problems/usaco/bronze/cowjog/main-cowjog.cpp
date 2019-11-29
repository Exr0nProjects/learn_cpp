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
  LL groups = 0, slowest = -1, prev = -1, spos = -1, spad = 0;
  for (int i=0; i<n; ++i)
  {
    int p, s;
    fscanf(fin, "%d%d", &p, &s);
    // check
    if (s < slowest || slowest == -1)
    {
      groups ++;
      slowest = s;
      spos = p;
      spad = 0;
    }
    else if (s == slowest)
    {
      if (p > spos+spad) // another group will form
      {
        groups ++;
        spos = p;
        spad = 0;
      }
    }

    // update
    ++spad;
  }

  fprintf(fout, "%d\n", groups);

  return 0;
}

/*
5
0 1
1 2
2 3
3 2
6 1
 => 2
 
5
0 5
1 5
2 4
4 5
5 4
 => 3
1
0 1
 => 1
20
1 1
2 1
3 1
4 1
5 1
6 1
7 1
8 1
9 1
10 1
11 1
12 1
13 1
14 1
15 1
16 1
17 1
18 1
19 1
20 1
 => 1

9
1 1
2 1
3 1
4 1
6 2
7 1
8 1
9 1
10 1
 => 2
 */