/*
ID: spoytie2
TASK: whatbase
LANG: C++14
*/

/*
 * Problem whatbase (usaco/bronze/jan2015/whatbase)
 * Created Sat 30 Nov 2019 @ 09:51 (PST)
 * Accepted [!meta:end!]
 * solution method from http://usaco.org/current/data/sol_whatbase_bronze.html (the answer)
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
FILE* fin = fopen("whatbase.in", "r");
FILE* fout = nullptr;

const int MAXSZ = 15000; // todo

int eval(string n, cn b)
{
  return (n[0]-'0') *b*b + (n[1]-'0')*b + (n[2]-'0');
}

int main ()
{
  if (fin) { fout = fopen("whatbase.out", "w+"); } else { fin = stdin; fout = stdout; }
  int n;
  fscanf(fin, "%d", &n);
  for (int i=0; i<n; ++i)
  {
    char a[8], b[8];
    fscanf(fin, "%s%s", a, b);
    // this works because any number Nxb is less than Nxb+1, therefore we can treat b as the index in a sorted array
    // thus we are looking for two numbers in sorted arrays that are the same value, so we crawl each array up, indexing whichever arr_idx is mapped to the smaller value
    for (int x=10, y=10; x<=MAXSZ && y<=MAXSZ;)
    {
      int _x = eval((string) a, x);
      int _y = eval((string) b, y);
      if (_x == _y)
      {
        fprintf(fout, "%d %d\n", x, y);
        break;
      }
      else if (_x > _y)
      {
        ++y;
      }
      else if (_y > _x)
      {
        ++x;
      }
    }
  }

  return 0;
}
