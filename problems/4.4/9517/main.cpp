/*
 * Problem #9517
 * guard the palace
 */

#include <cstdio>
#include <algorithm>
#define ll long long
#define dl double
#define i32x 2147483647

using namespace std;

const int MAXSZ = 1600;

struct Path
{
  int from=0, to=0, next=0;
} paths[MAXSZ];

int head[MAXSZ] = { };
int cost[MAXSZ] = { };

int mincost(int cur)
{
  //  printf("    curr: %d, calculating...\n", cur);
  if (head[cur] == 0) return cost[cur];
  int sum = 0;
  for (int pt=head[cur]; pt != 0; pt = paths[pt].next)
    sum += mincost(paths[pt].to);

  //  printf("    cur: %d, sum = %d\n", cur, sum);

  return min(cost[cur], sum);
}

int main ()
{
  paths[0].next = 1;
  paths[0].from = 0;
  paths[0].to = 1;

  int n, pt=1;
  scanf("%d", &n);
  for (int i=1; i<=n; ++i)
  {
    int idx, c, _n;
    scanf("%d %d %d", &idx, &c, &_n);

    // create all the branching paths
    for (int j=0; j<_n; ++j)
    {
      int target;
      scanf("%d", &target);

      paths[pt].next = head[idx];
      head[idx] = pt;

      paths[pt].from = idx;
      paths[pt].to = target;
      ++pt;
    }

    cost[idx] = c;
  }

  int cost = mincost(1);
  printf("%d", cost);

  return 0;
}

/*

 2
 1 5 1 2
 2 3 0

3
1 8 1 2 3
2 3 0
3 2 0


 */
