/*
ID: spoytie2
TASK: badmilk
LANG: C++14
*/

/*
 * Problem badmilk (usaco/bronze/2015dec/badmilk)
 * Created Sat 28 Dec 2019 @ 08:37 (PST)
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
FILE *fin = fopen("badmilk.in", "r");
FILE *fout = nullptr;

const int MAXSZ = 100; // todo
set<int> drinkers[MAXSZ + 10];
vector<pair<int, int>> drank[MAXSZ + 10];
int sicktime[MAXSZ + 10];
int possible[MAXSZ + 10];
ll N, M, D, S, ret = 0;

int main()
{
  if (fin)
  {
    fout = fopen("badmilk.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }
  fscanf(fin, "%lld%lld%lld%lld", &N, &M, &D, &S);

  for (int i = 0; i <= N; ++i)
    drank[i].push_back(pair<int, int>{-10, 0}); // 1-index all of the vectors
  for (int i = 0; i < D; ++i)
  {
    int p, m, t;
    fscanf(fin, "%d%d%d", &p, &m, &t);
    drank[p].push_back(make_pair(t, m));
    drinkers[m].insert(p);
  }

  for (int i = 0; i < S; ++i)
  {
    int p, t;
    fscanf(fin, "%d%d", &p, &t);
    sicktime[p] = t;
  }

  // count the number of people who got sick after drinking each milk
  for (int i = 1; i <= N; ++i)
  {
    sort(drank[i].begin(), drank[i].end());

    /*/d*/ printf("person %d:\n", i);
    for (int j = 1; j < drank[i].size(); ++j)
    {
      const auto &v = drank[i][j];
      if (v.first >= sicktime[i])
        break;
      ++possible[v.second]; // counts the number of people who were sick after drinking
      /*/d*/ printf("  %3d: %3d", v.first, v.second);
    }
    /*/d*/ printf("\n");
  }

  // figure out if each milk was possibly the culprit, and if so max for ans
  for (int i = 1; i <= M; ++i)
  {
    if (possible[i] >= S) // shouldn't ever be greater...
    {
      // could be culprit
      ret = max(ret, (ll)drinkers[i].size());
    }
  }
  fprintf(fout, "%lld\n", ret);

  return 0;
}
