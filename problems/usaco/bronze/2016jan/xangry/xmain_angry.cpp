/*
ID: spoytie2
TASK: angry
LANG: C++14
*/

/*
 * Problem angry (usaco/bronze/2016jan/angry)
 * Created Sat 28 Dec 2019 @ 10:15 (PST)
 * Accepted Sat 28 Dec 2019 @ 10:45 (PST)
 *
 */

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
FILE *fin = fopen("angry.in", "r");
FILE *fout = nullptr;

const int MAXSZ = 110; // todo
int bales[MAXSZ];
bool vis[MAXSZ];
queue<pair<int, int>> q;
int N;

void simulate(cn i, cn s)
{
  for (int j = 0; j < s; ++j)
    printf("  ");
  printf("simulate called (%d, %d)\n", bales[i], s);

  vis[i] = true;
  for (int p = i - 1; p >= 0 && bales[i] - s <= bales[p]; --p) // left
  {
    if (vis[p])
      continue;
    q.push(make_pair(p, s + 1));
  }
  for (int p = i + 1; p < N && bales[i] + s >= bales[p]; ++p) // right
  {
    if (vis[p])
      continue;
    q.push(make_pair(p, s + 1));
  }
}

int main()
{
  if (fin)
  {
    fout = fopen("angry.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }

  fscanf(fin, "%d", &N);
  for (int i = 0; i < N; ++i)
  {
    fscanf(fin, "%d", &bales[i]);
  }

  stable_sort(bales, bales + N);

  ll ret = 0;
  for (int i = 0; i < N; ++i)
  {
    ll t = 0;
    for (int j = 0; j < N; ++j)
      vis[j] = false;
    q.push(make_pair(i, 1));
    for (; !q.empty(); q.pop())
    {
      if (vis[q.front().first])
        continue;
      simulate(q.front().first, q.front().second);
      ++t;
    }
    ret = max(ret, t);
  }
  fprintf(fout, "%lld\n", ret);

  return 0;
}

/*
6
3
4
5
6
8
13
 */
