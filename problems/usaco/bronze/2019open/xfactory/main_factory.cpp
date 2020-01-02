/*
ID: spoytie2
TASK: factory
LANG: C++14
*/

/*
 * Problem factory (usaco/bronze/2019open/factory)
 * Created Thu 02 Jan 2020 @ 10:31 (PST)
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
FILE *fin = fopen("factory.in", "r");
FILE *_ = stderr;

const int MAXSZ = 110; // todo
bool vis_src[MAXSZ];
int vis_end[MAXSZ];
int N;

struct Edge
{
  int f, t, n;
} edges[MAXSZ];
int head[MAXSZ], eidx = 1;

void addEdge(cn a, cn b)
{
  edges[eidx].f = a;
  edges[eidx].t = b;
  edges[eidx].n = head[a];
  head[a] = eidx;
  ++eidx;
}

void travel(cn i, cn from_count = 0)
{
  vis_end[i] += from_count;

  for (int e = head[i]; e; e = edges[e].n)
  {
    fprintf(_, "traveling from%3d ->%3d\n", i, edges[e].t);
    travel(edges[e].t, from_count + (!vis_src[i])); // FIX: only increase the carry (from_count) if we haven't sourced from this station before
  }
  vis_src[i] = true;
}

void debug()
{
  for (int i = 0; i <= N; ++i)
    fprintf(_, "%3d", i);
  fprintf(_, "\n");
  for (int i = 0; i <= N; ++i)
    fprintf(_, "%3d", vis_src[i]);
  fprintf(_, "\n");
  for (int i = 0; i <= N; ++i)
    fprintf(_, "%3d", vis_end[i]);
  fprintf(_, "\n");
}

int main()
{
  if (fin)
  {
    stdin = fin;
    stdout = fopen("factory.out", "w+");
  }

  scanf("%d", &N);
  if (N == 1)
  {
    printf("1\n");
    return 0;
  }
  fprintf(_, "N=%d\n", N);
  for (int i = 0; i < N - 1; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    //d*/fprintf(_, "%d: scanned %d, %d\n", i, a, b);
    addEdge(a, b);
  }

  for (int i = 1; i <= N; ++i)
  {
    if (vis_src[i])
      continue;
    travel(i);
  }

  debug();

  for (int i = 1; i <= N; ++i)
  {
    if (vis_end[i] == N - 1) // visited by all
    {
      printf("%d\n", i);
      return 0;
    }
  }

  printf("-1\n"); // none were visited by all

  return 0;
}

/*
1
=> 1
 
2
1 2
=> 2

4
1 2
2 3
3 4
=> 4

4
1 2
2 3
1 4
=> -1

5
1 2
3 2
1 4
3 4
=> -1
 
10
1 2
 2 3
 3 4
 4 5
 5 6
 6 7
 7 8
 8 9
 9 10
 => 10
 
8
 1 3
 3 5
 2 3
 5 7
 7 8
 6 8
 4 5
 => 8
 */
