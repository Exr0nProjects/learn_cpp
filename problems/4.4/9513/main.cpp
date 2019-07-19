/*
 * Problem #9513
 * Inputting and storing big trees
 */

#include <bits/stdc++.h> // includes "everything"
#define ll long long
#define dl double
#define i32x 2147483647

using namespace std;

const int MAXSZ = 100010;

struct edge
{
  int nn, ne; // next node, next edge
} edges[MAXSZ];

int head[MAXSZ] = { };
int valu[MAXSZ] = { };

void dfs (int cur, const int amt)
{
  valu[edges[cur].nn] += amt;
  dfs(head[edges[cur].nn], amt);

  if (edges[cur].ne) dfs(edges[cur].ne, amt); // propogate
}

int main ()
{
  int n, q;
  scanf("%d %d\n", &n, &q);

  for (int i=0; i<n; ++i)
  {
    int a, b;
    scanf("%d %d\n", &a, &b);
    if (head[b]) swap(a, b); // a is the existing node, and b is the new one
    // initiate the new link
    edge temp;
    temp.nn = b;
    temp.ne = 0;
    // find the last link in the proper linked list
    int tpt = &edges[head[a]].ne;
    while (edges[tpt].ne) tpt = edges[tpt].ne; // find the last thing in the linked list
    // update it
    edges[tpt].ne = i;
    edges[i] = temp;
  }

  for (int i=0; i<q, ++i)
  {
    int bs, ad;
    scanf("%d %d\n", &bs, &ad);
    dfs( head[bs], ad );
  }

  for (int i=0; i<n; ++i) printf("%d ", valu[i]);

  return 0;
}
