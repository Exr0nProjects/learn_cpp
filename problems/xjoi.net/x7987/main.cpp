/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem #7987
 * Tue 27 Aug 2019 @ 18:40 PDT)
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

void pd (string& n, const int cut=1)
{
  if (cut-1 == n.length()) return;
  printf("%c", n[n.length()-cut]);
  pd(n, cut+1);
  printf("%c", n[n.length()-cut]);
}

int main ()
{
  string n;
  cin >> n;
  
  pd(n);
  return 0;
}
