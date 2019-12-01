/*
ID: spoytie2
TASK: cow
LANG: C++14
*/

/*
 * Problem cow (usaco/bronze/feb2015/cow)
 * Created Sun 01 Dec 2019 @ 14:59 (PST)
 * Accepted [!meta:end!]
 * .
 ! This method was inspired by Teacher X, I thought it was 2D dp but that was too slow and there is a better way to use 1D dp, which is implemented here.
 * This method works by counting the number of possibilities of "COW" up to a given letter instead of counting the number of that letter and then fiddling with it at the end.
 * This is much faster because it works with just one pass over the data.
 ! Final compelxity O(n)
 * 
 * OG NOTE:
 * using new method: count how many combos up to a letter, 1D dp with three arrays
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
FILE *fin = fopen("cow.in", "r");
FILE *fout = nullptr;

const int MAXSZ = 100000;      // todo
long long tab[10][MAXSZ + 10]; // dp tabulation

int n;

int main()
{
  if (fin)
  {
    fout = fopen("cow.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }

  fscanf(fin, "%d\n", &n);
  for (int j = 0; j <= n + 1; ++j)
    tab[0][j] = 1;
  for (int j = 1; j <= n; ++j)
  {
    char c;
    fscanf(fin, "%c", &c);
    int k;
    if (c == 'C')
      k = 1;
    else if (c == 'O')
      k = 2;
    else if (c == 'W')
      k = 3;

    for (int i = 1; i < 4; ++i)
    {
      tab[i][j] = tab[i][j - 1];
      if (i == k)
        tab[i][j] += tab[i - 1][j]; // combinations
    }
  }

  fprintf(fout, "%lld\n", tab[3][n]);

  return 0;
}

/*
4
CWOW
=> 1

4
COWW
=> 2

6
CCOOWW
=> 8

6
COOWWW
=> 6

5
WOCOW
=> 1

7
WOCOWWO
=> 2
 
8
WCWOCOWO
=> 3
 */
