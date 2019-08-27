/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem #1126
 * Tue 27 Aug 2019 @ 07:17 PDT)
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
  scanf("%d", &num);

  for (int i=0; i<=num; ++i) // should be i<=num?? todo
  {
    if (i % 3 == 2 && i % 5 == 3 && i % 7 == 2)
    {
      printf("%d\n", i);
    }
  }
  printf("\n");
  return 0;
}
