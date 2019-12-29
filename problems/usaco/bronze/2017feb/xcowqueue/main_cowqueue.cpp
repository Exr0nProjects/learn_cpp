/*
ID: spoytie2
TASK: cowqueue
LANG: C++14
*/

/*
 * Problem cowqueue (usaco/bronze/2017feb/cowqueue)
 * Created Sun 29 Dec 2019 @ 14:27 (PST)
 * Accepted [!meta:end!]
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
FILE *fin = fopen("cowqueue.in", "r");
FILE *_ = stderr;

const int MAXSZ = 110; // todo
int N;
vector<pair<int, int> > cows;


int main ()
{
  if (fin) { stdin = fin; stdout = fopen("cowqueue.out", "w+"); }
  scanf("%d", &N);
  for (int i=0; i<N; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    cows.push_back(make_pair(a, b));
  }

  const auto cmp = [](const pair<int, int> &l, const pair<int, int> &r) {return l.first < r.first;};
  stable_sort(cows.begin(), cows.end(), cmp);

  int end = 0;
  for (ca c : cows)
  {
    fprintf(_, "  %3d, %3d\n", c.first, c.second);
    if (c.first >= end) end = c.first + c.second;
    else if (c.first < end) end += c.second;
  }
  
  printf("%d\n", end);

  return 0;
}

