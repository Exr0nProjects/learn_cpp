/*
 * Problem #9513
 * Tree input and traversing
 */

//#include <bits/stdc++.h> // includes "everything"
#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>
#define ll long long
#define dl double
#define i32x 2147483647

using namespace std;

const int MAXSZ = 100010;

struct edge
{
  int from=-1, nn=0, ne=0; // next node, next edge
} edges[MAXSZ];

int head[MAXSZ] = {0, 1};
int hend[MAXSZ] = { };
ll valu[MAXSZ] = { };

inline void dfs (const int cur, const ll amt)
{
//d  printf("    dfs called\n");
  valu[edges[cur].nn] += amt;
  if (head[edges[cur].nn] > 0) dfs(head[edges[cur].nn], valu[edges[cur].nn]);
  if (edges[cur].ne > 0) dfs(edges[cur].ne, valu[edges[cur].nn]);
}

int main ()
{
  int n, q;
  scanf("%d %d", &n, &q);

  for (int i=1; i<n; ++i)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    if (head[b] != 0) { int t = a; a = b; b = t; } // a is the existing node, and b is the new one
 //d   printf("%d %d\n\n", a, b);
    // update heads
    head[b] = -1;
    // initiate the new link
    edge temp;
    temp.from = a;
    temp.nn = b;
    temp.ne = 0;

    // find the last link in the proper linked list
    if (head[a] > 0)
    {
      edges[hend[a]].ne = i;
    }
    else if (head[a] == -1)
    { // create new
//d      printf("    creating new head: [%d]  => %d\n", a, i);
      head[a] = i;
    }
    edges[i] = temp;
    hend[a] = i;
  }

//d  printf("input part one finished...\n\n");

  for (int i=0; i<q; ++i)
  {
    int bs, ad;
    scanf("%d %d", &bs, &ad);
    valu[bs] += ad;
  }

  dfs(head[1], valu[1]);

 //d printf("about to print!\n");

  for (int i=1; i<=n; ++i) printf("%lli\n", valu[i]);

  return 0;
}
