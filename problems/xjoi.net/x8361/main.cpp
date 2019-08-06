/*
 * Problem #8361
 * Tue 06 Aug 2019 @ 22:34 CST)
 * min sum
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
  int m=0, s=0, t;
  for (int i=0; i<3; ++i) {
    scanf("%d", &t);
    s += t;
    m = max(m, t);
  }
  
  printf("%d", s-m);

  return 0;
}
