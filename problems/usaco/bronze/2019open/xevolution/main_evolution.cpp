/*
ID: spoytie2
TASK: evolution
LANG: C++14
*/

/*
 * Problem evolution (usaco/bronze/2019open/evolution)
 * Created Thu 02 Jan 2020 @ 10:10 (PST)
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
FILE *fin = fopen("evolution.in", "r");
FILE *_ = stderr;

const int MAXSZ = -1; // todo
int N;
vector<set<string>> groups;

bool isSuperSet(cn i, cn j)
{ // nlogn*k
  for (ca s : groups[j])
  {
    if (groups[i].find(s) == groups[i].end())
    {
      return false;
    }
  }
  return true;
}

int main()
{
  if (fin)
  {
    freopen("evolution.in", "r", stdin);
    stdout = fopen("evolution.out", "w+");
  }

  cin >> N;
  for (int i = 0; i < N; ++i)
  {
    int t;
    cin >> t;
    if (t == 0)
    {
      --i;
      --N;
      continue;
    }
    groups.push_back(set<string>{});
    for (int j = 0; j < t; ++j)
    {
      string s;
      cin >> s;
      groups[i].insert(s);
    }
  }

  for (int i=0; i<N; ++i)
  {
    int t=0;
    for (int j=0; j<N; ++j)
    {
      if (i == j) continue;
      t += isSuperSet(i, j);
    }
    if (t > 1)
    {
      printf("no\n");
      return 0;
    }
  }
  printf("yes\n");

  return 0;
}
