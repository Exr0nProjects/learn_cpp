/*
ID: spoytie2
TASK: balancing
LANG: C++14
*/

/*
 * Problem balancing (usaco/bronze/2016feb/balancing)
 * Created Sat 28 Dec 2019 @ 14:03 (PST)
 * Accepted Sat 28 Dec 2019 @ 16:21 (PST)
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
vector<pair<int, int>> cows;
int n, B; // `B` is not actually used

bool cmpy(const pair<int, int> &l, const pair<int, int> &r)
{
  return l.second < r.second;
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

  stable_sort(cows.begin(), cows.end());
  for (auto c : cows)
  {
    printf("%5d", c.first);
  }
  printf("\n");
  int x = cows[n / 2].first - 1;
  stable_sort(cows.begin(), cows.end(), cmpy);
  for (auto c : cows)
    printf("%5d", c.second);
  printf("\n");
  int y = cows[n / 2].second - 1;

  printf("optimal crossing: (%d, %d)\n", x, y);
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

  fprintf(fout, "%d\n", ret);

  return 0;
}

/*
5 10000
1 9
1 5
1 1
5 3
5 -1
 => 2

8 100
1 9
5 3
3 5
7 9
9 5
9 1
11 9
13 5
=> 3
 
8 100
1 11
3 9
5 7
7 5
9 3
11 1
9 9
11 7
=> 3
 
4 10
1 1
1 3
3 1
3 3
=> 1

8 10
1 3
1 5
5 1
1 1
5 3
3 5
3 1
3 3
=> 3
 */
