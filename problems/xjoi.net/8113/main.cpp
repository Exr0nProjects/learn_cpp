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

int main()
{
  int k;
  scanf("%d\n", &k);

  for (int fli = 0; fli < k; ++fli)
  {
    int a, b, c, t;
    scanf("%d%d%d%d\n", &a, &b, &c, &t);
    for (int i = 0; i < a; ++i)
    {
      for (int j = 0; j < b; ++j)
      {
        for (int k = 0; k < c; ++k)
        {
          matrix[i][j][k].i = i;
          matrix[i][j][k].j = j;
          matrix[i][j][k].k = k;
          scanf("%d", &(matrix[i][j][k].val));
          if (matrix[i][j][k].val == 1)
            matrix[i][j][k].val = -1;
        }
      }
    }

    if (a + b + c == 3)
    {
      printf("0\n");
      continue;
    } // todo: should be printf 1?

    queue<Node> q;
    q.push(matrix[0][0][0]);
    while (!q.empty())
    {
      Node &f = q.front();
      if (f.i > 0 && matrix[f.i - 1][f.j][f.k].val == 0)
      {
        matrix[f.i - 1][f.j][f.k].val = f.val + 1;
        q.push(matrix[f.i - 1][f.j][f.k]);
      }
      if (f.j > 0 && matrix[f.i][f.j - 1][f.k].val == 0)
      {
        matrix[f.i][f.j - 1][f.k].val = f.val + 1;
        q.push(matrix[f.i][f.j - 1][f.k]);
      }
      if (f.k > 0 && matrix[f.i][f.j][f.k - 1].val == 0)
      {
        matrix[f.i][f.j][f.k - 1].val = f.val + 1;
        q.push(matrix[f.i][f.j][f.k - 1]);
      }
      if (f.i < a - 1 && matrix[f.i + 1][f.j][f.k].val == 0)
      {
        matrix[f.i + 1][f.j][f.k].val = f.val + 1;
        q.push(matrix[f.i + 1][f.j][f.k]);
      }
      if (f.j < b - 1 && matrix[f.i][f.j + 1][f.k].val == 0)
      {
        matrix[f.i][f.j + 1][f.k].val = f.val + 1;
        q.push(matrix[f.i][f.j + 1][f.k]);
      }
      if (f.k < c - 1 && matrix[f.i][f.j][f.k + 1].val == 0)
      {
        matrix[f.i][f.j][f.k + 1].val = f.val + 1;
        q.push(matrix[f.i][f.j][f.k + 1]);
      }
      q.pop();

      //      printf("\n");
      //      for (int _i=0; _i<a; ++_i)
      //      {
      //        for (int _j=0; _j<b; ++_j)
      //        {
      //          for (int _k=0; _k<c; ++_k)
      //          {
      //            printf("%3d", matrix[_i][_j][_k].val);
      //          }
      //          printf("\n");
      //        }
      //        printf("\n");
      //      }
      //      printf("\n\n");
    }

    if (matrix[a - 1][b - 1][c - 1].val <= t && matrix[a - 1][b - 1][c - 1].val != 0)
      printf("%d", matrix[a - 1][b - 1][c - 1].val);
    else
      printf("-1");
    printf(" ");
  }
  return 0;
}

/*
2
3 3 4 20
0 1 1 1
0 0 1 1
0 1 1 1
1 1 1 1
1 0 0 1
0 1 1 1
0 0 0 0
0 1 1 0
0 1 1 0
2 2 2 10
0 0
0 0
0 0
0 0
 
*/
