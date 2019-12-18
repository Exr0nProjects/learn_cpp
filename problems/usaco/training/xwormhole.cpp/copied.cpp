// based on https://www.youtube.com/watch?v=KR4iY-EfEs4

/*
ID: spoytie2
TASK: wormhole
LANG: C++14
*/

#include <bits/stdc++.h>

#define ll long long
#define cl const long long
#define ca const auto &
#define MP make_pair
const int MAXSZ = 20;

using namespace std;

FILE *fin = fopen("wormhole.in", "r");
FILE *fout = nullptr;

struct WH
{
  int x, y;
  WH(){};
  WH(int a, int b) : x(a), y(b){};
};
ll partner[MAXSZ];
ll next_on_right[MAXSZ];
ll n;

bool cycle_exists(const vector<WH> &wormholes)
{
  for (int i = 1; i < wormholes.size(); ++i)
  {
    ll wh = i;
    for (int s = 0; s < n; ++s)
    {
      wh = partner[next_on_right[wh]];
    }
    if (wh != 0)
      return true;
  }
  return false;
}

ll rearrange(const vector<WH> &wormholes, cl s = 0)
{
  ll a = 1, b = 1;
  for (; a < wormholes.size(); ++a)
  {
    if (!partner[a])
    {
      break;
    }
  }
  if (a >= wormholes.size())
  {
    return cycle_exists(wormholes);
  }

  ll ret = 0;
  for (b = a + 1; b < wormholes.size(); ++b)
  {
    if (!partner[b])
    {
      //d*/printf("new pair! %d, %d\n", a, b);
      partner[a] = b;
      partner[b] = a;
      ret += rearrange(wormholes);
      partner[a] = partner[b] = 0;
    }
  }

  return ret;
}

int main()
{
  if (fin)
  {
    fout = fopen("wormhole.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }
  fscanf(fin, "%lld", &n);

  vector<WH> wormholes(1);
  for (int i = 1; i <= n; ++i)
  {
    int x, y;
    fscanf(fin, "%d%d", &x, &y);
    wormholes.push_back({x, y});
  }
  for (int i = 1; i < wormholes.size(); ++i) // init next on right
  {
    for (int j = 1; j < wormholes.size(); ++j)
    {
      if (wormholes[i].y == wormholes[j].y && wormholes[i].x < wormholes[j].x && (next_on_right[i] == 0 || wormholes[next_on_right[i]].x > wormholes[j].x))
      {
        next_on_right[i] = j;
      }
    }
  }

  int c = 0;
  for (const auto &wh : wormholes)
  {
    printf("%3d, %3d: %3d\n", wh.x, wh.y, next_on_right[c]);
    ++c;
  }

  fprintf(fout, "%lld\n", rearrange(wormholes));
}
