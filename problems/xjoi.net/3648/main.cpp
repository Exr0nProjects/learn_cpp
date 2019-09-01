/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem #3648
 * Wed 28 Aug 2019 @ 19:46 PDT)
 * status: TLE? 
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
  string s;
  cin >> s;

  for (int i=s.length(); i>0; --i)
  {
    printf("%c", s[i-1]);
  }

  return 0;
}
