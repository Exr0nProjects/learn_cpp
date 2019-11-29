// jan 2015 bronze cowroute 1, missing test cases 2, 8, 9, 12 (9/12)

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
 auto fin = fopen("cowroute.in", "r");
 auto fout = fopen("cowroute.out", "w+");

const int MAXSZ = -1; // todo
LL a, b, n;

int main ()
{
  LL cmin = -1;
  fscanf(fin, "%lld %lld %lld", &a, &b, &n);
  for (LL i=0; i<n; ++i) // for each route
  {
    LL c, m;
    fscanf(fin, "%lld%lld", &c, &m);
    printf("%d\n", i);

    bool first = false;
    for (LL j=0; j<m; ++j) // for each stop
    {
      LL t;
      fscanf(fin, "%lld", &t);
      if (t == a) first = true; // visited a
      if (t == b && first) // then visited b => success!
      {
        if (cmin < 0 || cmin > c)
        {
          cmin = c;
        }
        break;
      }
    }
  }

  fprintf(fout, "%lld\n", cmin);

  return 0;
}

/*
// no route
1 2 1
2 2
1 3
 => -1

// backwards
1 2 1
2 2
2 1
 => -1

// min changes
1 4 2
8 4
1 2 3 4
4 2
1 4
 => 4

// better route but it doesn't work
1 4 2
8 4
1 2 3 4
4 2
1 3
 => 8

// visits first but not second
1 4 1
8 3
1 2 3
 => -1

// visits second but not first
1 4 1
8 3
2 3 4
 => -1

// visits first on one and second on another
1 4 2
2 3
1 2 3
2 3
2 3 4
 => -1
 
// lots of routes
 works!
 => 1

// worse routes later
1 4 3
4 3
1 2 4
8 3
1 3 4
2 3
1 2 3
 => 4
 */
