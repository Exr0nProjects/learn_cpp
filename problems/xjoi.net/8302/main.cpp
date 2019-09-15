/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem 8302 (xjoi.net/8302)
 * Created Sun 15 Sep 2019 @ 14:33 (PDT)
 * Accepted [!meta:end!]
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

#define cn const int
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

int f (const int n)
{
  return n*n+2;
}

int g (cn n)
{
  int s = 0;
  for (int i=1; i<=n; ++i)
    s += f(i);
  
  return s;
}

int main ()
{
  int n;
  scanf("%d", &n);

  int s = 0;
  for (int i=1; i<=n; ++i)
  {
    s += g(i);
  }
  
  printf("%d", s);
  
  return 0;
}
