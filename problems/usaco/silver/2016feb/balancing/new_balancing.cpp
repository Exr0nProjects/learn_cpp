/*
ID: spoytie2
TASK: balancing
LANG: C++14
*/

/*
 * Problem balancing (usaco/silver/2016feb/balancing)
 * Create time: Tue 14 Jan 2020 @ 19:29 (PST)
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
    int x, y;
    scanf("%d%d", &y, &x);
    pos.push_back(make_pair(y, x));
  }

  if (N <= 2)
  {
    printf("1\n");
    return 0;
  }

  stable_sort(pos.begin(), pos.end());

  int ret = INT32_MAX;
  for (auto divy : pos)
  {
    int top_left=0, bot_left=0, top=0, bot=0;
    
    map<int, int> above; // map<x_coord, count_of_cows_with_that_x_coord>
    map<int, int> below;
    for (ca p : pos) // count the number of cows above and below the horizontal fence
    {
      if (p.second > divy.second +1)
      {
        ++bot;
        if (below.count(p.first)) ++below[p.first];
        else below[p.first] = 1;
      }
      else
      {
        ++top;
        if (above.count(p.first)) ++above[p.first];
        else above[p.first] = 1;
      }
    }
    for (ca p : pos)
    {
      if (above.count(p.first)) top_left += above[p.first];
      if (below.count(p.first)) bot_left += below[p.first];
      ret = min(ret, max(max(top_left, top-top_left), max(bot_left, bot-bot_left)));
    }
  }

  printf("%d\n", ret);

  return 0;
}
