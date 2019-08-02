/*
 * Problem #1
 * Fri 02 Aug 2019 @ 09:37 CST)
 * @mention thingy
 *
 * Everyone is using a "bei4 zen1" method, where you take things by powers of 2. There does not seme to be a good translation for this and I don't know how to do it, so there is probably no way for me to do this prbolem.
 *
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

const int MAXSZ = 110; // todo
int size, layersadd;

class EdgeList
{
  friend void dfc(const int, const int, const int, const int[]);
public:
  struct Edge
  {
    int to, next;
    Edge ()
    {
      to = 0;
      next = 0;
    }
    Edge (const int t, const int n)
    {
      to = t;
      next = n;
    }
  };
private:
  Edge edges[MAXSZ];
  int head[MAXSZ] = { };
  unsigned size = 0;
public:
  EdgeList () {}
  
  /* get */
  const unsigned getSize () const
  { return size; }
  
  void addEdge (int  a, int b)
  {
    ++size;
    edges[size] = Edge(b, head[a]);
    head[a] = size;
  }
};

EdgeList el;

int mentions[MAXSZ] = { };
void dfc (const int cur=1, const int pre=0, const int lyr=1, const int layers[]={})
{
  for (int i=0; i<size; ++i)
    if (lyr-layers[i] <= layersadd && lyr-layers[i]>0) ++ mentions[i];
  for (int id=el.head[cur]; id != 0; id=el.edges[id].next)
  {
    if (el.edges[id].to == pre) continue;
    dfc(el.edges[id].to, cur, lyr+1);
  }
}

int main ()
{
  scanf("%d%d", &size, &layersadd);
  for (int i=1; i<size; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    el.addEdge(a, b);
    el.addEdge(b, a);
  }
  
  dfc();
  
  for (int i=0; i<size; ++i)
  {
    printf("%d\n", mentions[i]);
  }
  
  return 0;
}
