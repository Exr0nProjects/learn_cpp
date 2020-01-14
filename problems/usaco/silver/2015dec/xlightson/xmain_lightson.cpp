/*
ID: spoytie2
TASK: lightson
LANG: C++14
*/

/*
 * Problem lightson (usaco/silver/2015dec/lightson)
 * Create time: Mon 13 Jan 2020 @ 07:58 (PST)
 * Accept time: Mon 13 Jan 2020 @ 19:20 (PST)
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
FILE *fin = fopen("lightson.in", "r");
FILE *_ = stderr;

const int MAXSZ = 110; // todo
int N, M;
vector<pair<int, int> > switches[MAXSZ][MAXSZ];
bool on[MAXSZ][MAXSZ];
int vis[MAXSZ][MAXSZ];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void debug()
{
  return;
  fprintf(_, "         ");
  for (int i=0; i<=N+1; ++i) fprintf(_, "%3d", i);
  
  fprintf(_, "\n    on:\n");
  for (int i=0; i<=N+1; ++i)
  {
    fprintf(_, "    %3d: ", i);
    for (int j=0; j<=N+1; ++j)
    {
      fprintf(_, "%3c", on[i][j] ? 'X' : '.');
    }
    fprintf(_, "\n");
  }
  
  fprintf(_, "________________\n\n");
}

void search(cn i, cn j)
{
//  fprintf(_, "called search %d, %d\n", i, j);
  debug();
  if (vis[i][j]) return;
  vis[i][j] = true;
  // turn on all lights from this room and search those if possible
  for (ca nxt : switches[i][j])
  {
    on[nxt.first][nxt.second] = true;
    // check if it has a visited neighbor, if so visit it
    for (int id=0; id<4; ++id)
    {
//      fprintf(_, "  id %d: %2d + %2d = %2d     %2d + %2d = %2d\n", id, nxt.first, dy[id], nxt.first+dy[id], nxt.second, dx[id], nxt.second+dx[id]);
      if (vis[nxt.first+dy[id]][nxt.second+dx[id]]>0 && !vis[nxt.first][nxt.second])
      {
        search(nxt.first, nxt.second);
      }
    }
  }
  // visit unvisited neighbors (aka follow the chain from this location)
  for (int idx=0; idx<4; ++idx)
    if (on[i+dy[idx]][j+dx[idx]])
      search(i+dy[idx], j+dx[idx]);
}

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("lightson.out", "w+"); }
  scanf("%d%d", &N, &M);
  for (int i=0; i<=N+1; ++i)
  { // set search boundaries
    vis[i][0] = vis[i][N+1] = vis[0][i] = vis[N+1][i] = -1;
  }
  for (int i=0; i<M; ++i)
  {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    switches[a][b].push_back(make_pair(c, d));
  }

//  queue<pair<int, int> > q;
//  q.push(make_pair(1, 1));
  on[1][1] = true;
  search(1, 1);

  // Count the number of lights
  int ret=0;
  for (int i=1; i<=N; ++i)
    for (int j=1; j<=N; ++j)
      if (on[i][j]) ++ret;
  printf("%d\n", ret);

  return 0;
}

/*
 
// unvisitable lights
 3 2
 1 1 2 3
 2 3 3 3
 => 2
 
 */
