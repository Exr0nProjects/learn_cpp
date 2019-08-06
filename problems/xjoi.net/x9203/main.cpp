/*
 * Problem #9203
 * Tue 06 Aug 2019 @ 21:47 CST)
 * reverse num
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

const int MAXSZ = 1; // todo

int main ()
{
  int a[3], m=0;
  for (int i=0; i<3; ++i) { scanf("%1d", &(a[i])); m = max(m, a[i]); }
  
  for (int i=2; i>=0; --i) ((a[i]==0 && i==2)?NULL:printf("%d", a[i]));
    
    return 0;
}
