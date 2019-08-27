/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem #7974
 * Tue 27 Aug 2019 @ 07:33 PDT)
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

const LL dfc(const LL r, const LL c = 1)
{
  if (r == 1)
    return c;
  return c * (dfc(r - 1, c + 1) % 998244353);
}
int main()
{
  LL num;
  scanf("%lld", &num);
  printf("%lld", dfc(num) % 998244353);
  return 0;
}
