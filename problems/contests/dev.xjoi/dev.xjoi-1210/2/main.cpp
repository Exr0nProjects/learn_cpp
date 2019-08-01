/*
 * dev.xjoi.net 1210 p2
 * 29 July 2019
 */

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

#define ll long long
#define dl double
#define ld long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 10000; // todo
int connect[MAXSZ][MAXSZ];
int mmax = 0;

bool dfc (const int siz, const int rem, bool pairs[MAXSZ], const int funcmin=1*pow(10, 9), const int starti=0, int startj=0)
{
  if (rem <= 0)
  {
    mmax = max(mmax, funcmin);
    return false;
  }
  for (int i=starti; i<siz; ++i)
  {
    if (pairs[i]) continue;
    for (int j=startj; j<siz; ++j)
    {
      if (pairs[j] || connect[i][j] == 0) continue;
      if (funcmin < mmax) return true;
      pairs[i] = true;
      pairs[j] = true;
      if (dfc(siz, rem-2, pairs, min(funcmin, connect[i][j]), i, j)) return true;
    }
    startj = 0;
  }
  if (mmax == 0) { printf("no answer"); exit(0); }
  return true; // this shouldnt actually ever happen
}

int main ()
{
  int num;
  scanf("%d", &num);
  for (int i=0; i<num; ++i)
  {
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    connect[n-1][m-1] = t;
    connect[m-1][n-1] = t;
  }
//
//  for (int i=0; i<num; ++i)
//  {
//    for (int j=0; j<num; ++j)
//    {
//      printf("%3d ", connect[i][j]);
//    }
//    printf("\n");
//  }
//
  bool pairs[MAXSZ] = { };
  
  dfc(num, num, pairs);
  
  printf("%d", mmax);
  
  return 0;
}
