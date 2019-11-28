/*
ID: spoytie2
TASK: learning
LANG: C++14
*/

/*
 * Problem learning (usaco/bronze/learning)
 * Created Wed 27 Nov 2019 @ 12:24 (PST)
 * Accepted [!meta:end!]
 * problem # 490
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
auto fin = fopen("learning.in", "r");
auto fout = fopen("learning.out", "w+");

const int MAXSZ = 50010; // todo
struct Cow
{
  bool s;
  int w;
  bool operator<(const Cow& o) const { return w < o.w; }
} herd[MAXSZ];
int n, a, b;

void debug()
{
  bool d = true;
  /*/d*/ d = false;
  if (d) return;
  for (int i=0; i<n; ++i)
  {
    printf("%d: %d, ", herd[i].w, herd[i].s);
  }
}

int main ()
{
  int ret = 0;
  
  //fscanf(fin, "%d%d%d", &n, &a, &b);
  fscanf(fin, "%d%d%d", &n, &a, &b);
  for (int i=0; i<n; ++i)
  {
    char s[5];
    //fscanf(fin, "%s%d", &s, &herd[i].w);
    fscanf(fin, "%s%d", &s, &herd[i].w);
    herd[i].s = s[0] == 'S';
    if (herd[i].w <= b && herd[i].w >= a && herd[i].s) ++ ret; // in range and is spotted
  }
  stable_sort(herd, herd+n);

  debug();
  /*/d*/ printf("ret = %d\n", ret);
  
  for (int i=1; i<n; ++i)
  {
    int pad = (herd[i].w-herd[i-1].w+1)/2-1; // the distance each herd cow "extends"
    int even = (herd[i].w-herd[i-1].w+1)%2; // one if the distance is even (there is a tie cow) and zero if not
    if (herd[i].w <= b && herd[i-1].w >= a) // segment fully w/in range
    {
      if (herd[i].s == herd[i-1].s) // segment full of the same type
      {
        ret += ( herd[i].w - herd[i-1].w -1 ) * herd[i].s; // all of the ones in between will count if spotted
      }
      else
      {
        ret += pad + even; // additional one if the distance between was even
      }
    }
    else if (herd[i-1].w < a && herd[i].w > a) // segment goes too far down
    {
      if (herd[i-1].s == herd[i].s) // same type
      {
        ret += (herd[i].w - a) * herd[i].s; // add seg between upper bound and a, if upper bound is spotted
      }
      else if (herd[i].s && !herd[i-1].s) // upper half is spotted
      {
        ret += (herd[i].w - max(a, herd[i].w-pad-even)); // add segment either to the pad or to where the incoming cows start
      }
      else if (herd[i-1].s && !herd[i].s) // lower half is spotted
      {
        ret += (min(a, herd[i-1].w+pad+even) - herd[i-1].w); // same as above but for the lower bound
      }
    }
    else if (herd[i].w > b && herd[i-1].w < b) // segment goes too far up
    {
      if (herd[i-1].s == herd[i].s) // same type
      {
        ret += (b-herd[i-1].w) * herd[i-1].s; // add the entire segment between lower of herd cow seg and upper bound
      }
      else if (herd[i].s && !herd[i-1].s) // upper half is spotted
      {
        ret += max(b - (herd[i].w - pad - even)+1, 0); // add however many we can
      }
      else if (herd[i-1].s && !herd[i].s) // lower half is spotted
      {
        ret += min(herd[i-1].w+pad+even, b) - herd[i-1].w; // same, but for lower
      }
    }
    /*/d*/ printf("after seg %d, ret = %d\n", i, ret);
  }
  
  // if incoming cows are out of bounds of the segments
  if (b > herd[n-1].w) ret += (b-herd[n-1].w) *herd[n-1].s;
  if (a < herd[0].w) ret += (herd[0].w - a) *herd[0].s;
  
  //fprintf(fout, "%d\n", ret);
  fprintf(fout, "%d\n", ret);

  return 0;
}

/*
3 1 10
S 10
NS 4
S 1
 => 6
 
3 4 10
S 10
NS 4
S 1
 => 4

3 4 14
S 10
NS 4
S 1
 => 8

3 1 10
S 10
NS 4
S 3
 => 7

2 1 200
S 23
NS 24
 => 23

5 1 20
S 5
S 25
NS 26
S 10
NS 11
 => 13
 */
