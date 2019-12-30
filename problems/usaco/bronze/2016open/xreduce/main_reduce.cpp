/*
ID: spoytie2
TASK: reduce
LANG: C++14
*/

/*
 * Problem reduce (usaco/bronze/2016open/reduce)
 * Created Mon 30 Dec 2019 @ 12:56 (PST)
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
FILE *fin = fopen("reduce.in", "r");
FILE *_ = stderr;

const int MAXSZ = -1; // todo
int N;
vector<pair<int, int> > cows;
vector<int> xp, yp;


int main ()
{
  if (fin) { stdin = fin; stdout = fopen("reduce.out", "w+"); }
  scanf("%d", &N);
  for (int i=0; i<N; ++i)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    cows.push_back(make_pair(x, y));
    xp.push_back(x);
    yp.push_back(y);
  }
  sort(xp.begin(), xp.end());
  sort(yp.begin(), yp.end());

  int ret = (xp[xp.size()-1]-xp[0]) * (yp[yp.size()-1]-yp[0]);
  for (ca c : cows)
  {
    int maxx=xp.size()-1, maxy=yp.size()-1, minx=0, miny=0;
    if (c.first == xp[maxx]) -- maxx;
    else if (c.first == xp[minx]) ++minx;
    if (c.second == yp[maxy]) --maxy;
    else if (c.second == yp[miny]) ++miny;
    ret = min(ret, (xp[maxx]-xp[minx])*(yp[maxy]-yp[miny]));
  }

  printf("%d\n", ret);

  return 0;
}
