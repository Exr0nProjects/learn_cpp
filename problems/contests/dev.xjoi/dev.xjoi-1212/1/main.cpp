/*
 * dev.xjoi.net c1212 1
 * 1 August 2019
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

const int MAXSZ = 1; // todo

class Node
{
  int i_x, i_y;
  Node* i_l;
public:
  /* construct */
  Node ()  { i_x=-1; i_y=-1; i_l=this; }
  Node (CN int x, CN int y)
  {
    i_x = x;
    i_y = y;
  }
  
  /* operate */
  bool operator== (Node o) const
  { return i_x == o.x() && i_y == o.y(); }
  bool operator!= (Node o) const { return !(*this == o); }
  
  /* get */
  int x () const { return i_x; }
  int y () const { return i_y; }
  Node* leader ()
  {
    for (; i_l != this;)
      i_l = i_l->leader();
    return i_l;
  }
  void print ()
  {
    printf("  (%3d,%3d): %3d,%3d", i_x, i_y, i_l->x(), i_l->y());
  }
  
  /* set */
  int merge (Node* target)
  {
    if (this == target) return 0;
    i_l->merge(target);
    
    int c;
    for (c=0; i_l != target; ++c)
    { i_l = i_l->leader(); }
    return c;
  }
} nodes[MAXSZ][MAXSZ];

int main ()
{
  int m, n;
  scanf("%d%d", &m, &n);
  
  for (int i=1; i<=n; ++i)
    for (int j=1; j<=m; ++j)
      nodes[i][j] = Node {i, j};
  
  int ai, aj, bi, bj;
  while (cin >>ai>>aj>>bi>>bj)
    nodes[ai][aj].merge( &(nodes[bi][bj]) );
  
  UN LL ans = 0;
  
  for (int j=1; j<=m; ++j)
    for (int i=1; i<n; ++i)
    {
      nodes[i][j].merge( &(nodes[i+1][j]) );
      ++ ans;
    }
  
  for (int i=1; i<=n; ++i)
    for (int j=1; j<m; ++j)
    {
      nodes[i][j].merge( &(nodes[i][j+1]) );
      ans += 2;
    }
  
  printf("%lld", ans);
  
  return 0;
}
