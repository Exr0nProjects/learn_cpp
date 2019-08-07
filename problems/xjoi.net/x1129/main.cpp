/*
 * Problem #1129
 * Wed 07 Aug 2019 @ 11:00 CST)
 * heads and legs
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
  int h, l;
  scanf("%d%d", &h, &l);
  
  int r = l/2-h;
  printf("%d\n%d", h-r, r);

  return 0;
}
