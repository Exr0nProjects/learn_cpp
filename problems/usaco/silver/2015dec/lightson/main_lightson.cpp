/*
ID: spoytie2
TASK: lightson
LANG: C++14
*/

/*
 * Problem lightson (usaco/silver/2015dec/lightson)
 * Create time: Mon 13 Jan 2020 @ 07:58 (PST)
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
FILE *fin = fopen("lightson.in", "r");
FILE *_ = stderr;

const int MAXSZ = 110; // todo
int N, M;
vector<pair<int, int> > switches[MAXSZ][MAXSZ];
bool on[MAXSZ][MAXSZ];
bool vis[MAXSZ][MAXSZ];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void search(cn i, cn j)
{
  if (vis[i][j]) return;
  vis[i][j] = true;
  for (ca nxt : switches[i][j])
  {
    on[nxt.first][nxt.second] = true;
    // check if it has a visited neighbor
    for (int id=0; id<4; ++id)
      if (vis[nxt.first+dy[id]][nxt.second+dx[id]])
        search(nxt.first, nxt.second);
  }
  // visit unvisited neighbors
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
    vis[i][0] = vis[i][N+1] = vis[0][i] = vis[N+1][i] = true;
  }
  for (int i=0; i<M; ++i)
  {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    switches[a][b].push_back(make_pair(c, d));
  }

  queue<pair<int, int> > q;
  q.push(make_pair(1, 1));
  search(1, 1);

  // Count the number of lights
  int ret=0;
  for (int i=1; i<=N; ++i)
    for (int j=1; j<=N; ++j)
      if (on[i][j]) ++ret;
  printf("%d\n", ret);

  return 0;
}
