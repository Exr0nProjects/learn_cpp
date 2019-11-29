// jan 2015 bronze cowroute 1, missing #2, 8, 9, 12

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
int a, b, n;

int main ()
{
  int cmin = -1;
  fscanf(fin, "%d%d%d", &a, &b, &n);
  for (int i=0; i<n; ++i)
  {
    int c, m;
    fscanf(fin, "%d%d", &c, &m);

    bool first = false;
    for (int j=0; j<m; ++j)
    {
      int t;
      fscanf(fin, "%d", &t);
      if (t == a) first = true; // visited a
      if (t == b && first) // then visited b => success!
      {
        cmin = (cmin < 0 ? c : min(c, cmin)); // min between c, cmin if cmin is inited
        break;
      }
    }
  }

  fprintf(fout, "%d\n", cmin);

  return 0;
}