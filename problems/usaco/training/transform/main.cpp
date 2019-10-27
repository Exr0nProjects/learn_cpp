/*
ID: spoytie2
TASK: transform
LANG: C++14
*/

/*
 * Problem transform (usaco/training/transform)
 * Created Sun 27 Oct 2019 @ 14:22 (PDT)
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

#define cn const int
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 11; // todo
int n;
char abeg[MAXSZ][MAXSZ], aend[MAXSZ][MAXSZ], targ[MAXSZ][MAXSZ];

void r90()
{
  for (int i = 0; i <= n; ++i)
  {
    for (int j = 0; j <= n; ++j)
    {
      aend[j][n - i] = abeg[i][j];
    }
  }
}

void r180()
{
  for (int i = 0; i <= n; ++i)
  {
    for (int j = 0; j <= n; ++j)
    {
      aend[n - i][n - j] = abeg[i][j];
    }
  }
}

void r270()
{
  for (int i = 0; i <= n; ++i)
  {
    for (int j = 0; j <= n; ++j)
    {
      aend[n - j][i] = abeg[i][j];
    }
  }
}

void reflect()
{
  for (int i = 0; i <= n; ++i)
  {
    for (int j = 0; j <= n; ++j)
    {
      aend[i][n - j] = abeg[i][j];
    }
  }
}

void combo()
{
  for (int i = 0; i <= n; ++i)
  {
    for (int j = 0; j <= n; ++j)
    {
      aend[n - i][j] = abeg[i][j];
    }
  }
}

bool check()
{
  for (int i = 0; i <= n; ++i)
  {
    for (int j = 0; j <= n; ++j)
    {
      if (aend[i][j] != targ[i][j])
        return false;
    }
  }
  return true;
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    scanf("\n");
    for (int j = 0; j < n; ++j)
    {
      scanf("%c", &abeg[i][j]);
      aend[i][j] = abeg[i][j];
    }
  }
  for (int i = 0; i < n; ++i)
  {
    scanf("\n");
    for (int j = 0; j < n; ++j)
    {
      scanf("%c", &targ[i][j]);
    }
  }
  --n;

  if (check())
  {
    printf("6\n");
    return 0;
  }

  r90();
  if (check())
  {
    printf("1\n");
    return 0;
  }
  r180();
  if (check())
  {
    printf("2\n");
    return 0;
  }
  r270();
  if (check())
  {
    printf("3\n");
    return 0;
  }
  reflect();
  if (check())
  {
    printf("4\n");
    return 0;
  }
  combo();
  if (check())
  {
    printf("5\n");
    return 0;
  }

  printf("7\n");
  return 0;
}
