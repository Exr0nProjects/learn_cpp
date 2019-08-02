/*
 * Problem #9501
 * Fri 02 Aug 2019 @ 15:24 CST)
 * node weights
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

class EdgeList
{
  friend void dfc (const int, const int, const int);
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
  int head[MAXSZ];
  UN size = 0;
public:
  void addEdge (CN int a, CN int b)
  {
    ++size;
    edges[size] = Edge (b, head[a]);
    head[a] = size;
  }
} el;

int weights[MAXSZ];
void dfc (const int cur, const int pre, const int lyr)
{
  
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
  
  for (int i=1; i<=num; ++i)
  {
    printf("%d\n", weights[i]);
  }

  return 0;
}
/*
6
2 1
2 3
2 4
2 5
6 5
*/