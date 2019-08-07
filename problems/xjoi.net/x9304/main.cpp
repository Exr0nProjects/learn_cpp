/*
 * Problem #9304
 * Wed 07 Aug 2019 @ 11:25 CST)
 * disjoint function
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
  LD num; scanf("%Lf", &num);
  
  if (num < 2) NULL;
  else if (num < 6) num = num*num+1;
  else if (num < 10) num = sqrt(num + 1);
  else num = 1/(num+1);
  
  printf("%.2Lf", num);

  return 0;
}
