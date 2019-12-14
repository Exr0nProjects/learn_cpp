/*
ID: spoytie2
TASK: whereami
LANG: C++14
*/

/*
 * Problem whereami (usaco/bronze/2019dec/whereami)
 * Created Sat 14 Dec 2019 @ 11:32 (PST)
 * Accepted [!meta:end!]
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
FILE *fin = fopen("whereami.in", "r");
FILE *fout = nullptr;

const int MAXSZ = 110; // todo
char road[MAXSZ];
int n;

ll pi(cl s = 0)
{
  ll pre = s, mmax = 0;
  for (ll i = s; i < n; ++i)
  {
    if (road[i] == road[pre] && i > s)
    {
      ++pre;
      mmax = max(mmax, pre);
    }
    else
    {
      pre = s;
    }
  }
  return mmax - s;
}

int main()
{
  if (fin)
  {
    fout = fopen("whereami.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }

  fscanf(fin, "%d\n", &n);
  ll mmax = 0;
  for (int i = 0; i < n; ++i)
  {
    fscanf(fin, "%c", &road[i]);
  }

  for (int i = 0; i < n; ++i)
  {
    mmax = max(mmax, pi(i));
    printf("i: %d -> %d\n", i, mmax);
  }

  fprintf(fout, "%d\n", mmax + 1);

  /* (this code from a previous practice problem I wrote using python, https://repl.it/@cmd0kittn/xcamp-KMP-sketch)
  def pi(s):
  ret = []
  pre = 0
  for i in range(len(s)):
    if (s[i] == s[pre] and i != 0):
      pre += 1
    else:
      pre = 0
    ret.append(pre)
  return ret
  */

  return 0;
}
