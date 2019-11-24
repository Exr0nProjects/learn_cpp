/*
ID: spoytie2
TASK: 7988
LANG: C++14
*/

/*
 * Problem 7988 (xjoi.net/7988)
 * Created Sun 24 Nov 2019 @ 13:27 (PST)
 * Accepted Sun 24 Nov 2019 @ 13:37 (PST)
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
// auto fin = fopen("7988.in", "r");
// auto fout = fopen("7988.out", "w+");

const int MAXSZ = 1; // todo
int n, r;

void recurse(cn n, cn r)
{
  if (n < r)
    printf("%d", n);
  else
  {
    recurse(n / r, r);
    printf(" %d", n % r);
  }
}

int main()
{
  scanf("%d%d", &n, &r);
  recurse(n, r);

  return 0;
}
