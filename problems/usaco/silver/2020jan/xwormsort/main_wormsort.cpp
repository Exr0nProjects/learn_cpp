/*
ID: spoytie2
TASK: wormsort
LANG: C++14
*/

/*
 * Problem wormsort (usaco/silver/2020jan/wormsort)
 * Create time: Thu 06 Feb 2020 @ 18:59 (PST)
 * Accept time: [!meta:end!]
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

void setIO(const std::string &name = "wormsort");

typedef struct
{
  int f, t, w, n;
} Edge;
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)

const int MX = 100010;
//#define __USING_EDGELIST
//void addEdge(cn a, cn b, cn w=1);
//Edge edges[MX*MX];
//int ect=1, head[MX];

using namespace std;
int N, M;
int pos[MX];
vector<pair<int, pii>> edges;

// disjoint set
int djs_f[MX]; // father
int djs_s[MX]; // size
int find(cn n)
{
  //  printf("finding %d\n", n);
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

// binary search
bool test(cn min_width)
{
  //  printf("min wormhole width: %d\n", min_width);
  FOR(i, N + 5)
  djs_s[i] = 1;
  iota(djs_f, djs_f + N, 0);

  TRAV(p, edges)
  {
    if (p.F >= min_width)
    {
      //      printf("wormhole %d - %d legit with width %d\n", p.S.F, p.S.S, p.F);
      merge(p.S.F, p.S.S);
    }
  }
  //  FOR(i, N) printf("  %d has %d\n", find(i), i); // Works to here

  FOR(i, N)
  {
    //    printf("  does cow %d (at %d) work? %d\n", i, pos[i], find(i) == find(pos[i]));
    if (find(i) != find(pos[i]))
    {
      return false;
    }
  }
  return true;
}

int binarySearch(cn l, cn r) // include l, exclude r
{
  //  printf("binary searching %d - %d (range %d)\n", l, r, (r-l));
  if (l + 1 >= r)
    return l;
  int m = (l + r) / 2;
  if (test(m))
    return binarySearch(m, r);
  else
    return binarySearch(l, m);
}

int main()
{
  setIO();
  scanf("%d%d", &N, &M);
  FOR(i, N)
  {
    scanf("%d", &pos[i]);
    --pos[i]; // shift for zero indexing
  }
  FOR(i, M)
  {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    edges.emplace_back(w, make_pair(a - 1, b - 1));
  }

  int ret = binarySearch(0, 1 << 30);
  if (ret == (1 << 30) - 1)
    ret = -1;
  printf("%d\n", ret);

  return 0;
}
/*
 4 2
 1 2 3 4
 1 2 1
 3 4 2
 => -1
 
 4 2
 1 2 4 3
 1 2 1
 3 4 2
 => 2
 
 4 2
 2 1 4 3
 1 2 1
 3 4 2
 => 1
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
