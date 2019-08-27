/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem #3647
 * Tue 27 Aug 2019 @ 07:21 PDT)
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

inline int fbi (const int r, const int a=0, const int b=1)
{
  if (r == 1) return a;
  return fbi(r-1, b, a+b);
}
int main ()
{
  // FILE* fin = fopen("fbi.in", "r");
  // FILE* fout = fopen("fbi.out", "w+");

  int num;
  // fscanf(fin, "%d", &num);
  scanf("%d", &num);

  // fprintf(fout, "%d", fbi(num));
  printf("%d", fbi(num));
  return 0;
}
