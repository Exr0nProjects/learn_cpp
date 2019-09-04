/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem 3586 (xjoi.net/3586)
 * Created Tue 03 Sep 2019 @ 19:01 (PDT)
 * Accepted [!meta:end!]
 *
 */

#include <bits/stdc++.h>

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

#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 210; // todo
struct Block
{
  int i, j, v[4] = { };
  bool is_kentucky_fried_chicken_resturaunt = false;
} matrix[MAXSZ][MAXSZ];

int n, m;

void bfs(Block cur, const int t)
{
  matrix[cur.i][cur.j].v[t] = 1;
  queue<Block> q;
  for (q.push(matrix[cur.i][cur.j]); !q.empty(); q.pop())
  {
    cur = q.front();
    //printf("(%d, %d)\n", cur.i, cur.j); for (int i=0; i<n; ++i) { printf("  "); for (int j=0; j<m; ++j) printf("%3d", matrix[i][j].v[t]); printf("\n"); } printf("\n");
    if (cur.i-1 >= 0 && matrix[cur.i-1][cur.j].v[t] == 0) { matrix[cur.i-1][cur.j].v[t] = cur.v[t]+1; q.push(matrix[cur.i-1][cur.j]); }
    if (cur.j-1 >= 0 && matrix[cur.i][cur.j-1].v[t] == 0) { matrix[cur.i][cur.j-1].v[t] = cur.v[t]+1; q.push(matrix[cur.i][cur.j-1]); }
    if (cur.i+1 <  n && matrix[cur.i+1][cur.j].v[t] == 0) { matrix[cur.i+1][cur.j].v[t] = cur.v[t]+1; q.push(matrix[cur.i+1][cur.j]); }
    if (cur.j+1 <  m && matrix[cur.i][cur.j+1].v[t] == 0) { matrix[cur.i][cur.j+1].v[t] = cur.v[t]+1; q.push(matrix[cur.i][cur.j+1]); }
  }
}

int main ()
{
  int sai, saj, sbi, sbj;
  scanf("%d%d", &n, &m);
  for (int i=0; i<n; ++i)
  {
    scanf("\n");
    for (int j=0; j<m; ++j)
    {
      matrix[i][j].i = i;
      matrix[i][j].j = j;
      
      char t;
      scanf("%c", &t);
      if (t == '#') matrix[i][j].v[1] = matrix[i][j].v[2] = -1;
      if (t == 'F') matrix[i][j].is_kentucky_fried_chicken_resturaunt = true;
      if (t == '@') { sai = i; saj = j; }
      if (t == '&') { sbi = i; sbj = j; }
    }
  }
  
  bfs(matrix[sai][saj], 1);
  bfs(matrix[sbi][sbj], 2);
  
  int mmin = 1000000000;
  for (int i=0; i<n; ++i) for (int j=0; j<m; ++j)
  {
    if (matrix[i][j].is_kentucky_fried_chicken_resturaunt
        && matrix[i][j].v[1] > 0 && matrix[i][j].v[2] > 0)
      mmin = min(mmin, matrix[i][j].v[1] + matrix[i][j].v[2]);
  }
  
  if (mmin == 1000000000) printf("-1");
  else printf("%d", mmin-2);
  
  return 0;
}

/*

4 4
@.#F
....
.#..
F..&

 
3 3
@.&
###
FFF

2 8
@......F
&..#....
 
1 5
@K#.&

*/
