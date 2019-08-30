/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem 7080 (xjoi.net/7080)
 * Created Fri 30 Aug 2019 @ 16:48 (PDT)
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

void r (const int n)
{
  if (n == 0) return;
  r(n/10);
  printf("%d\n", n%10);
}

int main ()
{
  int num;
  scanf("%d", &num);
  r(num);
  
  return 0;
}
