/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem 8309 (xjoi.net/8309)
 * Created Sun 15 Sep 2019 @ 07:33 (PDT)
 * Accepted Sun 15 Sep 2019 @ 07:37 (PDT)
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

cn MAXSZ = 1; // todo

void fib (cn m, cn a=1, cn b=1)
{
  if (m == 0) return;
  printf("%d ", a);
  fib(m-1, b, a+b);
}

int main ()
{
  int num;
  scanf("%d", &num);
  fib(num);
  return 0;
}
