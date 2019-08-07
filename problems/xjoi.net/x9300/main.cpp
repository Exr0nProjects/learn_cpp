/*
 * Problem #9300
 * Wed 07 Aug 2019 @ 12:34 CST)
 * property count
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
  int a, c, w=0, b=0, h=0, d=0;
  for (int i=0; i<5; ++i)
  {
    scanf("%d%d", &a, &c);
    if (a == 0) ++ w;
    else ++ b;
    if (c == 2) ++ h;
    else ++ d;
  }
  
  printf("%d %d %d %d", w, b, h,d);
  
  return 0;
}
