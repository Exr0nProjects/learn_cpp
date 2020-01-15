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
//    fprintf(_, "divy @ %d\n", divy.second+1);
    int top=0, bot=0;
    
    vector<int> above; // map<x_coord, count_of_cows_with_that_x_coord>
    vector<int> below;
    for (ca p : pos) // count the number of cows above and below the horizontal fence
    {
      if (p.second > divy.second +1)
      {
        ++bot;
        below.push_back(p.first);
      }
      else
      {
        ++top;
        above.push_back(p.first);
      }
    }
    int below_idx=0, above_idx=0;
    for (; below_idx < below.size() || above_idx < above.size();)
    {
      int border = INT32_MAX;
      if (below_idx < below.size()) // can increment below
        border = min(border, below[below_idx]); // move to the next one
      if (above_idx < above.size()) // can increment in above
        border = min(border, above[above_idx]); // move to the next one (minned with above so its the next over the entire data not just below the yborder)
      // increment along each list to count the cows that are now on the left of the xborder
      for (; below_idx < below.size() && below[below_idx] == border; ++below_idx);
      for (; above_idx < above.size() && above[above_idx] == border; ++above_idx);
      // min answer with this division with all others
      ret = min(ret, max(max(above_idx, top-above_idx), max(below_idx, bot-below_idx)));
    }
  }

  printf("%d\n", ret);

  return 0;
}
