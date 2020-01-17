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
bool vis[MAXSZ];
int recurse_depth=0;
int dfs(cn s, cn p=0)
{
//  fprintf(_, "dfs(%d) recurse depth: %d\n", s, ++recurse_depth);
//   if (vis[s]) return mem[s];
  if (vis[s]) return 0;
  vis[s] = true; // FIX: mem was getting set after the recurse calls so relying on mem for vis was faulty
  
  int ret=1; // myself
  for (int e=head[s]; e; e=edges[e].n)
  {
    if (edges[e].t == p) continue; // don't visit the previous node
    ret += dfs(edges[e].t, s);
  }
  
  mem[s] = ret;
  --recurse_depth;
  return ret;
}

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("moocast.out", "w+"); }
  scanf("%d", &N);
  for (int i=1; i<=N; ++i) // FIX: make everything one indexed (cuz we use edgelist)
  {
    scanf("%d%d%d", &rawx[i], &rawy[i], &rawp[i]);

    for (int j=1; j<i; ++j)
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
  for (int s=1; s<=N; ++s)
  {
//    printf("cow %02d can transmit directly to ", s);
//    for (int e=head[s]; e; e=edges[e].n)
//      printf("%02d ", edges[e].t);
//    printf("\n");
//    for (int j=1; j<=N; ++j) vis[j] = false;
    
    ret = max(ret, dfs(s));
  }
  
  printf("%d\n", ret);

  return 0;
}

/*
1
1 1 1
=> 1

0
=> 0

20
1 1 2
2 2 2
3 3 2
4 4 2
5 5 2
6 6 2
7 7 2
8 8 2
9 9 2
10 10 2
11 11 2
12 12 2
13 13 2
14 14 2
15 15 2
16 16 2
17 17 2
18 18 2
19 19 1
20 20 1
=> 19

6
1 11 1
1 12 1
1 13 1
1 14 1
1 17 7
1 8 8
=> 5
*/
