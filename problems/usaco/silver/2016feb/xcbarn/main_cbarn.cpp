/*
ID: spoytie2
TASK: cbarn
LANG: C++14
*/

/*
 * Problem cbarn (usaco/silver/2016feb/cbarn)
 * Create time: Mon 13 Jan 2020 @ 19:47 (PST)
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
FILE *fin = fopen("cbarn.in", "r");
FILE *_ = stderr;

const int MAXSZ = 1010; // todo
int N;
int rooms[MAXSZ];

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("cbarn.out", "w+"); }
  scanf("%d", &N);
  for (int i=0; i<N; ++i)
  {
    scanf("%d", &rooms[i]);
  }
  
  for (int i=0; i<N; ++i) fprintf(_, "%3d", rooms[i]); fprintf(_, "\n");

  int ret=INT32_MAX, tmp=0;
  for (int start=0; start<N; ++start)
  {
    for (int loc=(start-1+N)%N; loc != start; loc = ((loc+N)-1)%N)
    {fprintf(_, "  loc=%3d\n", loc);
      if (rooms[loc] == 0) // needs a cow
      {
        fprintf(_, "    cow needed in room %d\n", loc);
        int trans;
        for (trans=(loc-1+N)%N; rooms[trans] == 0; trans = (trans-1+N)%N) // go forward until we find a room with a cow
        { fprintf(_, "      does room %d have a cow?\n", trans); }
        --rooms[trans];
        ++rooms[loc];
        tmp += (int) pow((trans-loc +N) %N, 2);
      }
    }
    ret = min(ret, tmp);
  }

  printf("%d\n", ret);

  return 0;
}

/*
 3
 1
 1
 1
 => 0
 
 3
 1
 2
 0
 => 1
 */
