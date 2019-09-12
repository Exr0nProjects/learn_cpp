/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 1320 (1320)
 * Created Thu 12 Sep 2019 @ 07:26 (PDT)
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

const int MAXSZ = 10010; // todo
struct Customer
{
  int b, e;
  bool operator< (const Customer& o) { return e < o.e; }
} arr[MAXSZ];

int main ()
{
  int num;
  scanf("%d", &num);
  for (int i=0; i<num; ++i)
  {
    scanf("%d%d", &arr[i].b, &arr[i].e);
  }

  sort(arr, arr+num);

  int ret = 1, end = arr[0].e;
  for (int i=1; i<num; ++i)
  {
    if (arr[i].b >= end)
    {
      ++ret;
      end = arr[i].e;
    }
  }

  printf("%d", ret);

  return 0;
}
