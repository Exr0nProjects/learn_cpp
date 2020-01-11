/*
ID: spoytie2
TASK: angry
LANG: C++14
*/

/*
 * Problem angry (usaco/silver/2016jan/angry)
 * Create time: Sat 11 Jan 2020 @ 08:43 (PST)
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
FILE *fin = fopen("angry.in", "r");
FILE *_ = stderr;

const int MAXSZ = 50010; // todo
int N, K;
int pos[MAXSZ];

int recurse(cn s, vector<int> &div)
{
  if (K == 1)
  {
    int mx = 0;
    div.push_back(N);
    fprintf(_, "split:\n");
    for (ca i : div)
      fprintf(_, "%3d", i);
    fprintf(_, "\n");
    for (int i = 1; i < div.size(); ++i)
    { // ! Doesn't work, because sections don't have to be contiguous. Obviously.
      fprintf(_, "    dist: %d\n", pos[div[i]] - pos[div[i - 1]]);
      mx = max(mx, ((pos[div[i]] - pos[div[i - 1]]) + 1) / 2);
    }
    return mx;
  }
  int mn = INT_MAX / 2;
  for (int i = s + 1; i <= N; ++i)
  {
    div.push_back(i);
    --K;
    mn = min(mn, recurse(i, div));
    ++K;
    div.pop_back();
  }
  return mn;
}

int main()
{
  if (fin)
  {
    stdin = fin;
    stdout = fopen("angry.out", "w+");
  }
  scanf("%d%d", &N, &K);
  for (int i = 1; i <= N; ++i)
  {
    scanf("%d", &pos[i]);
  }

  stable_sort(pos + 1, pos + N + 1);
  for (int i = 0; i <= N; ++i)
    fprintf(_, "%3d", pos[i]);
  fprintf(_, "\n");

  vector<int> vec{1};

  printf("%d\n", recurse(1, vec));

  return 0;
}

/*
 1 1
 4
 => 0
 
 2 1
 4 5
 => 1
 
 3 2
 5
 4
 8
 => 1
 */
