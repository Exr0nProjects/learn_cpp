/*
ID: spoytie2
TASK: art
LANG: C++14
*/

/*
 * Problem art (usaco/bronze/2017open/art)
 * Created Mon 30 Dec 2019 @ 15:34 (PST)
 * Accepted [!meta:end!]
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
FILE *fin = fopen("art.in", "r");
FILE *_ = stderr;

const int MAXSZ = 12; // todo
int N;
bool possible[MAXSZ];
bool msearch[MAXSZ][6][MAXSZ];
int painting[MAXSZ][MAXSZ];

int at(cn y, cn x)
{
  if (y >= 0 && y < N && x >= 0 && x < N) return painting[y][x];
  return 0;
}

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("art.out", "w+"); }
  scanf("%d", &N);

  for (int i=0; i<N; ++i)
  {
    scanf("\n");
    for (int j=0; j<N; ++j)
    {
      scanf("%c", &painting[i][j]);
      painting[i][j] -= '0';
    }
  }

  // search for colors on multiple sides
  for (int si=0; si<N; ++si) for (int sj=0; sj<N; ++sj) // for every starting point
  {
    for (int k=1; k<=N; ++k) // scan
    {
      //fprintf(_, "(%d, %d), %d\n", si, sj, k);
      msearch[painting[si][sj]][0][at(si+k, sj)] = true; // down
      msearch[painting[si][sj]][1][at(si-k, sj)] = true; // up
      msearch[painting[si][sj]][2][at(si, sj+k)] = true; // right
      msearch[painting[si][sj]][3][at(si, sj-k)] = true; // left
    }
  }
  
  for (int d=0; d<4; ++d)
  {
    for (int c=1; c<=9; ++c)
    {
      fprintf(_, "%2c", msearch[2][d][c]?'X':'.');
    }
    fprintf(_, "\n");
  }

  int ret = 0;
  for (int c=1; c<=9; ++c) // each start color
  {
    bool seen[MAXSZ] = {};
    bool legit = true;
    for (int d=0; d<4; ++d) // each direction from that block
    {
      for (int s=1; s<=9; ++s)
      {
        if (s == c) continue; // no need to check for its own color
        if (msearch[c][d][s] && seen[s]) // saw the same color on different sides
          legit = false;
        seen[s] = msearch[c][d][s]; // update seen so the next iter can use it
      }
    }
    if (legit) ++ret; // this color could have been drawn first
  }

  printf("%d", ret);

  return 0;
}
