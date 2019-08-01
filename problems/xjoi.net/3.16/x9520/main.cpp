/*
 * Problem #9520
 * Thu 01 Aug 2019 @ 13:30 CST
 * depth of tree
 */

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

#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 1000010; // todo

class Edge
{
  static int c_head [MAXSZ];
  static Edge c_edges [2*MAXSZ];
  
  int i_from, i_to, i_next;
public:
  static int head (const int id) { return c_head[id]; }
  static Edge* get (const int id) { return &c_edges[id]; }
  
  static void add (const int, const int);
  
  /* per instance */
  Edge ()
  {
    i_from = -1;
    i_to = -1;
    i_next = 0;
  }
  Edge (const int from, const int to, const int next=0)
  {
    i_from = from;
    i_to = to;
    i_next = next;
  }
  
  int next () const { return i_next; }
  int to () const { return i_to; }
};

int Edge::c_head[MAXSZ] = { };
Edge Edge::c_edges[2*MAXSZ] = { };

void Edge::add (const int a, const int b)
{
  ST UN next = 1;
  
  c_edges[next] = Edge (a, b, c_head[a]);
  c_head[a] = next;
  ++ next;
}



int dfc (const int cur=1, const int pre=1, const int lyr=0)
{
  static int mmax = 0;
  
  mmax = max(lyr, mmax);
  
  if (Edge::get(cur)->to() == 0) return mmax;
  
  for (int i=Edge::head(cur); i != 0; i = Edge::get(i)->next())
    if (Edge::get(i)->to() != pre)
      dfc(Edge::get(i)->to(), cur, lyr+1);
  return mmax;
}



int main ()
{
  int num;
  scanf("%d", &num);
  for (int i=1; i<=num; ++i)
  {
    scanf("\n");
    for (int j=1; j<=num; ++j)
    {
      int c;
      scanf("%1d", &c);
      if (c == 1)
      {
        Edge::add(i, j);
      }
    }
  }
  
  printf("%d", dfc());
  
  return 0;
}
