/*
ID: spoytie2
TASK: paint
LANG: C++14
*/

/*
 * Problem paint (usaco/bronze/2015dec/paint)
 * Created Sat 28 Dec 2019 @ 08:11 (PST)
 * Accepted [!meta:end!]
 ! an implementation of the second method described in the usaco problem analysis by Nick Wu (mathy)
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
int a, b, c, d;


int main ()
{
  if (fin) { fout = fopen("paint.out", "w+"); } else { fin = stdin; fout = stdout; }
  
  fscanf(fin, "%d%d%d%d", &a, &b, &c, &d);
  // ensure a starts first
  if (c < a)
  {
    swap(a, c);
    swap(b, d);
  }
  
  if (b <= c) // no overlap
    fprintf(fout, "%d\n", b-a + d-c);
  else // overlap
    fprintf(fout, "%d\n", max(b, d) - a);

  return 0;
}
