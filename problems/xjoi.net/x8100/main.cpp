/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem 8100 (xjoi.net/8100)
 * Created Sun 08 Sep 2019 @ 14:30 (PDT)
 * Accepted Sun 08 Sep 2019 @ 14:53 (PDT)
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

const int MAXSZ = 1010000; // todo
struct Person
{
  int i, t;
} line[MAXSZ];

int main()
{
  int num;
  scanf("%d", &num);

  if (num == 0)
  {
    printf("\n0");
    return 0;
  }

  for (int i = 0; i < num; ++i)
  {
    scanf("%d", &line[i].t);
    line[i].i = i;
  }

  stable_sort(line, line + num, [](const Person &lhs, const Person &rhs) { return lhs.t < rhs.t; });

  long double avg = 0, wait = 0;
  for (int i = 0; i < num; ++i)
  {
    printf("%d ", line[i].i + 1);
    avg += wait;
    wait += line[i].t;
  }
  printf("\n%.2Lf", avg / num);

  return 0;
}

/*
10
56 12 1 99 1000 234 33 55 99 812
*/
