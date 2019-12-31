/*
ID: spoytie2
TASK: trapped
LANG: C++14
*/

/*
 * Problem trapped (usaco/bronze/2015open/trapped)
 * Created Tue Dec 31 2019 @ earlier (PST)
 * Accepted Tue 31 Dec 2019 @ 12:27 (PST)
 *
 */


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
FILE *fin = fopen("trapped.in", "r");
FILE *fout = nullptr;

const int MAXSZ = 4050; // todo
ll n;
vector<pair<int, int> > bales; // first  = pos  second =  size

bool ram(int l, int r)
{
  if (l < 0 || r >= bales.size()) return true;
  
  if (bales[r].first - bales[l].first > bales[r].second)
  {
    ++r;
  }
  else if (bales[r].first  -bales[l].first > bales[l].second)
  {
    --l;
  }
  else
  {
    return false;
  }
  
  return ram(l, r);
}

int main()
{
  if (fin)
  {
    fout = fopen("trapped.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }
  fscanf(fin, "%lld", &n);
  printf("n=%d\n", n);

  for (int i=0; i<n; ++i)
  {
    int s, p;
    fscanf(fin, "%d%d", &s, &p);
    printf("bale @%d with %d\n", p, s);
    bales.push_back(make_pair(p, s));
  }
  
  stable_sort(bales.begin(), bales.end());
  
  int ret=0;
  for  (int i=1; i<n; ++i)
  {
    if (!ram(i-1, i)) ret += bales[i].first - bales[i-1].first;
  }

  fprintf(fout, "%lld\n", ret);

  return 0;
}

/*

3
5 2
5 4
5 10
 => 2
 */

