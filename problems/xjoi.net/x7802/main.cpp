/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 7802 (xjoi.net/7802)
 * Created Sun 15 Sep 2019 @ 14:29 (PDT)
 * Accepted Sun 15 Sep 2019 @ 14:32 (PDT)
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

int main ()
{
  int num, mn=10000000, mx=0;
  scanf("%d", &num);

  for (int i=0; i<num; ++i)
  {
    int t;
    scanf("%d", &t);
    mn = min(mn, t);
    mx = max(mx, t);
  }

  printf("%d", mx-mn);

  return 0;
}
