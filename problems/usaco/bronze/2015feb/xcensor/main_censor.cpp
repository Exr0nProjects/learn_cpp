/*
ID: spoytie2
TASK: censor
LANG: C++14                 
*/

/*
 * Problem censor (usaco/bronze/feb2015/censor)
 * Created Sun 01 Dec 2019 @ 11:49 (PST)
 * Accepted [!meta:end!]
 * 
 * first try finished at 12:06, 7/15 test cases, others TLE
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
#define ca const auto &
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
FILE* fin = fopen("censor.in", "r");
FILE* fout = nullptr;

const unsigned long MAXSZ = 1000000; // todo



int main ()
{
  if (fin) { fout = fopen("censor.out", "w+"); } else { fin = stdin; fout = stdout; }
  freopen("censor.in", "r", stdin);
  string s, c;
  cin >> s >> c;

  size_t i = s.find(c);
  while(i < MAXSZ)
  {
    s = s.substr(0, i) + s.substr(i+c.length());
    i = s.find(c);
  }

  fprintf(fout, "%s", s.c_str());

  return 0;
}
