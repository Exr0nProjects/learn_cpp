/*
ID: spoytie2
TASK: censor
LANG: C++14                 
*/

/*
 * Problem censor (usaco/bronze/feb2015/censor)
 * Created Sun 01 Dec 2019 @ 13:42 (PST)
 * Accepted [!meta:end!]
 * 
 * working on analysing the problem, hopefully will result in a better algorithm.
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
FILE *fin = fopen("censor.in", "r");
FILE *fout = nullptr;

const unsigned long MAXSZ = 1000000; // todo

int main()
{
  if (fin)
  {
    fout = fopen("censor.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }
  freopen("censor.in", "r", stdin);
  string s, c;
  cin >> s >> c;

  for (int i=0; i<s.length(); ++i)
  {
    bool yeetus = true;
    for (int j=0; j<c.length(); ++j)
    {
      if (s[i+j] != c[j])
      {
        yeetus=false;
        break;
      }
    }
    if (yeetus)
    {
      s.erase(i, c.length());
      i = max(i-(int)c.length(), -1); // j gets incremented immedietly after
    }
  }

  fprintf(fout, "%s", s.c_str());

  return 0;
}
