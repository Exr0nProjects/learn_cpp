/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem #7074
 * Tue 27 Aug 2019 @ 08:39 PDT)
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

const LL gcd (const LL a, const LL b)
{
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main ()
{
  LL a, b;
  scanf("%lld%lld", &a, &b);

  printf("%lld", gcd(a, b));
  return 0;
}
