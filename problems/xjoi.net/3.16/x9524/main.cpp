/*
 * Problem #9524
 * Fri 02 Aug 2019 @ 11:06 CST)
 * number of leaf nodes
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

const int MAXSZ = 1000010; // todo

int main ()
{
  int ret = 0, ids[MAXSZ] = { };
  
  int num;
  scanf("%d\n", &num);
  
  for (int i=0; i<num; ++i)
  {
    int ans = 0;
    for (int j=0; j<num; ++j)
    {
      int d;
      scanf("%1d", &d);
      if (d == 1) ++ ans;
    }
    if (i > 0) --ans;
    if (ans == 0)
    {
      ids[ret] = i;
      ++ret;
    }
  }
  
  printf("%d\n", ret);
  for (int i=0; i<ret; ++i)
  {
    printf("%d ", ids[i]+1);
  }
  
  return 0;
}
