/*
 * Problem #3902
 * Wed 07 Aug 2019 @ 11:04 CST)
 * sequence thing
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

int main ()
{
  int c=2, a=4;
  int num; scanf("%d", &num);
  
  LD ans=0;
  
  for (int i=0; i<num; ++i)
  {
    ans += (LD)1/(LD)c;
    c += a;
    a += 2;
  }
  
  printf("%.2Lf", ans);

  return 0;
}
