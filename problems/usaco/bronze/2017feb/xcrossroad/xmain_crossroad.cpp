/*
ID: spoytie2
TASK: crossroad
LANG: C++14
*/

/*
 * Problem crossroad (usaco/bronze/2017feb/crossroad)
 * Created Sun 29 Dec 2019 @ 14:08 (PST)
 * Accepted Sun 29 Dec 2019 @ 14:27 (PST)
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
FILE *fin = fopen("crossroad.in", "r");
FILE *_ = stderr;

const int MAXSZ = 12; // todo
int side[MAXSZ], N;


int main ()
{
  if (fin) { stdin = fin; stdout = fopen("crossroad.out", "w+"); }
  scanf("%d", &N);
  int ret = 0;
  for (int i=0; i<N; ++i)
  {
    int id, s; // FIX: used to be named `i`, name collision
    scanf("%d%d", &id, &s);
    if (side[id] != 0 && side[id] != s+1) ++ret;
    side[id] = s+1;
  }

  printf("%d\n", ret);

  return 0;
}
