/*
ID: spoytie2
TASK: 2
LANG: C++14
*/

/*
 * Problem 2 (contests/dev.xjoi/dev.xjoi-1351/2)
 * Created Sat 28 Dec 2019 @ 17:59 (PST)
 * Accepted Sun 29 Dec 2019 @ 09:32 (PST)
 * knapsack
 */

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
#define ll long long
#define cl const long long
#define UN unsigned
#define ST static
#define CN const
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 40; // todo
int weight[MAXSZ];
int value[MAXSZ];
int tabu[MAXSZ][210];
int m, n;

int knapsack(cn i, cn w)
{
  if (tabu[i][w] > 0)
    ; // return tabu[i][w];
  if (i >= n || w < 0)
    return 0;
  int ret = knapsack(i + 1, w);
  if (w - weight[i] >= 0)
    ret = max(ret, knapsack(i + 1, w - weight[i]) + value[i]);
  for (int j = 0; j < i; ++j)
   // printf("  "); // FIX: forgot to remove the debug output. 
  //printf("knapsack %d, %d -> %d\n", i, w, ret);
  tabu[i][w] = ret;
  return ret;
}

int main()
{

  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d%d", &weight[i], &value[i]);
  }

  printf("%d", knapsack(0, m));

  return 0;
}
