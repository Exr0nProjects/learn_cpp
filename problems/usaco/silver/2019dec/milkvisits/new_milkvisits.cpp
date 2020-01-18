/*
ID: spoytie2
TASK: milkvisits
LANG: C++14
*/

/*
 * Problem milkvisits (usaco/silver/2019dec/milkvisits)
 * Created Fri 17 Jan 2020 @ 19:20 (PST)
 * Accepted [!meta:end!]
 *
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
FILE* fin = fopen("milkvisits.in", "r");
FILE* fout = nullptr;


const int MAXSZ = 50010; // todo
struct Edge
{
  int f, t, n;
};
Edge edges[2500000010];
int ect = 1, head[MAXSZ];
void addEdge(cl a, cl b)
{
  edges[ect].f = a;
  edges[ect].t = b;
  edges[ect].n = head[a];
  head[a] = ect;
  ++ect;
}

char type[MAXSZ];
int group[MAXSZ];

void disjointDfs(cn s, cn g)
{
  if (group[s]) return;
  group[s] = g;
  for (int e=head[s]; e; e=edges[e].n)
  {
//    printf("%d->%d ? %d\n", s, edges[e].t, type[edges[e].t] == type[s]);
    if (type[edges[e].t] == type[s])
    {
      disjointDfs(edges[e].t, g);
    }
  }
}

int N, V;

int main ()
{
  setIO();
  fscanf(fin, "%d%d\n", &N, &V);
  for (int i=1; i<=N; ++i)
  {
    fscanf(fin, "%c", &type[i]);
  }
  for (int i=1; i<N; ++i)
  {
    int a, b;
    fscanf(fin, "%d%d", &a, &b);
    addEdge(a, b);
    addEdge(b, a);
  }
  
//  for (int i=1; i<=N; ++i)
//  {
//    printf("%2d ->", i);
//    for (int e=head[i]; e; e=edges[e].n)
//    {
//      printf("%3d", edges[e].t);
//    }
//    printf("\n");
//  }

  // groupings
  for (int i=1; i<=N; ++i)
  {
    disjointDfs(i, i);
  }
  
//  for (int i=1; i<=N; ++i) printf("%2d (%c): %3d\n", i, type[i], group[i]);

  for (int i=0; i<V; ++i)
  {
    int a, b;
    char c;
    fscanf(fin, "%d%d %c", &a, &b, &c);
    if (group[a] == group[b]) fprintf(fout, "%d", type[a] == c);
    else fprintf(fout, "1");
  }

  fprintf(fout, "\n");

  return 0;
}

/*
3 2
HGH
1 2
1 3
1 3 G
1 3 H
=> 01
 
3 2
HGH
1 2
1 3
1 2 G
1 2 H
=> 11

// larger dataset
10 2
HHHHHHHHHH
1 2
2 3
3 4
5 4
6 5
9 8
7 8
6 7
9 10
3 4 H
1 10 G
=> 10

// circle
7 7
GHHHGGG
1 2
1 3
1 4
1 5
1 6
1 7
1 2 H
1 3 H
1 4 H
1 5 H
1 6 H
1 7 H
7 7 G
 => 1110001
 */
