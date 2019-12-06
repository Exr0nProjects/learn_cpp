/*
ID: spoytie2
TASK: cow
LANG: C++14
*/

/*
 * Problem cow (usaco/bronze/feb2015/cow)
 * Created Sun 01 Dec 2019 @ 11:49 (PST)
 * Accepted Sun 01 Dec 2019 @ 15:13 (PST)
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
bool field[10][MAXSZ + 10];    // 3 letters in cow + padding
long long tab[10][MAXSZ + 10]; // dp tabulation

int n;

long long dfs(cn y, cn x, cn stp = 0)
{
  for (int i = 0; i < stp; ++i)
    //d*/  printf("  ");
    //d*/printf("dfs: %d, %d\n", y, x);

    if (y < 0 || x < 0)
      throw "y or x out of bounds!";
    else if (y >= 2)
      return tab[3][x + 1];
    else if (y >= 3)
      return 1; // made the word cow
    else if (x >= n)
      return 0; // ran out of letters
    else if (tab[y][x] >= 0)
      return tab[y][x];

  long long ret = 0;
  for (int j = x + 1; j < n; ++j) // doesn't have to go up to n because that spot would have to be an W to be worth anything anyways, and we deal with W in the base case
  {
    if (field[y + 1][j])
      ret += dfs(y + 1, j, stp + 1);
  }
  tab[y][x] = ret;
  return ret;
}

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
  for (int j = 1; j <= n; ++j)
  {
    for (int i = 1; i <= 4; ++i) // this used to be `i<=n` which would fail for large numbers of n
      tab[i][j] = -1;            // init tabulation array

    char c;
    fscanf(fin, "%c", &c);
    if (c == 'C')
      field[1][j] = true;
    else if (c == 'O')
      field[2][j] = true;
    else if (c == 'W')
      field[3][j] = true;
  }

  tab[3][n] = field[3][n];
  for (int j = n - 1; j > 0; --j)
  {
    if (field[3][j])
      ++tab[3][j]; // ends up as either 0 or -1
    tab[3][j] += tab[3][j + 1] + 1;
  }

  tab[0][0] = -1;
  fprintf(fout, "%lld\n", dfs(0, 0));

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
