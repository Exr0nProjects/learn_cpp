/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 1197 (xjoi.net/1197)
 * Created Sun 01 Sep 2019 @ 16:07 (PDT)
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

const int MAXSZ = 1; // todo

int dfs(const int b, const int m, const int t, const int cur = 0)
{
  int mx = cur;
  if (t >= b) mx = max(dfs(b, m, t-b, cur + 3), mx);
  if (t >= m) mx = max(dfs(b, m, t-m, cur + 1), mx);
  return mx;
}

int main ()
{
  int b, m, t;
  scanf("%d%d%d", &b, &m, &t);

  printf("%d", dfs(b, m, t));

  return 0;
}
