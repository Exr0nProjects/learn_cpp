/*
ID: spoytie2
TASK: marathon
LANG: C++14
*/

/*
 * Problem marathon (usaco/bronze/marathon)
 * Created Wed 27 Nov 2019 @ 11:11 (PST)
 * Accepted [!meta:end!]
 * problem # 487
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
auto fin = fopen("marathon.in", "r");
auto fout = fopen("marathon.out", "w+");

const int MAXSZ = 100010; // todo
int n;
struct Point
{
  int x, y;
} points[MAXSZ];

inline int mhdist (const Point& a, const Point& b)
{
  return abs(a.x-b.x) + abs(a.y-b.y);
}
int main ()
{
  //auto cmp = [](const pair<int,int>& l, const pair<int,int>& r) { return l.second < r.second; }; // should create a max heap...
  //priority_queue<pair<int,int>, deque<pair<int,int>, function<bool(pair<int,int>,pair<int,int>)> > pq(cmp);

  int bestskip = 0, total = 0;

  fscanf(fin, "%d", &n);
  for (int i=0; i<n; ++i)
  {
    fscanf(fin, "%d%d", &points[i].x, &points[i].y);
    if (i > 0) total += mhdist(points[i], points[i-1]);
    if (i > 1)
    {
      bestskip = max(bestskip, mhdist(points[i], points[i-1])+mhdist(points[i-1], points[i-2])-mhdist(points[i], points[i-2]));
    }
  }

  fprintf(fout, "%d\n", total-bestskip);

  return 0;
}
