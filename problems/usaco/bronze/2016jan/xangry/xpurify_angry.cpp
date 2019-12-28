/*
ID: spoytie2
TASK: angry
LANG: C++14
*/

/*
 * Problem angry (usaco/bronze/2016jan/angry)
 * Created Sat 28 Dec 2019 @ 10:15 (PST)
 * Accepted [!meta:end!]
 ! the minor purification modification for this problem is we only have to simulate the furthest exploding haybale for each explosion stage
 ! instead of all of them because we can just subtract indicies to get the number of haybales in between
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
FILE *fin = fopen("angry.in", "r");
FILE *fout = nullptr;

const int MAXSZ = 110; // todo
int bales[MAXSZ];
int N;

ll simulate(cn i, cn s, cn d) // d is either -1 or 1 for direction
{
  for (int j = 0; j < s; ++j)
    printf("  ");
  printf("simulate called (%d, %d)\n", bales[i], s);

  ll next = -1;
  for (int p = i + d; p >= 0 && p < N && abs(bales[i] - bales[p]) <= s; p += d)
  {
    next = p;
  }
  if (next < 0)
    return i;
  return simulate(next, s + 1, d);
}

int main()
{
  if (fin)
  {
    fout = fopen("angry.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }

  fscanf(fin, "%d", &N);
  for (int i = 0; i < N; ++i)
  {
    fscanf(fin, "%d", &bales[i]);
  }

  stable_sort(bales, bales + N);

  ll ret = 0;
  for (int i = 0; i < N; ++i)
  {
    ret = max(ret, simulate(i, 1, 1) - simulate(i, 1, -1) + 1);
  }
  fprintf(fout, "%lld\n", ret);

  return 0;
}

/*
6
3
4
5
6
8
13
 */
