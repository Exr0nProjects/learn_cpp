// jan 2015 bronze cowroute 2 brute force, missing test case #4 (9/10)

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

void debug()
{
  printf("idx: ");
  for (int i=0; i<20; ++i)
  {
    printf("%3d", i);
  }
  printf("\nto:  ");
  for (int i=0; i<20; ++i)
  {
    if (to[i])
      printf("%3d", to[i]);
    else printf("  .");
  }
  printf("\nfrom:");
  for (int i=0; i<20; ++i)
  {
    if (from[i])
      printf("%3d", from[i]);
    else printf("  .");
  }
  printf("\n");
}

int main ()
{
  fscanf(fin, "%lld %lld %lld", &a, &b, &n);
  // scanf("%lld%lld%lld", &a, &b, &n);
  for (int i=0; i<n; ++i)
  {
    // input
    int c, m;
    fscanf(fin, "%d%d", &c, &m);
    // scanf("%d%d", &c, &m);
    
    vector<int> route;
    int s = m;
    for (int j=0; j<m; ++j)
    {
      int t;
      fscanf(fin, "%d", &t);
      // scanf("%d", &t);
      printf("%d: pushing back %d\n", i, t);
      if (t == a) s = j;
      route.push_back(t);
    }
    // from source to any transfer point
    for (; s<m; ++s) // going towards
    {
      // passed? logic taken care of in input, thru `s`
      if (to[route[s]] <= 0 || to[route[s]] > c) to[route[s]] = c; // store minimum cost from start to transfer
    }

    // from the end to the transfer point
    bool passed = false;
    for (int j=route.size()-1; j>=0; --j) // go backwards and check if dest is there
    {
      if (route[j] == b) passed = true;
      else if (passed)
      {
        if (from[route[j]] <= 0 || from[route[j]] > c) from[route[j]] = c; // stor minimum cost from transfer to end
      }
    }
  }
  
  debug();

  int gmin = -1;
  // check all the possible transfer points
  for (int i=1; i<=10000; ++i)
  {
    if (to[i] > 0 && from[i] > 0) // valid transfer point
    {
      if (gmin < 0 || to[i] + from[i] < gmin)
      {
        gmin = to[i] + from[i];
      }
    }
  }
  
  if (to[b] > 0 && (gmin < 0 || gmin > to[b])) // direct
  {
    gmin = to[b];
  }

  fprintf(fout, "%lld\n", gmin);
  //printf("%lld\n", gmin);

  return 0;
}

/*
1 2 3
3 3
3 2 1
4 4
2 1 4 3
8 5
4 1 7 8 2

 */
