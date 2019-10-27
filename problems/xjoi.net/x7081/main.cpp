/*
ID: spoytie2
TASK: XXXX
LANG: C++14
*/

/*
 * Problem 7081 (xjoi.net/7081)
 * Created Sun 27 Oct 2019 @ 13:24 (PDT)
 * Accepted Sun 27 Oct 2019 @ 14:20 (PDT)
 * permutations
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

int n;

void dfs(vector<int> v)
{
  //  printf("%d\n", r); for (int i:v) printf("%3d", i); printf("\n\n");
  if (v.size() == n)
  {
    for (int i : v)
    {
      printf("%d ", i);
    }
    printf("\n");
    return;
  }

  for (int i = 1; i <= n; ++i)
  {
    bool f = false;
    for (int j = 0; j < v.size(); j++)
    {
      if (i == v[j])
      {
        f = true;
        break;
      };
    }
    if (f)
      continue;

    v.push_back(i);
    dfs(v);
    v.pop_back();
  }
}

int main()
{
  scanf("%d", &n);

  dfs(vector<int>{});

  return 0;
}
