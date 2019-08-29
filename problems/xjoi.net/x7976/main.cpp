/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem #7976
 * Wed 28 Aug 2019 @ 19:39 PDT)
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

void f (const int n)
{
  if (n == 1) { printf("1 "); return; }
  f(n/2);
  printf("%d ", n);
  f(n-n/2);
}
int main ()
{
  int num;
  scanf("%d", &num);
  
  f(num);
  
  return 0;
}
