/*
ID: spoytie2
TASK: closing
LANG: C++14
*/

/*
 * Problem closing (usaco/silver/2016open/closing)
 * Create time: Fri 07 Feb 2020 @ 17:09 (PST)
 * Accept time: Fri 07 Feb 2020 @ 18:03 (PST)
 *
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

// for macro overloading, see https://stackoverflow.com/questions/11761703/overloading-macro-on-number-of-arguments
// this set is designed for one indexed collections
#define FOR_(i, b, e) for (int i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (int i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define SORT(a, n) std::sort((a), (a) + (n))
#define TRAV(a, x) for (auto &a : x)
#define SORTV(v) std::sort((v).begin(), (v).end())

void setIO(const std::string &name = "closing");

typedef struct
{
  int f, t, w, n;
} Edge;
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)

const int MX = 3010;
//#define __USING_EDGELIST
//void addEdge(cn a, cn b, cn w=1);
//Edge edges[MX*MX];
//int ect=1, head[MX];

using namespace std;
int N, M;
bool closed[MX];
int u[MX], v[MX];

// disjoint set
int djs_f[MX];
int djs_s[MX];
int find(cn n)
{
  if (djs_f[n] != n)
    djs_f[n] = find(djs_f[n]);
  return djs_f[n];
}
void merge(int a, int b)
{
  a = find(a);
  b = find(b);
  if (djs_s[a] < djs_s[b])
    swap(a, b);
  djs_s[a] += djs_s[b];
  djs_f[b] = a;
}
void djs_debug()
{
  FOR(i, N)
  printf("  %d has %d\n", djs_f[i], i);
  printf("\n");
}

int main()
{
  setIO();
  scanf("%d%d", &N, &M);
  FOR(i, M)
  {
    scanf("%d%d", &u[i], &v[i]);
    --u[i];
    --v[i];
  }
  FOR(i, N)
  {
    FOR(j, N)
    djs_s[j] = 1;
    iota(djs_f, djs_f + N, 0);

    FOR(e, M)
    {
      if (!closed[u[e]] && !closed[v[e]]) // path is usable
      {
        merge(u[e], v[e]);
      }
    }

    //    printf("Step %d: closed=", i);
    //    FOR(j, N) if (closed[j]) printf("%3d", j); printf("\n");
    //    djs_debug();

    int prev = -1;
    FOR(j, N)
    {
      //      printf("  prev=%d\n", prev);
      if (!closed[j])
      {
        //        printf("    found open barn %d!\n", j);
        if (prev < 0)
          prev = find(j);
        if (prev != find(j))
        {
          printf("NO\n");
          prev = -1;
          break;
        }
      }
    }
    if (prev >= 0)
    {
      printf("YES\n");
    }
    int to_close;
    scanf("%d", &to_close);
    closed[to_close - 1] = 1;
  }

  return 0;
}

/*
 2 1
 1 2
 1
 2
 => YES YES
 */

// boilerplate functions
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
