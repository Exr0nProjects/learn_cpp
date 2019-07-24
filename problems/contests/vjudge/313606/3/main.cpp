/*
 * Vjudge 313606 3
 * 24 July 2019
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

const int MAXSZ = 10000010; // todo

struct Edges
{
  int to=0, next=0;
} edges[MAXSZ];

int head[MAXSZ];
int tail[MAXSZ];

inline void addEdge (int a, int b)
{
  if (head[a] > 0) edges[tail[a]].next = b;
  else head[a] = b;
  tail[a] = b;
  edges[b].to = b;

  if (head[b] > 0) edges[tail[b]].next = a;
  else tail[b] = a;
  tail[b] = a;
  edges[a].to = a;
}

int mheap[MAXSZ], mhpt = 1;
void hadd (int id)
{
  mheap[mhpt] = id;
  int temp = mhpt;
  for (; temp != 1 && mheap[temp/2] > mheap[temp];)
  {
    swap(mheap[temp/2], mheap[temp]);
  }
  ++ mhpt;
}
void hdel (int id)
{
  -- mhpt;
  swap(mheap[1], mheap[mhpt]);

  for (int temp = mhpt; mheap[temp*2] > 0 || mheap[temp*2+1];)
  {
    if (mheap[temp] > mheap[temp*2] && mheap[temp*2] > 0 && mheap[temp*2] > mheap[temp*2+1])
    {
      swap( mheap[temp], mheap[temp*2] );
    }
    else if (mheap[temp] > mheap[temp*2+1] && mheap[temp*2+1] > 0)
    {
      swap( mheap[temp], mheap[temp*2] );
    }
    else break;
  }
}

inline void dfc (int cur, int pre)
{

}


int main ()
{
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i=0; i<n; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    addEdge(a, b);
  }

  dfc(1, 0);

  return 0;
}
