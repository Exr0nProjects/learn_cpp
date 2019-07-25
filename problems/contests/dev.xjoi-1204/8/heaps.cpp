/*
 * c1204-8
 * 24 Jul 2019
 */

#include <iostream>
#include <cstdio>
#include <exception>
#include <algorithm>
#include <utility>
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

const int MAXSZ = 110; // todo

struct Hampster
{
  int expire=0, worth=0;
} hamps[MAXSZ], hheap[MAXSZ];

bool hamp_cmp (const Hampster a, const Hampster b)
{
  return a.expire < b.expire;
}

void heapifyd (const int root)
{
  if (hheap[root*2].worth < hheap[root].worth && hheap[root*2].worth < hheap[root*2+1].worth && hheap[root*2].expire > 0)
  {
    swap<Hampster> (hheap[root*2], hheap[root]);
    heapifyd(root * 2);
  }
  else if (hheap[root*2+1].worth < hheap[root].worth && hheap[root*2+1].expire > 0)
  {
    swap<Hampster> (hheap[root*2+1], hheap[root]);
    heapifyd(root * 2 + 1);
  }
}

void heapifyu (const int root)
{
  if (hheap[root].worth < hheap[root/2].worth && root != 1)
  {
    swap<Hampster> (hheap[root/2], hheap[root]);
    heapifyu (root/2);
  }
}

int main ()
{
  int num, hsz=1, ret=0;
  scanf("%d", &num);
  for (int i=0; i<num; ++i) scanf("%d", &hamps[i].expire);
  for (int i=0; i<num; ++i) scanf("%d", &hamps[i].worth);

  sort(hamps, hamps + num, hamp_cmp);

  for (int i=0; i<num; ++i)
  { // do heapy thing
    if (hamps[i].expire == hsz  && hamps[i].worth > hheap[1].worth)
    {
      ret -= hheap[1].worth;
      hheap[1] = hamps[i];
      ret += hheap[1].worth;
      heapifyd(1);
    }
    else if (hamps[i].expire > hsz)
    {
      hheap[++hsz] = hamps[i];
      ret += hamps[i].worth;
      heapifyu(hsz);
    }
//    printf("  %d\n", ret);
  }

  printf("%d", ret);

  return 0;
}
