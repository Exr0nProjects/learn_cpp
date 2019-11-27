/*
ID: spoytie2
TASK: 3665
LANG: C++14
*/

/*
 * Problem 3665 (xjoi.net/3665)
 * Created Wed 27 Nov 2019 @ 10:53 (PST)
 * Accepted [!meta:end!]
 * 0/1 knapsack
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
// auto fin = fopen("3665.in", "r");
// auto fout = fopen("3665.out", "w+");

const int MAXSZ = 50; // todo
int m, n;
struct Item
{
  int w, v;
} items[MAXSZ];
int tab[50][210];

int rec(cn si, cn w)
{
  if (tab[si][w] >= 0) return tab[si][w];
  if (w < 0 || si >= n) return 0;

  int ret = rec(si+1, w);
  if (w >= items[si].w) ret = max(ret, rec(si+1, w-items[si].w)+items[si].v);
  
  tab[si][w] = ret;
  return ret;
}

int main ()
{
  scanf("%d%d", &m, &n);
  for (int i=0; i<50; ++i)
  {
    for (int j=0; j<200; ++j)
    {
      tab[i][j] = -1;
    }
  }
  
  for (int i=0; i<n; ++i)
  {
    scanf("%d%d", &items[i].w, &items[i].v);
  }

  printf("%d\n", rec(0, m));

  return 0;
}
