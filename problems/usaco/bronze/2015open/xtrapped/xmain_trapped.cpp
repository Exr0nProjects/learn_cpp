/*
ID: spoytie2
TASK: trapped
LANG: C++14
*/

/*
 * Problem trapped (usaco/bronze/2015open/trapped)
 * Created Sun 15 Dec 2019 @ 08:59 (PST)
 * Accepted Tue 31 Dec 2019 @ 12:26 (PST)
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
FILE *fin = fopen("trapped.in", "r");
FILE *fout = nullptr;

const int MAXSZ = 4050; // todo
struct Bale
{
  int pos, siz;
  bool operator<(const Bale &o) const { return pos < o.pos; }
} bales[MAXSZ];
ll n;
short tab[MAXSZ][MAXSZ];


bool escape(ll l, ll r)
{
  if (tab[l][r] >= 0) return tab[l][r];
  if (l <= 0 || r > n)
  {
    printf("escaped! l: %d, r: %d, n: %d\n", l, r, n);
    return true;
  }
  cl dist = bales[r].pos - bales[l].pos;
  if (dist > bales[r].siz || dist > bales[l].siz)
  {
    printf("breakthru! dist=%d, %d-%d\n", dist, l, r);
    if (dist > bales[r].siz)
      ++r;
    if (dist > bales[l].siz)
      --l;
    printf("-> %d-%d\n", l, r);
    bool ret = escape(l, r);
    tab[l][r] = ret;
    return ret;
  }
  tab[l][r] = false;
  return false;
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

  for (int i=0; i<=n+1; ++i)
  {
    for (int j=0; j<=n+1; ++j)
    {
      tab[i][j] = -1;
    }
  }

  for (int i = 1; i <= n; ++i)
  {
    int s, p;
    fscanf(fin, "%d%d", &s, &p);
    bales[i].siz = s;
    bales[i].pos = p;
  }
  stable_sort(bales + 1, bales + n + 1);

  ll ret = 0;
  for (ll i = 1; i < n; ++i)
  {
    printf("\nbale %d: %d @ %d\n", i, bales[i].siz, bales[i].pos);

    printf("%d-%d:\n", i, i + 1);
    if (!escape(i, i + 1))
    {
      ret += bales[i + 1].pos - bales[i].pos;
    }
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
