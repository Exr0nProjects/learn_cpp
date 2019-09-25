/*
 * Problem #8806
 * Fri 02 Aug 2019 @ 16:08 CST)
 * father given binary tree
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

#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 1010; // todo

int parents[MAXSZ] =  {0, -1};

int main ()
{
  int num;
  scanf("%d\n", &num);
  for (int i=1; i<=num; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a>0) parents[a] = i;
    if (b>0) parents[b] = i;
  }
  
  for (int i=1; i<=num; ++i)
  {
    printf("%d ", parents[i]);
  }
  
  return 0;
}
