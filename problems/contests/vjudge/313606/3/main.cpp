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

typedef int node;
typedef int edid;

using namespace std;

const int MAXSZ = 100010; // todo

struct Edges
{
  node to=0;
  edid next=0;
} edges[2*MAXSZ];

edid head[MAXSZ] = { };
bool vis[MAXSZ] = { };

inline void addEdge (const node a, const node b, const bool con=true)
{
  static int cur = 0;

  edges[++cur].to = b;
  edges[cur].next = head[a];
  head[a] = cur;

  //if (con) addEdge(b, a, false);
}

inline void bfc ()
{
  static priority_queue< node, vector<node>, greater<node> > que;
  que.push(1);
  vis[1] = true;


  for (; !que.empty();)
  {
    // we need this because pushing to the queue can change the top element, so we need to store it and pop it immedietly before we push anything.
    int top = que.top();
    que.pop();

    printf("%d ", top);

    for (edid i=head[top]; i; i = edges[i].next)
    {
      if (!vis[edges[i].to])
      {
        que.push(edges[i].to);
        vis[edges[i].to] = true;
      }
    }
  }
}


int main ()
{
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i=0; i<m; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    addEdge(a, b);
    addEdge(b, a);
  }

//  printf("%d %d\n\n", edges[0].to, head[0]);

  bfc();

  return 0;
}
