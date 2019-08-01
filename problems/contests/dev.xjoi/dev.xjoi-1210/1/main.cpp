/*
 * dev.xjoi.net/contest/12010 problem 1
 * 29 July 2019
 * distance from points and line
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

#define ll long long
#define dl double
#define ld long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 1; // todo
ld dists[MAXSZ];

struct Point
{
  ld x, y;
} tempPoint;

class LineStd
{
public:
  ld a, b, c;
  ld gety (ld x) const {return -1* this->a/this->b *x -(this->c/this->b)}
  ld getx (ld y) const {return -1* this->b/this->a *y -(this->c/this->a)}
  ld dist (const Point& p)
  {
    ld a = this->gety(p.x) - p.y;
    ld b = this->getx(p.y) - p.x;
    return a*(b/sqrt(a*a + b*b));
  }
} fitline;

int main ()
{
  ld mnd;
  int num;
  scanf("%Lf%Lf%Lf%d", &fitline.a, &fitline.b, &mnd, &num);
  for (int i=0; i<num; ++i)
  {
    scanf("%Lf%Lf", &tempPoint.x, &tempPoint.y);
    dists[i] = fitline.dist(tempPoint);
  }
  sort(dists, dists+num);
  
  int ret = 0;
  for (int i=0; i<num; ++i)
  {
    ret = max(ret, upper_bound(dists[num] + mnd) - i);
  }
  
  printf("%d", ret);

  return 0;
}
