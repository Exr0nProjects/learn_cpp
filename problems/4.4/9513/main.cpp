/*
 * Problem #9513
 *
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
  int nn=0, ne=0; // next node, next edge
} edges[MAXSZ];

int head[MAXSZ] = {0, 1};
int valu[MAXSZ] = { };

void dfs (const int cur, const int amt)
{
//d  printf("    dfs called\n");
  valu[edges[cur].nn] += amt;

  if (head[edges[cur].nn] > 0) dfs(head[edges[cur].nn], amt);
  if (edges[cur].ne > 0) dfs(edges[cur].ne, amt); // propogate
}

int main ()
{
  int n, q;
  scanf("%d %d", &n, &q);

  for (int i=1; i<n; ++i)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    if (head[b] == 0) { int t = a; a = b; b = t; } // a is the existing node, and b is the new one
 //d   printf("%d %d\n\n", a, b);
    // update heads
    head[b] = -1;
    // initiate the new link
    edge temp;
    temp.nn = b;
    temp.ne = 0;

    // find the last link in the proper linked list
    int tpt;
    if (head[a] > 0)
    {
      tpt = edges[head[a]].ne;
      while (edges[tpt].ne != 0) tpt = edges[tpt].ne; // find the last thing in the linked list
      edges[tpt].ne = i;
    }
    else if (head[a] == -1)
    { // create new
      printf("    creating new head: [%d]  => %d\n", a, i);
      head[a] = i;
    }
     edges[i] = temp;
  }

//d  printf("input part one finished...\n\n");

  for (int i=0; i<q; ++i)
  {
    int bs, ad;
    scanf("%d %d", &bs, &ad);
    if (bs == 1) valu[bs] += ad;
    dfs( head[bs], ad );
  }

 //d printf("about to print!\n");

  for (int i=1; i<=n; ++i) printf("%d\n", valu[i]);

  return 0;
}

/*

5 3
2 1
3 2
3 4
3 5
1 47
3 4
1 63


 */
