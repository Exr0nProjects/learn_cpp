/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem 9403 (xjoi.net/9403)
 * Created Sun 15 Sep 2019 @ 14:59 (PDT)
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

const int MAXSZ = 10010; // todo
int bricks[MAXSZ];
int num, siz;

int main ()
{
  scanf("%d%d", &num, &siz);
  num -= (siz-1);
  
  LL ret = 1;
  for (int i=0; i<num; ++i)
  {
    scanf("%d", &siz);
    ret <<= 1;
    ret %= 1000000007;
  }
  
  printf("%lld", ret-1);
  
  return 0;
}

/*
 1 1
 10
 
 4 1
 1 2 3 100
 */
