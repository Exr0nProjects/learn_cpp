/*
 * Problem #8353
 * Tue 06 Aug 2019 @ 19:59 CST)
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
  int num, ans=0;
  scanf("%d", &num);
  if (! (num&1))
  {
    ans += num;
    -- num;
  }
  
  printf("%d", ans + (num/2+1)*num);

  return 0;
}
