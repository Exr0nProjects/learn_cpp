/*
 * Problem #9522
 * Fri 02 Aug 2019 @ 11:01 CST)
 * children of each node
 */
 
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

int main ()
{
  int num; 
  scanf("%d\n", &num);
  for (int i=0; i<num; ++i)
  {
    int ans=0;
    for (int j=0; j<num; ++j)
    {
      int d;
      scanf("%1d", &d);
      if (d == 1) ++ ans;
    }
    if (i > 0) --ans;
    printf("%d ", &ans);
  }

  return 0;
}
