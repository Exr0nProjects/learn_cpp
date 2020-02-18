/*
ID: spoytie2
TASK: shuffle
LANG: C++14
*/

/*
 * Problem shuffle (usaco/silver/2017dec/shuffle)
 * Create time: Fri 31 Jan 2020 @ 11:17 (PST)
 * Accept time: Fri 31 Jan 2020 @ 11:52 (PST)
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

void setIO(const std::string &name = "shuffle");

typedef struct
{
  int f, t, w, n;
} Edge;
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)

const int MX = 100010;
//#define __USING_EDGELIST
//Edge edges[MX*MX];
//int ect=1, head[MX];
//void addEdge(cn a, cn b)
//{
//  edges[ect].f = a;
//  edges[ect].t = b;
//  edges[ect].n = head[a];
//  head[a] = ect;
//  ++ect;
//}

using namespace std;
int N, ret = 0;
int dest[MX];
vector<int> scc_vis(MX);

int findSCC(cn i, cn src, set<int> &prev, cn step = 0)
{
  //  FOR(i, step) printf("  "); printf("at %d by %d\n", i, step);
  if (scc_vis[i])
  {
    if (prev.find(i) != prev.end())
      return step - scc_vis[i];
    else
      return 0; // just a tail that leads to something already accounted for
  };
  scc_vis[i] = step;
  prev.insert(i);
  return findSCC(dest[i], src, prev, step + 1);
}

int main()
{
  setIO();
  scanf("%d", &N);
  FOR_(i, 1, N + 1)
  {
    scanf("%d", &dest[i]);
  }

  FOR_(i, 1, N + 1)
  {
    //    printf("%d -> %d\n", i, dest[i]);

    if (scc_vis[i])
      continue; // not technically needed
    auto empty = set<int>{};
    ret += findSCC(i, i, empty);
    //    printf("ret = %d\n\n", ret);
  }

  printf("%d\n", ret);

  return 0;
}

/*
 
 4
 1 2 3 4
 -> 4
 
 4
 4 3 2 1
 -> 4
 
 4
 2 1 2 2
 -> 2
 
 7
 2 7 4 5 4 7 5
 -> 2
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