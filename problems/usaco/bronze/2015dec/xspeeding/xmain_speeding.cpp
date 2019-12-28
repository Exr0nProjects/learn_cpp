/*
ID: spoytie2
TASK: speeding
LANG: C++14
*/

/*
 * Problem speeding (usaco/bronze/2015dec/speeding)
 * Created Sat 28 Dec 2019 @ 08:18 (PST)
 * Accepted Sat 28 Dec 2019 @ 08:28 (PST)
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

#define cn const int
#define ca const auto &
#define ll long long
#define cl const long long
#define UN unsigned
#define ST static
#define CN const
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
FILE* fin = fopen("speeding.in", "r");
FILE* fout = nullptr;

const int MAXSZ = 100; // todo
int limit[MAXSZ+10];
int spood[MAXSZ+10];
int L, S, ret=0;

int main ()
{
  if (fin) { fout = fopen("speeding.out", "w+"); } else { fin = stdin; fout = stdout; }
  
  fscanf(fin, "%d%d", &L, &S);
  int j=0;
  for (int i=0; i<L; ++i)
  {
    int l, s;
    fscanf(fin, "%d%d", &l, &s);
    l += j;
    for (; j<l; ++j)
      limit[j] = s;
  }

  j=0;
  for (int i=0; i<S; ++i)
  {
    int l, s;
    fscanf(fin, "%d%d", &l, &s);
    l += j;
    for (; j < l; ++j)
      spood[j] = s; // * the bug from originial write was that this said `limit[j] = s;` because I copy pasted from above
  }

  for (int i=0; i<MAXSZ; ++i)
  {
    ret = max(ret, spood[i]-limit[i]);
  }
  fprintf(fout, "%d\n", ret);

  return 0;
}
