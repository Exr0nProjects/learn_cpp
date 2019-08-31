/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 7983 (xjoi.net/7983)
 * Created Fri 30 Aug 2019 @ 16:59 (PDT)
 * Accepted Fri 30 Aug 2019 @ 17:02 (PDT)
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

int f (const int n, const int c = 0)
{
  if (n == 1) return c;
  if (n % 2) return f(n*3+1, c+1);
  else return f(n/2, c+1);
}

int main ()
{
  int num;
  scanf("%d", &num);
  printf("%d", f(num));

  return 0;
}
