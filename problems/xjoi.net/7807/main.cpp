/*
ID: spoytie2
TASK: 7807
LANG: C++14
*/

/*
 * Problem [!meta:pid!] (xjoi.net/7807)
 * Created Sun 03 Nov 2019 @ 10:43 (PST)
 * Accepted [!meta:end!]
 *
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
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
// auto fin = fopen("[!meta:pid!].in", "r");
// auto fout = fopen("[!meta:pid!].out", "w+");

const int MAXSZ = 1; // todo
int n, ret;

void dfs(cn r = 0, bool has = false)
{
  if (r == n)
  {
    if (has)
      ++ret;
    return;
  }
  for (int i = 0; i < 10; ++i)
  {
    if (i == 6 || i == 8)
      dfs(r + 1, true);
    else
      dfs(r + 1, has);
  }
}

int main()
{
  scanf("%d", &n);

  dfs();
  printf("%d", ret);

  return 0;
}
