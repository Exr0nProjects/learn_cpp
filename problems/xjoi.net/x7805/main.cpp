/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem 7805 (xjoi.net/7805)
 * Created Sun 15 Sep 2019 @ 07:11 (PDT)
 * Accepted Sun 15 Sep 2019 @ 07:14 (PDT)
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

int rec (const int num, const int i=1)
{
  if (i == num) return 1;
  return num/i + rec(num, i+1);
}

int main ()
{
  int num;
  scanf("%d", &num);

  printf("%d", rec(num));
  return 0;
}
