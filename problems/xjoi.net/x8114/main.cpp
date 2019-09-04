/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem 8114 (xjoi.net/8114)
 * Created Tue 03 Sep 2019 @ 18:34 (PDT)
 * Accepted Tue 03 Sep 2019 @ 18:58 (PDT)
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
int skip[MAXSZ];
int steps[MAXSZ];
int n;

void dfs(const int cur)
{

  //  printf("  %d: ", cur); for (int i=0; i<n; ++i) printf("%3d", steps[i]); printf("\n");

  if (cur + skip[cur] < n && steps[cur + skip[cur]] == 0)
  {
    steps[cur + skip[cur]] = steps[cur] + 1;
    dfs(cur + skip[cur]);
  }
  if (cur - skip[cur] >= 0 && steps[cur + skip[cur]] == 0)
  {
    steps[cur - skip[cur]] = steps[cur] + 1;
    dfs(cur - skip[cur]);
  }
}

int main()
{
  int a, b;
  scanf("%d %d %d\n", &n, &a, &b);
  // printf("\n%d: %d->%d", n, a, b);

  for (int i = 0; i < n; ++i)
  {
    int t;
    scanf("%d", &t);
    skip[i] = t;
  }

  //  printf("\n%d: %d->%d\n", n, a, b); for (int i=0; i<n; ++i) printf("%3d", skip[i]); printf("\nbfs:\n");

  steps[a - 1] = 1;
  dfs(a - 1);

  printf("%d", steps[b - 1] - 1);

  return 0;
}

/*

5 1 5
3 3 1 2 5
0

*/
