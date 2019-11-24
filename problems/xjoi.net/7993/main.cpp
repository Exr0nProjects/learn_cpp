/*
ID: spoytie2
TASK: 7993
LANG: C++14
*/

/*
 * Problem 7993 (xjoi.net/7993)
 * Created Sun 24 Nov 2019 @ 13:00 (PST)
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
#define ca const auto &
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
// auto fin = fopen("7993.in", "r");
// auto fout = fopen("7993.out", "w+");

const int MAXSZ = 10010; // todo
int n, ret = 0;
bool vis[MAXSZ];
vector<int> nums;

void recurse(cn rem)
{
  if (rem == 0)
  {
    int add = 1;
    if (add)
      ret = (ret + 1) % 998244353;
    return;
  }
  for (int i = 1; i <= n; ++i)
  {
    if (n - rem == i - 1)
      continue;
    if (vis[i] == 0)
    {
      vis[i] = 1;
      nums.push_back(i);
      recurse(rem - 1);
      nums.pop_back();
      vis[i] = 0;
    }
  }
}

int main()
{
  scanf("%d", &n);
  recurse(n);

  printf("%d\n", ret);

  return 0;
}
