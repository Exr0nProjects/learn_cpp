/*
ID: spoytie2
TASK: 8461
LANG: C++14
*/

/*
 * Problem 8461 (xjoi.net/8461)
 * Created Sun 24 Nov 2019 @ 13:38 (PST)
 * Accepted Sun 24 Nov 2019 @ 13:52 (PST)
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
// auto fin = fopen("8461.in", "r");
// auto fout = fopen("8461.out", "w+");

const int MAXSZ = 100010; // todo
int n, m, tw = 0;
int items[MAXSZ];
int ret = 0;

void recurse(cn rem = 0)
{
  if (rem == n)
  {
    ret += tw == m;
  }
  else
  {
    recurse(rem + 1);
    tw += items[rem];
    if (tw <= m)
      recurse(rem + 1);
    tw -= items[rem];
  }
}
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &items[i]);
  }

  recurse();
  if (ret)
    printf("yes");
  else
    printf("no");

  return 0;
}

/*
5 10
8 4 3 5 1
 */
