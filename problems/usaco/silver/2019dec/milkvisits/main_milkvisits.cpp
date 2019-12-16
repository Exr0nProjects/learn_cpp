/*
ID: spoytie2
TASK: milkvisits
LANG: C++14
*/

/*
 * Problem milkvisits (usaco/silver/2019dec/milkvisits)
 * Created Sun 15 Dec 2019 @ 14:15 (PST)
 * Accepted [!meta:end!]
 *
 */

#include <bits/stdc++.h>

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

#define cn const int
#define ca const auto &
#define ll long long
#define cl const long long
#define UN unsigned
#define ST static
#define CN const
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
FILE* fin = fopen("milkvisits.in", "r");
FILE* fout = fopen("milkvisits.out", "w+");

const int MAXSZ = 50010; // todo
struct Cow
{
  int typ; // either 1=G or 2=H
  deque<int> paths;
  //int heuristic[MAXSZ];
} cows[MAXSZ];

int n, v;

void addEdge(cl a, cl b)
{
  cows[a].paths.push_back(b);
  cows[b].paths.push_back(a);
}

bool vis[MAXSZ];
map<pair<int, int>, int> tab;
int search(const int a, const int b, const int step = 0)
{
  //d*/ for (int i=0; i<step; ++i) printf("  "); printf("search called %d->%d\n", a, b);for (int i=0; i<step; ++i) printf("  "); printf("vis: "); for (int i=1; i<=n; ++i) printf("%3d", vis[i]); printf("\n");
  pair<int, int> tab_value= make_pair(a, b);
  if (tab.find(tab_value) != tab.end()) return tab.at(tab_value);
  if (a == b)
  {
    return cows[b].typ;
  }
  int ret = 0;
  for (int i=0; i<cows[a].paths.size(); ++i)
  {
    int idx = cows[a].paths[i];
    if (!vis[idx] && !ret)
    {
      vis[idx] = true;
      int r = search(idx, b, step+1);
      if (r)
      {
        ret |= cows[a].typ | r;
      }
      vis[idx] = false;
    }
  }
  //d*/ for (int i=0; i<step; ++i) printf("  "); printf("returning %d\n", ret);
  tab[tab_value] = ret;
  return ret;
}

int main ()
{
  if (fin) {fout = fopen("milkvisits.out", "w+");} else {fin = stdin; fout = stdout;}
  fscanf(fin, "%d%d\n", &n, &v);
  for (int i=1; i<=n; ++i)
  {
    char c;
    fscanf(fin, "%c", &c);
    cows[i].typ = (int)(c == 'H') + 1;
  }
  for  (int i=1; i<n; ++i)
  {
    int a, b;
    fscanf(fin, "%d%d", &a, &b);
    addEdge(a, b);
  }

  for (int i=1; i<=v; ++i)
  {
    int a, b;
    char c;
    int typ;
    fscanf(fin, "%d%d %c", &a, &b, &c);
    typ = (int)(c == 'H') + 1;
    vis[a] = true;
    fprintf(fout, "%d", (bool)(typ & search(a, b)));
    vis[a] = false;
  }

  fprintf(fout, "\n");

  return 0;
}

/*
3 2
HGH
1 2
1 3
1 3 G
1 3 H
=> 01
 
3 2
HGH
1 2
1 3
1 2 G
1 2 H
=> 11

// larger dataset
10 2
HHHHHHHHHH
1 2
2 3
3 4
5 4
6 5
9 8
7 8
6 7
9 10
3 4 H
1 10 G
=> 10

// circle
7 7
GHHHGGG
1 2
1 3
1 4
1 5
1 6
1 7
1 2 H
1 3 H
1 4 H
1 5 H
1 6 H
1 7 H
7 7 G
 => 1110001
 */
