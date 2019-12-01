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

string dqm(const string s, const string t) // Divide conQuer Merge
{
  if (s.length() < t.length()) return s; // conquer

  // divide
  string a = dqm(s.substr(0, s.length()/2), t);
  string b = dqm(s.substr(s.length()/2));
  // shift around so we can KMP the back part of a (the middle part)
  a = a + b.substr(0, t.length());
  b = b.substr(t.length());
  // merge
  a = a.replace(a.find(t, max(a.length()-2*t.length(), 0)), t.length(), ""); // delete any t that we find.
}

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

  size_t i = s.find(c);
  while (i < MAXSZ)
  {
    s = s.substr(0, i) + s.substr(i + c.length());
    i = s.find(c);
  }

  fprintf(fout, "%s", s.c_str());

  return 0;
}
