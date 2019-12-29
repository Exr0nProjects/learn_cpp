/*
ID: spoytie2
TASK: square
LANG: C++14
*/

/*
 * Problem square (usaco/bronze/2016dec/square)
 * Created Sun 29 Dec 2019 @ 10:09 (PST)
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
FILE *fin = fopen("square.in", "r");
FILE *_ = stderr;

const int MAXSZ = -1; // todo



int main ()
{
  if (fin) { stdin = fin, stdout = fopen("square.out", "w+"); }
  int x1a, y1a, x2a, y2a, x1b, y1b, x2b, y2b;
  scanf("%d%d%d%d%d%d%d%d", &x1a, &y1a, &x2a, &y2a, &x1b, &y1b, &x2b, &y2b);
  fprintf(_, "%d-%d=%d, %d-%d=%d\n", max(x2a, x2b), min(x1a, x1b), abs(max(x2a, x2b)-min(x1a, x1b)), max(y2a, y2b), min(y1a, y1b), abs(max(y2a, y2b)-min(y1a, y1b)));
  printf("%d", (int) pow(max(abs(max(x2a, x2b)-min(x1a, x1b)), abs(max(y2a, y2b)-min(y1a, y1b))), 2));

  return 0;
}
