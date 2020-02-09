/*
ID: spoytie2
TASK: 10474
LANG: C++14
*/

/*
 * Problem 10474 ([!meta:srcpath!])
 * Create time: Sun 09 Feb 2020 @ 14:10 (PST)
 * Accept time: [!meta:end!]
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=835&page=show_problem&problem=1415
 */

#include <iostream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>

#define cn const int
#define ll long long
#define cl const long long
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 0x7FFFFFFF

#define FOR_(i, b, e) for (int i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (int i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define SORT(a, n) std::sort((a), (a) + (n))
#define TRAV(a, x) for (auto &a : x)
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)
#define SORTV(v) std::sort((v).begin(), (v).end())

void setIO(const std::string &name = "10474");

using namespace std;
const int MX = -1;

int main()
{
  setIO();
  for (int kase = 1;; ++kase)
  {
    int N, Q;
    vector<int> marbles;
    scanf("%d%d", &N, &Q);
    if (!N || !Q)
      return 0;
    FOR(i, N)
    {
      int a;
      scanf("%d", &a);
      marbles.emplace_back(a);
    }
    printf("CASE# %d:\n", kase);
    FOR(i, Q)
    {
      int q;
      scanf("%d", &q);

      auto found = lower_bound(marbles.begin(), marbles.end(), q);
      if (found == marbles.end() || *found != q)
      {
        printf("%d not found\n", q);
      }
      else
      {
        printf("%d found at %d\n", q, *found);
      }
      // if (pos[q] > 0)
      // {
      //   printf("%d found at %d\n", q, pos[q]);
      // }
      // else
      // {
      //   printf("%d not found\n", q);
      // }
    }
  }

  return 0;
}

void setIO(const string &name)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); // fast cin/cout
  if (fopen((name + ".in").c_str(), "r") != nullptr)
  {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w+", stdout);
  }
}
