/*
 * Problem #8358
 * Tue 06 Aug 2019 @ 22:43 CST)
 * moni cash using
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

CN int costs[] = {100, 50, 20, 10, 5, 1};

int main ()
{
  int num, ans=0;
  scanf("%d", &num);
  
  for (; num;)
  {
    int pt;
    for (pt=0; costs[pt]>num; ++pt);
    num -= costs[pt];
    ++ ans;
  }
  
  printf("%d", ans);
  
  return 0;
}
