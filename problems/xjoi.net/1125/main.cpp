/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 1125 (xjoi.net/1125)
 * Created Sat 21 Sep 2019 @ 11:59 (PDT)
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

int f (const int n, c=1)
{
  if (n == 1) return c;
  return f(n-1, (c+1)*2);
}

int main ()
{
  int n;
  scanf("%d", &n);

  printf("%d", f(n));

  return 0;
}
