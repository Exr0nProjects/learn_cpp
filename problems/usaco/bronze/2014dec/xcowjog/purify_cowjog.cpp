/*
ID: spoytie2
TASK: cowjog
LANG: C++14                 
*/

/*
 * Problem cowjog (usaco/bronze/dec2014/cowjog)
 * Created Thu 12 Dec 2019 @ 19:00 (PST)
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
FILE *fin = fopen("cowjog.in", "r");
FILE *fout = nullptr;

const int MAXSZ = -1; // todo
int n;

int main()
{
  if (fin)
  {
    fout = fopen("cowjog.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }
  fscanf(fin, "%d", &n);
  vector<int> spood;
  for (int i = 0; i < n; ++i)
  {
    int _, s;
    fscanf(fin, "%d%d", &_, &s);
    spood.push_back(s);
  }

  reverse(spood.begin(), spood.end());

  int s = -1, count = 0;
  for (int p : spood)
  {
    if (s < 0 || s >= p)
    {
      s = p;
      ++count;
    }
  }

  fprintf(fout, "%d\n", count);

  return 0;
}
