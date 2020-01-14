/*
ID: spoytie2
TASK: balancing
LANG: C++14
*/

/*
 * Problem balancing (usaco/silver/2016feb/balancing)
 * Create time: Mon 13 Jan 2020 @ 20:15 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <cmath>
#include <random>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <string>
#include <vector>
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
FILE *_ = stderr;

const int MAXSZ = 1010; // todo
int N;
int pos_x[MAXSZ], pos_y[MAXSZ];
vector<pair<int, int>> pos;

int main()
{
  if (fin)
  {
    stdin = fin;
    stdout = fopen("balancing.out", "w+");
  }
  scanf("%d", &N);
  for (int i = 0; i < N; ++i)
  {
    scanf("%d%d", &pos_y[i], &pos_x[i]);
    pos.push_back(make_pair(pos_y[i], pos_x[i]));
  }

  if (N <= 2)
  {
    printf("1\n");
    return 0;
  }

  stable_sort(pos_y, pos_y + N);
  stable_sort(pos_x, pos_x + N);

  int ret = INT32_MAX;
  for (int i = max(0, N / 2 - 100); i < min(N, N / 2 + 100); ++i)
  //  for (int i=0; i<N; ++i)
  {
    int dy = pos_y[i] + 1;
    for (int j = max(0, N / 2 - 100); j < min(N, N / 2 + 100); ++j)
    //    for (int j=0; j<N; ++j)
    {
      int dx = pos_x[i] + 1;
      int a, b, c, d, mx;
      a = b = c = d = mx = 0;
      for (ca cow : pos)
      {
        if (cow.first < dy && cow.second < dx)
          ++a;
        if (cow.first < dy && cow.second > dx)
          ++b;
        if (cow.first > dy && cow.second < dx)
          ++c;
        if (cow.first > dy && cow.second > dx)
          ++d;
      }
      ret = min(ret, max(max(a, b), max(c, d)));
    }
  }

  printf("%d\n", ret);

  return 0;
}
