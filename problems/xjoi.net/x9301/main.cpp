/*
 * Problem #9301
 * Wed 07 Aug 2019 @ 12:13 CST)
 * quadratic equation
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
  LD a, b, c, a1, a2;
  scanf("%Lf%Lf%Lf", &a,  &b, &c);
  
  int d = (int)b*(int)b - 4*(int)a *(int)c;
  if (d < 0) printf("No Solution");
  else
  {
    a1 = (-1*b+sqrt(b*b-4*a*c))/2/a;
    a2 = (-1*b-sqrt(b*b-4*a*c))/2/a;
    if (d > 0) printf("%.2Lf %.2Lf", min(a1, a2), max(a1, a2));
    else printf("%.2Lf", a1);
  }
  
  return 0;
}
