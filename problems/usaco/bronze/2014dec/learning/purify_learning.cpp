/*
ID: spoytie2
TASK: learning
LANG: C++14
*/

/*
 * Problem learning (usaco/bronze/learning)
 * Created Mon 02 Dec 2019 @ 16:34 (PST)
 * Accepted [!meta:end!]
 * problem # 490
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
auto fin = fopen("learning.in", "r");
FILE *fout = nullptr;

const int MAXSZ = 50010; // todo
struct Cow
{
  bool s;
  int w;
  Cow() {}
  Cow(bool _s, int _w) : s{_s}, w{_w} {}
  bool operator<(const Cow &o) const { return w < o.w; }
};
vector<Cow> herd(1);
int n, a, b;

void debug()
{
  bool d = true;
  /*/d*/ d = false;
  if (d)
    return;
  for (int i = 0; i < n; ++i)
  {
    printf("%d: %d, ", herd[i].w, herd[i].s);
  }
  printf("\n");
}

int main()
{
  if (fin)
    fout = fopen("learning.out", "w+");
  else
  {
    fin = stdin;
    fout = stdout;
  }

  //fscanf(fin, "%d%d%d", &n, &a, &b);
  fscanf(fin, "%d%d%d", &n, &a, &b);
  ++b; // our intervals don't count the upper bound, so we increment so when it counts to one below the upper bound, it is actually the original upper bound
  for (int i = 0; i < n; ++i)
  {
    char s[5];
    int w;
    //fscanf(fin, "%s%d", &s, &herd[i].w);
    fscanf(fin, "%s%d", &s, &w);
    herd.push_back({s[0] == 'S', w});
  }
  stable_sort(herd.begin(), herd.end());

  debug();
  printf("a: %d, b: %d\n", a, b);

  // add two cows far far away that shouldn't affect anything
  herd[0] = {herd[1].s, -1 * INF};
  herd.push_back({herd[n].s, INF});

  int ret = 0;
  for (int i = 0; i <= n; ++i)
  {
    printf("  cycle %d: ret = %d\n", i, ret);
    int l = herd[i].w;
    int r = herd[i + 1].w;
    int m = (l + r) / 2; // inspired by usaco solution
    printf("    %d->%d->%d\n", l, m, r);

    if (herd[i].s) // bottom half
    {
      int s = max(l, a);
      int e = min(m, b);
      ret += max(e - s + 1, 0);
    }
    printf("    %d ", ret);
    if (herd[i + 1].s) // top half
    {
      int s = max(m + 1, a); // not m, because we want the interval to start at the next one
      int e = min(r, b);
      ret += max(e - s, 0);
    }
    printf("%d ", ret);
    // above will undercount center if upper but not lower
    if ((!herd[i].s) && herd[i + 1].s && herd[i].w % 2 == herd[i + 1].w % 2 && a <= m && m <= b)
    {
      ++ret;
    }
    printf("%d\n", ret);
  }

  //fprintf(fout, "%d\n", ret);
  fprintf(fout, "%d\n", ret);

  return 0;
}

/*
3 1 10
S 10
NS 4
S 1
 => 6
 
3 4 10
S 10
NS 4
S 1
 => 4

3 4 14
S 10
NS 4
S 1
 => 8

3 1 10
S 10
NS 4
S 3
 => 7

2 1 200
S 23
NS 24
 => 23

5 1 20
S 5
S 25
NS 26
S 10
NS 11
 => 13
 */
