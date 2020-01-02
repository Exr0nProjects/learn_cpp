/*
ID: spoytie2
TASK: buckets
LANG: C++14
*/

/*
 * Problem buckets (usaco/bronze/2019open/buckets)
 * Created Thu 02 Jan 2020 @ 10:12 (PST)
 * Accepted Thu 02 Jan 2020 @ 10:31 (PST)
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
FILE *fin = fopen("buckets.in", "r");
FILE *_ = stderr;

const int MAXSZ = 10; // todo
char farm[MAXSZ + 4][MAXSZ + 4];
int y, x;

struct Step
{
  int y, x, step;
  Step(cn _y, cn _x, cn _step)
  {
    y = _y;
    x = _x;
    step = _step;
  }
};

void debug()
{
  return;
  for (int i = 0; i <= MAXSZ + 1; ++i)
  {
    for (int j = 0; j <= MAXSZ + 1; ++j)
      fprintf(_, "%2c", farm[i][j]);
    fprintf(_, "\n");
  }
}

int main()
{
  if (fin)
  {
    stdin = fin;
    stdout = fopen("buckets.out", "w+");
  }

  for (int i = 0; i <= MAXSZ + 1; ++i)
  {
    for (int j = 0; j <= MAXSZ + 1; ++j)
    {
      if (i > 0 && i <= MAXSZ && j > 0 && j <= MAXSZ)
        scanf("%c", &farm[i][j]);
      else
        farm[i][j] = 'R';

      if (farm[i][j] == 'B')
      {
        y = i;
        x = j;
      }
    }
    if (i < MAXSZ)
      scanf("\n");
  }

  queue<Step> q;
  for (q.push(Step(y, x, 0)); !q.empty(); q.pop())
  {
    ca s = q.front();
    if (farm[s.y][s.x] == 'X')
      continue; // already visited
    if (farm[s.y][s.x] == 'L')
    {
      printf("%d\n", s.step - 1);
      break;
    }
    debug();

    farm[s.y][s.x] = 'X';
    for (ca dir : vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
    {
      //d*/fprintf(_, "mod: %+2d, %+2d\n", dir.first, dir.second);
      if (farm[s.y + dir.first][s.x + dir.second] == '.' || farm[s.y + dir.first][s.x + dir.second] == 'L')
      {
        q.push(Step(s.y + dir.first, s.x + dir.second, s.step + 1));
      }
    }
  }

  return 0;
}
