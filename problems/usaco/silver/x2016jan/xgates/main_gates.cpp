/*
ID: spoytie2
TASK: gates
LANG: C++14
*/

/*
 * Problem gates (usaco/silver/2016jan/gates)
 * Create time: Sat 11 Jan 2020 @ 09:21 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <cmath>
#include <random>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <string>
#include <vector>
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
FILE *fin = fopen("gates.in", "r");
FILE *_ = stderr;

const int MAXSZ = 2020; // todo
int N;
int dest[MAXSZ][MAXSZ][5];
int x = 1010, y = 1010;

int conv(char c)
{
  int ret=5;
  if (c == 'N') ret=1;
  if (c == 'E') ret=2;
  if (c == 'S') ret=3;
  if (c == 'W') ret=4;

  return ret;
}


int main ()
{
  if (fin) { stdin = fin; stdout = fopen("gates.out", "w+"); }
  scanf("%d\n", &N);


  dest[y][x][0] = true;
  int crossings=0;
  for (int i=0; i<N; ++i)
  {
    char c;
    scanf("%c", &c);

    c = conv(c);
    if (c == 5) continue;

    // update dest of where we left from
    dest[y][x][(c+1)%4+1] = true;

    static int my[] = {0, -1, 0, 1, 0};
    static int mx[] = {0, 0, 1, 0, -1};
    y += my[c];
    x += mx[c];

    // update dest of new position
    if (dest[y][x][0] && !dest[y][x][c]) // already been here, and not from this direction aka crossing
    {
//      fprintf(_, "crossing! (total: %d)\n", crossings+1);
      ++crossings;
    }
    dest[y][x][c] = dest[y][x][0] = true; // mark position as visited from direction c and as visited in general

//    fprintf(_, "    now at [%d %d]: visited=%d, from n=%d, e=%d, s=%d, w=%d\n", y, x, dest[y][x][0], dest[y][x][1], dest[y][x][2], dest[y][x][3], dest[y][x][4]);
  }

  fprintf(_, "\n\n=> ");
  printf("%d\n", crossings);

  return 0;
}
