/*
ID: spoytie2
TASK: lostcow
LANG: C++14
*/

/*
 * Problem lostcow (usaco/bronze/2017open/lostcow)
 * Created Mon 30 Dec 2019 @ 15:08 (PST)
 * Accepted [!meta:end!]
 * 
 */

#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <cmath>
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
FILE *fin = fopen("lostcow.in", "r");
FILE *_ = stderr;

const int MAXSZ = -1; // todo
int x, y;


int main ()
{
  if (fin) { stdin = fin; stdout = fopen("lostcow.out", "w+"); }
  scanf("%d%d", &x, &y);

  int ret = 0;
  int pos = x, step = 1;
  for (; pos != y; pos += (step<0 ? -1 : 1))
  {
    ++ret;
    if (pos == x + step)
    {
      step *= -2;
    }
  }

  printf("%d\n", ret);

  return 0;
}
