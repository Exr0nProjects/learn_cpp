/*
ID: spoytie2
TASK: billboard
LANG: C++14
*/

/*
 * Problem billboard (usaco/bronze/2017dec/billboard)
 * Created Sun 29 Dec 2019 @ 16:08 (PST)
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
FILE *fin = fopen("billboard.in", "r");
FILE *_ = stderr;

const int MAXSZ = -1; // todo
int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, xx1, xy1, xx2, xy2;


int main ()
{
  if (fin) { stdin = fin; stdout = fopen("billboard.out", "w+"); }
  scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &ax1, &ay1, &ax2, &ay2, &bx1, &by1, &bx2, &by2, &xx1, &xy1, &xx2, &xy2); // das a big scanf
  int ret = 0;
  for (int i=-1010; i<1010; ++i)
  {
    for (int j=-1010; j<1010; ++j)
    {
      if (((i >= ax1 && i < ax2 && i >= ay1 && i < ay2)  // part of billboard 1
        || (i >= bx1 && i < bx2 && i >= by1 && i < by2)) // part of billboard 2
        &&!(i >= xx1 && i < xx2 && i >= xy1 && i < xy2)) // and not blocked by the truck
      {
        ++ret;
      }
    }
  }

  printf("%d\n", ret);

  return 0;
}
