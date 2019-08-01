/*
 * dev.xjoi.net c1207 -1
 * 25 July 2019 AM
 */


#include <iostream>
#include <cstdio>
#include <exception>
#include <algorithm>
#include <math.h>
#include <random>
#include <tuple>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>

#define ll long long
#define dl double
#define i32x 2147483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 100010; // todo

struct Tree
{
  int pos, hih;
} forest[MAXSZ];

int main ()
{
  int num;
  scanf("%d", &num);
  for (int i=0; i<num; ++i)
    scanf("%d%d", &forest[i].pos, &forest[i].hih);

  sort(forest, forest + num, [] (const Tree a, const Tree b) { return a.pos < b.pos; } );

  ll sum=0;
  for (int i=0; i<num; ++i)
  {
    int mmin = forest[i].hih;
    if (i>0) mmin = abs(forest[i].pos - forest[i-1].pos);
    if (i<num-1) mmin = min(mmin, abs(forest[i].pos - forest[i+1].pos));
    if (mmin == 0) sum += forest[i].hih;
    else sum += max( forest[i].hih-mmin, 0 );
  }

  printf("%lld", sum);

  return 0;
}
