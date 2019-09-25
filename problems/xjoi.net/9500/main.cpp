/*
 * Problem #9500
 * Fri 02 Aug 2019 @ 11:33 CST)
 * output father of nodes
 */

#include <bits/stdc++.h>

using namespace std;

const int MAXSZ = 1000010; // todo

class EdgeList
{
  friend void dfc (const int, const int, const int);
public:
  struct Edge
  {
    int to, next;
    Edge () {to=0; next=0;}
    Edge (const int t, const int n)
    {
      to = t;
      next = n;
    }
  };
private:
  Edge edges[2*MAXSZ] = { };
  int head[MAXSZ] = { };
  unsigned size = 0;
public:
  EdgeList () {}
  
  void addEdge (const int a, const int b)
  {
    ++size;
    edges[size] = Edge(b, head[a]);
    head[a] = size;
  }
};

EdgeList el;
int parents[MAXSZ] = { };
void dfc (const int cur=1, const int pre=0, const int lyr=1)
{
  for (int id=el.head[cur]; id != 0; id = el.edges[id].next)
  {
    if (el.edges[id].to == pre) continue;
    parents[el.edges[id].to] = cur;
    dfc(el.edges[id].to, cur, lyr+1);
  }
}

int main ()
{
  int num;
  scanf("%d", &num);
  for (int i=1; i<num; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    el.addEdge(a, b);
    el.addEdge(b, a);
  }
  
  dfc();
  
  for (int i=2; i<=num; ++i)
  {
    printf("%d\n", parents[i]);
  }
  
  return 0;
}
