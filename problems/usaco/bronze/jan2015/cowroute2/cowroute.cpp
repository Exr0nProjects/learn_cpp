// jan 2015 bronze cowroute 2 brute force

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

const int MAXSZ = 10010; // todo
LL a, b, n;

LL to[MAXSZ];
LL from[MAXSZ];

int main ()
{
  fscanf(fin, "%lld %lld %lld", &a, &b, &n);
  for (int i=0; i<n; ++i)
  {
    // input
    int c, m;
    fscanf(fin, "%d%d", &c, &m);
  
    vector<int> route;
    for (int j=0; j<m; ++j)
    {
      int t;
      fscanf(fin, "%d", &t);
      route.push_back(t);
    }
    // from source to any transfer point
    bool passed = false; // for the first pass
    for (int j=0; j<route.size()-1; ++j) // going towards
    {
      if (route[j] == a) passed = true;
      else if (passed)
      {
        if (to[route[j]] <= 0 || to[route[j]] > c) to[route[j]] = c; // store minimum cost from start to transfer
      } 
    }

    // from the end to the transfer point
    passed = false;
    for (int j=route.size()-1; j>=0; --j) // go backwards and check if dest is there
    {
      if (route[j] == b) passed = true;
      else if (passed)
      {
        if (from[route[j]] <= 0 || from[route[j]] > c) from[route[j]] = c; // stor minicum cost from transfer to end
      }
    }
  }

  int gmin = -1;
  // check all the possible transfer points
  for (int i=1; i<=10000; ++i)
  {
    if (to[i] > 0 && from[i] > 0) // valid transfer point
    {
      if (gmin < 0 || to[i] + from[i] > gmin)
      {
        gmin = to[i] + from[i];
      }
    }
  }

  fprintf(fout, "%lld\n", gmin);

  return 0;
}
