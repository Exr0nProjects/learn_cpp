/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem 7801 (xjoi.net/7801)
 * Created Sun 15 Sep 2019 @ 14:21 (PDT)
 * Accepted Sun 15 Sep 2019 @ 14:26 (PDT)
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

int rsum (cn n)
{
  if (n == 0) return 0;
  int t;
  scanf("%d", &t);
  return t + rsum(n-1);
}

int main ()
{
  int num;
  scanf("%d", &num);

  printf("%d", rsum(num));
  
  return 0;
}
