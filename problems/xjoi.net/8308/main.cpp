/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 8308 (xjoi.net/8308)
 * Created Sun 15 Sep 2019 @ 07:25 (PDT)
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

void rec(const int m, const int c=1, const int p=3)
{
  if (c == m) return;
  printf("%d ", p);
  rec(m, c+1, p + (c+1)*2);
}

int main ()
{
  int num;
  scanf("%d", &num);
  rec(num);
  return 0;
}
