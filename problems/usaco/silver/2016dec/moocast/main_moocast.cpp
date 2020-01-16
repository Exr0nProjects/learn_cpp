/*
ID: spoytie2
TASK: moocast
LANG: C++14
*/

/*
 * Problem moocast (usaco/silver/2016dec/moocast)
 * Create time: Wed 15 Jan 2020 @ 21:13 (PST)
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
FILE *fin = fopen("moocast.in", "r");
FILE *_ = stderr;

const int MAXSZ = 210; // todo
// raw input data
int N;
int rawx[MAXSZ]; // x coord
int rawy[MAXSZ]; // y coord
int rawp[MAXSZ]; // power

// graph
inline double dist(cn i, cn j)
{
  return sqrt(pow(rawx[i]-rawx[j], 2) + pow(rawy[i]-rawy[j], 2));
}

struct Edge
{
  int f, t, n;
} edges[MAXSZ*MAXSZ];
int head[MAXSZ], ecnt=1;
void addEdge(cn a, cn b)
{
  edges[ecnt].f = a;
  edges[ecnt].t = b;
  edges[ecnt].n = head[a];
  head[a] = ecnt;
  ++ecnt;
}

// traversial
int mem[MAXSZ];
int dfs(cn s)
{
  if (mem[s] > 0) return mem[s];
  int ret=1; // myself
  for (int e=head[s]; e; e=edges[e].n)
  {
    ret += dfs(edges[e].t);
  }
  mem[s] = ret;
  return ret;
}

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("moocast.out", "w+"); }
  scanf("%d", &N);
  for (int i=0; i<N; ++i)
  {
    scanf("%d%d%d", &rawx[i], &rawy[i], &rawp[i]);

    for (int j=0; j<i; ++j)
    {
      if (dist(i, j) < (double) rawp[i]) // can go from i to j
      {
        addEdge(i, j);
      }
      if (dist(i, j) < (double) rawp[j]) // can go from j to i
      {
        addEdge(j, i);
      }
    }
  }
  
  int ret=0;
  for (int s=0; s<N; ++s)
  {
//    printf("cow %02d can transmit directly to ", s);
//    for (int e=head[s]; e; e=edges[e].n)
//      printf("%02d ", edges[e].t);
//    printf("\n");

    ret = max(ret, dfs(s));
  }
  
  printf("%d\n", ret);

  return 0;
}
