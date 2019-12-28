/*
ID: spoytie2
TASK: balancing
LANG: C++14
*/

/*
 * Problem balancing (usaco/bronze/2016feb/balancing)
 * Created Sat 28 Dec 2019 @ 14:03 (PST)
 * Accepted [!meta:end!]
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
FILE *fin = fopen("balancing.in", "r");
FILE *fout = nullptr;

const int MAXSZ = 110; // todo
vector< pair<int, int> > cows;
int n, B;

int bash(cn x, cn y)
{
  int count[2][2] = {};
  int ret = 0;
  for (const auto &p : cows)
  {
    int i = 0, j = 0;
    if (p.first > x)
      i = 1;
    if (p.second > y)
      j = 1;
    ++count[i][j];
    ret = max(ret, count[i][j]);
  }
  return ret;
}

int main()
{
  if (fin)
  {
    fout = fopen("balancing.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }
  fscanf(fin, "%d%d", &n, &B);
  for (int i = 0; i < n; ++i)
  {
    int x, y;
    fscanf(fin, "%d%d", &x, &y);
    cows.push_back(make_pair(x, y));
  }

  int ret = 1000000000;
  for (int x = 0; x <= B; x += 2)
  {
    for (int y = 0; y <= B; y += 2)
    {
      ret = min(ret, bash(x, y));
    }
  }
  fprintf(fout, "%d\n", ret);
  return 0;
}
/**/
