#include <bits/stdc++.h>
#define cn const int
using namespace std;
cn MAXSZ = 500010;
struct Link
{
  int v;
  Link *n;
  Link(cn _v, Link *_n)
  {
    v = _v;
    n = _n;
  }
} * head[MAXSZ];
bool vis[500000010]; // for min sorted diff

int n, m;
int main()
{
  int gmax = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
  {
    int a;
    scanf("%d", &a);
    head[i] = new Link(a, head[i]);
    vis[a] = true;
    gmax = max(gmax, a);
  }
  for (int i = 1; i <= n * 10; ++i)
    printf("%3d", vis[i]);
  printf("\n\n");
  for (int i = 1; i <= m; ++i)
  {
    char c[20];
    scanf("\n%s ", &c);
    if (c[4] == 'R')
    {
      printf("insert\n");
      int a, b;
      scanf("%d%d", &a, &b);
      Link *c;
      for (c = head[a]; c->n; c = c->n)
        ;
      c->n = new Link(b, nullptr);
      gmax = max(gmax, a);
    }
    else if (c[4] == 'G')
    { // min gap
      printf("min\n");
      int p = -1000000, mn = 1000000;
      for (int i = 1; i < n; ++i)
      {
        for (Link *j = head[i]; j->n; j = j->n)
        {
          mn = min(mn, abs(j->v - p));
        }
      }
      printf("%d\n", mn);
    }
    else if (c[4] == 'S')
    {
      int mn = 1000000, cm = 0;
      for (int i = gmax - 1; i >= 0; --i)
      { // count the spaces between numbers
        printf("minsort\n");
        if (vis[i])
        {
          mn = min(mn, cm);
          cm = 0;
        }
        else
        {
          ++cm;
        }
      }
      printf("%d\n", mn + 1);
    }
  }
}
