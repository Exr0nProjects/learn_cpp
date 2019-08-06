/*
 * Problem #8364
 * Tue 06 Aug 2019 @ 22:38 CST)
 * mathy thing
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

int dfc (CN int cur)
{
  if (cur == 1) return 1;
  return dfc(cur-1) + cur * cur;
}

int main ()
{
  int num;
  scanf("%d", &num);
  
  printf("%d", dfc(num));
  
  return 0;
}
