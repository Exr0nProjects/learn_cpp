/*
 * Problem #9521
 * Fri 02 Aug 2019 @ 08:31 CST
 * width of tree
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

#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 1; // todo

int sizes[MAXSZ];

int main ()
{
  int num, ans=0;
  scanf("%d", &num);
  for (int i=0; i<num; ++i)
  {
    for (int j=0; j<num; ++j)
    {
      int d;
      scanf("%1d", &d);
      if (d == 1)
      {
        sizes[i] += 1;
        sizes[j] += 1;
        ans = max(ans, max(sizes[i], sizes[j]));
      }
    }
  }
  
  printf("%d", ans-1);

  return 0;
}
