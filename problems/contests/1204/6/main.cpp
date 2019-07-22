/*
 * c1204-6
 * tree depth/width
 */

#include <cstdio>
#include <algorithm>
#define ll long long
#define dl double
#define i32x 2147483647

using namespace std;

const int MAXSZ = 10010;

struct Edge
{
  int to, next;
} edges[MAXSZ];

int heads[MAXSZ];
int tails[MAXSZ];

int maxw[MAXSZ];

int retd=0;

void dfs(const int beg, int cd)
{
  if (cd > retd) retd = cd;
  ++ maxw[cd];

  for (int ed = heads[beg]; ed; ed = edges[ed].next)
  {
    if (edges[ed].to) dfs(edges[ed].to, cd+1);
  }
}

int main ()
{
  int num, newpt=1;
  scanf("%d", &num);
  for (int i=0; i<num; ++i)
  {
    int t;
    scanf("%d", &t);
    for (int j=0; true; ++j)
    {
      char _t;
      scanf("%c", &_t);
      if (_t == '\n') break; // todo: could be an issue

      int tn;
      scanf("%d", &tn);
      edges[newpt].to = tn;

      if (heads[t] == 0)
        heads[t] = newpt;
      else
        edges[tails[t]].next = newpt;
      tails[t] = newpt;
      ++ newpt;
    }
  }

  dfs(1, 1);

  printf("%d\n", retd);
  int widmax = 0;
  for (int i=0; i<num; ++i)
  {
    if (maxw[i] > widmax) widmax = maxw[i];
  }
  printf("%d",  widmax);

  return 0;
}
