/*
ID: spoytie2
TASK: cownomics
LANG: C++14
*/

/*
 * Problem cownomics (usaco/bronze/2017open/cownomics)
 * Created Mon 30 Dec 2019 @ 15:13 (PST)
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
FILE *fin = fopen("cownomics.in", "r");
FILE *_ = stderr;

const int MAXSZ = 110; // todo
int N, M;
char spots[MAXSZ][MAXSZ];
char plain[MAXSZ][MAXSZ];

int mapTo(char c)
{
  if (c == 'G') return 0;
  if (c == 'C') return 1;
  if (c == 'A') return 2;
  if (c == 'T') return 3;
  return -1;
}

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("cownomics.out", "w+"); }
  
  scanf("%d%d", &N, &M);
  for (int i=0; i<N; ++i)
    scanf("%s", spots[i]);
  for (int i=0; i<N; ++i)
    scanf("%s", plain[i]);
  
  for (int i=0; i<N; ++i)
  {
    for (int j=0; j<M; ++j)
      fprintf(_, "%c", spots[i][j]);
    fprintf(_, "\n");
  }

  int ret = 0;
  for (int i=0; i<M; ++i)
  {
    bool gene[4] = {};
    for (int j=0; j<N; ++j)
    {
      gene[mapTo(spots[j][i])] = true; // this gene affected this cow
    }
    bool legit = true;
    for (int j=0; j<N; ++j)
    {
      if (gene[mapTo(plain[j][i])]) legit = false; // overlap!
    }
    if (legit) ++ret;
  }

  printf("%d\n", ret);

  return 0;
}
