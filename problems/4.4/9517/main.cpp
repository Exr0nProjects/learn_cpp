/*
 * Problem #9517
 * guard the palace
 */

#include <bits/stdc++.h> // includes "everything"
#define ll long long
#define dl double
#define i32x 2147483647

using namespace std;

const int MAXSZ = 1600;

struct Path
{
  int from=0, to=0, next=0, cost=-1;
} paths[MAXSZ];

int head[MAXSIZE] = { };
int hend[MAXSIZE] = { };

int main ()
{
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i=0; i<n; ++i)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    if (head[b] != 0) { int t=a; a=b; b=t; }
    head[b] = -1;

    if (head[a] > 0)
    {
      paths[hend[a]].next = i;
      hend[a] = i;
    }
    else if (head[a] == -1)
    {
      head[a] = hend[a] = i;
      
    }
  }

  return 0;
}
