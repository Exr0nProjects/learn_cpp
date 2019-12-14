/*
ID: spoytie2
TASK: moocrypt
LANG: C++14
*/

/*
 * Problem moocrypt (usaco/bronze/2015open/moocrypt)
 * Created Fri 13 Dec 2019 @ 19:06 (PST)
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
FILE* fin = fopen("moocrypt.in", "r");
FILE* fout = nullptr;

const int MAXSZ = 60; // todo
char board[MAXSZ][MAXSZ];
int n, m;

ll count(cl y, cl x, cl m, cl o)
{
  if (board[y][x] != m) return 0;
  int mods[] = {-1, 0, 1};
  ll ret = 0;
  for (int i:mods) for (int j:mods)
  {
    if (i == j && j == 0) continue;
    //d*/printf("    mod: %d, %d\n", i, j);
    ret += (board[y+i][x+j] == o && board[y+2*i][x+2*j] == o);
  }
  return ret;
  // (
  //   (board[y-1][ x ] == o && board[y-2][ x ] == o) + // N
  //   (board[y-1][x+1] == o && board[y-2][x+2] == o) + // NE
  //   (board[ y ][x+1] == o && board[ y ][x+2] == o) + // E
  //   (board[y+1][x+1] == o && board[y+2][x+2] == o) + // SE
  //   (board[y]) + // S
  //   () + // SW
  //   () + // W
  //   () // NW
  // )
}

int main ()
{
  if (fin) { fout = fopen("moocrypt.out", "w+"); } else { fin = stdin; fout = stdout; }
  fscanf(fin, "%d%d", &n, &m);
  
  if (n < 3 && m < 3)
  {
    fprintf(fout, "0\n");
    return 0;
  }
  
  for (int i=0; i<=n+3; ++i) for (int j=0; j<=m+3; ++j)
  {
    board[i][j] = '.';
  }
  for (int i=2; i<=n+1; ++i)
  {
    fscanf(fin, "\n"); // needed for character input
    for (int j=2; j<=m+1; ++j)
    {
      char c;
      fscanf(fin, "%c", &c);
      board[i][j] = c;
    }
  }
  
  
//  printf("%d\n", count(4, 4, 'M', 'O')); return 0;
  
  
  
  ll ret = 0;

  for (char _m='A'; _m<='Z'; ++_m)
  {
    for (char _o='A'; _o<='Z'; ++_o)
    {
      if (_m == _o) continue;
      ll t = 0;
      for (int i=2; i<=n+1; ++i)
      {
        for (int j=2; j<=m+1; ++j)
        {
          t += count(i, j, _m, _o);
          if (_m=='Q' && _o=='M') printf("number @ (%d, %d): %d\n", i, j, count(i, j, _m, _o));
        }
      }
      if (t) printf("t = %d with m=%c, o=%c\n", t, _m, _o);
      ret = max(ret, t);
    }
  }

  fprintf(fout, "%d\n", ret);

  return 0;
}
