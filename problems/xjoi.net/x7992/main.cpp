/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem #7992
 * Tue 27 Aug 2019 @ 07:08 PDT)
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

int gcd (const int a, const int b)
{
  if (b == 0) return a;
  return gcd(b, a%b);
}
int main ()
{
  int a, b;
  scanf("%d%d", &a, &b);

  printf("%d", gcd(a, b));

  printf("\n");
  return 0;
}
