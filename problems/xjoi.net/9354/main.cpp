/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 9354 (xjoi.net/9354)
 * Created Sun 01 Sep 2019 @ 16:36 (PDT)
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

int main ()
{
  int num;
  for (int i=0; i<4; ++i)
  {
    int d;
    scanf("%d", &d);
    if (d == 1) ++num;
  }

  switch (num)
  {
    case 1:
      num = 3; break;
    case 2: 
      num = 2; break;
    case 3:
      num = 1; break;
    case 4:
      num = 4; break;
  }

  printf("%d", num);

  return 0;
}
