/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem 8101 (xjoi.net/8101)
 * Created Tue 10 Sep 2019 @ 18:57 (PDT)
 * Accepted Sun 15 Sep 2019 @ 13:44 (PDT)
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

const int MAXSZ = 100010; // todo

int main()
{
  int num, mmx, p=0, ret=0;
  scanf("%d%d", &num, &mmx);
  for (int i=0; i<num; ++i)
  {
    int c;
    scanf("%d", &c);
    if (c + p > mmx) 
    {
      ret += c+p-mmx;
      c -= c+p-mmx;
    }
    p = max(c, 0);
  }
  
  printf("%d", ret);

  return 0;
}
