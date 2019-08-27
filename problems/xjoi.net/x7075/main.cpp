/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem #7075
 * Tue 27 Aug 2019 @ 08:28 PDT)
 *
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

LL g(const LL x, const LL y)
{
  if (x <= 0 || y <= 0)
    return 1;
  return g(x - 1, y) + 2 * g(x - 1, y - 1) + 3 * g(x, y - 1);
}

int main()
{
  LL a, b;
  scanf("%lld%lld", &a, &b);

  printf("%lld", g(a, b));

  return 0;
}
