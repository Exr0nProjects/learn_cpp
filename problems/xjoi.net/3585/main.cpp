/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 3585 (xjoi.net/3585)
 * Created Fri 06 Sep 2019 @ 06:36 (PDT)
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
  int i, j, val, add;
  bool operator< (const Block& o)
  { return this->val < o.val; }
} mat[MAXSZ][MAXSZ];
int a, b;

void bfs (const int ci, const int cj)
{
  mat[ci][cj].val = 1;
  priority_queue<Block> pq;
  for (pq.push(mat[ci][cj]); !pq.empty(); pq.pop())
  {
    c = pq.front();
    if (c.i > 0   && mat[c.i-1][c.j].val == 0) { mat[c.i-1][c.j].val = c.val+1+mat[c.i-1][c.j].add; pq.push(mat[c.i-1][c.j]); }
    if (c.j > 0   && mat[c.i][c.j-1].val == 0) { mat[c.i][c.j-1].val = c.val+1+mat[c.i][c.j-1].add; pq.push(mat[c.i][c.j-1]); }
    if (c.i < a-1 && mat[c.i+1][c.j].val == 0) { mat[c.i+1][c.j].val = c.val+1+mat[c.i+1][c.j].add; pq.push(mat[c.i+1][c.j]); }
    if (c.j > b-1 && mat[c.i][c.j+1].val == 0) { mat[c.i][c.j+1].val = c.val+1+mat[c.i][c.j+1].add; pq.push(mat[c.i][c.j+1]); }
  }
}

int main ()
{
  int si, sj, ei, ej;
  scanf("%d%d", &a, &b);
  for (int i=0; i<a; ++i)
  {
    scanf("\n");
    for (int j=0; j<b; ++j)
    {
      mat[i][j].i = i;
      mat[i][j].j = j;
      char t;
      scanf("%d", &t);
      if (t == '#') mat[i][j].val = -1;
      if (t == 'G') mat[i][j].add = 1;
      if (t == '@') { si = i; sj = j; }
      if (t == 'M') { ei = i; ej = j; }
    }
  }

  bfs(si, sj);

  if (mat[ei][ej].val == 0) printf("You can't save Mengxin");
  else printf("%d", mat[ei][ej].val);
  
  return 0;
}
