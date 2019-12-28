/*
ID: spoytie2
TASK: paint
LANG: C++14
*/

/*
 * Problem paint (usaco/bronze/2015dec/paint)
 * Created Sat 28 Dec 2019 @ 08:11 (PST)
 * Accepted Sat 28 Dec 2019 @ 08:17 (PST)
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
FILE* fin = fopen("paint.in", "r");
FILE* fout = nullptr;

const int MAXSZ = 110; // todo
bool painted[MAXSZ];
int a, b, c, d;


int main ()
{
  if (fin) { fout = fopen("paint.out", "w+"); } else { fin = stdin; fout = stdout; }
  fscanf(fin, "%d%d%d%d", &a, &b, &c, &d);
  for (int i=a; i<b; ++i) painted[i] = 1;
  for (int i=c; i<d; ++i) painted[i] = 1;
  
  ll ret = 0;
  for (int i=0; i<MAXSZ; ++i)
  {
    ret += painted[i];
  }
  fprintf(fout, "%lld\n", ret);

  return 0;
}
