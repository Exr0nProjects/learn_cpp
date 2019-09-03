/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 8113 (xjoi.net/8113)
 * Created Mon 02 Sep 2019 @ 16:45 (PDT)
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

const int MAXSZ = 60; // todo

struct Node
{
  int i, j, k, val;
} matrix[MAXSZ][MAXSZ][MAXSZ];

int main ()
{
  int k;
  scanf("%d", &k);

  for (int fli = 0; fli < k; ++fli)
  {
    int a, b, c, t;
    scanf("%d%d%d%d", &a, &b, &c, &t);
    for (int i=0; i<a; ++i)
    {
      for (int j=0; j<b; ++j)
      {
        for (int k=0; k<b; ++k)
        {
          matrix[i][j][k].i = i;
          matrix[i][j][k].j = j;
          matrix[i][j][k].k = k;
          scanf("%d", &(matrix[i][j][k].val));
          if (matrix[i][j][k].val == 1) matrix[i][j][k].val = -1;
        }
      }
    }
    queue<Node&> q;
    q.push(matrix[0][0][0]);
    while (!q.empty())
    {
      if (q.front().val != 0) continue;

      Node& f = q.front();
      if (f.i > 0)
      {
        matrix[f.i-1][f.j][f.k].val = f.val + 1;
        q.push(matrix[f.i-1][f.j][f.k]);
      }
      if (f.j > 0)
      {
        matrix[f.i][f.j-1][f.k].val = f.val + 1;
        q.push(matrix[f.i][f.j-1][f.k]);
      }
      if (f.k > 0)
      {
        matrix[f.i][f.j][f.k-1].val = f.val + 1;
        q.push(matrix[f.i][f.j][f.k-1]);
      }
      if (f.i < a-1)
      {
        matrix[f.i+1][f.j][f.k].val = f.val + 1;
        q.push(matrix[f.i+1][f.j][f.k]);
      }
      if (f.j < b-1)
      {
        matrix[f.i][f.j+1][f.k].val = f.val + 1;
        q.push(matrix[f.i][f.j+1][f.k]);
      }
      if (f.k < c-1)
      {
        matrix[f.i][f.j][f.k+1].val = f.val + 1;
        q.push(matrix[f.i][f.j][f.k+1]);
      }
    }

    if (matrix[a-1][b-1][c-1].val <= t) printf("%d", matrix[a-1][b-1][c-1]);
    else printf("-1");
    printf("\n");
  }
  return 0;
}
