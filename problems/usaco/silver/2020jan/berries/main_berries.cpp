/*
ID: spoytie2
TASK: berries
LANG: C++14
*/

/*
 * Problem berries (usaco/silver/2020jan/berries)
 * Create time: Sun 19 Jan 2020 @ 09:46 (PST)
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

void setIO(const std::string &name = "berries");

typedef struct
{
  int f, t, w, n;
} Edge;
#define TRAVE(s, e) for (int e = head[s]; e; e = edges[e].n)

const int MX = 1010;
//#define __USING_EDGELIST
//void addEdge(cn a, cn b, cn w=1);
//Edge edges[MX*MX];
//int ect=1, head[MX];

using namespace std;
int N, K, tree_max = 0;
int trees[MX];

int main()
{
  setIO();
  scanf("%d%d", &N, &K);
    for (int i=0; i<N; ++i)
  {
    scanf("%d", &trees[i]);
    tree_max = max(tree_max, trees[i]);
  }

  int ret = 0;
    for (int b=1; b<tree_max+1; ++b)
  {
    int full = 0;
    for (int i=0; i<N; ++i) full += trees[i] / b;
    if (full < K / 2)
      break; // b isn't the least amount of berries in a bucket that elsie gets
    if (full >= K)
    {
      ret = max(ret, K / 2 * b);
      continue;
    }

    //printf("  only filled %d buckets each with %d berries, now filling rest with remaining...\n", full, b);
    // not all buckets filled evenly with b berries
    sort(trees, trees + N, [&](cn l, cn r) { return l % b < r % b; });
    int sum = (full - (K / 2)) * b;
    for (int i=0; i<K+full; ++i)
    {
      sum += trees[i] % b; // fill each bucket with the biggest remaining tree
    }
    ret = max(ret, sum);
  }

  printf("%d\n", ret);

  return 0;
}

/*
 1 2
 2
 => 1

 2 2
 5 10
 => 5

 3 4
 6 4 4
 => 6
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

#ifdef __USING_EDGELIST
void addEdge(cn a, cn b, cn w)
{
  edges[ect].f = a;
  edges[ect].t = b;
  edges[ect].w = w;
  edges[ect].n = head[a];
  head[a] = ect++;
}
#endif

/*
Benjamin Qi
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
*/

/*
thecodingwizard

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())

#define INF 1000000000
#define LL_INF 4500000000000000000
#define LSOne(S) (S & (-S))
#define EPS 1e-9
#define A first
#define B second
#define mp make_pair
#define pb push_back
#define PI acos(-1.0)
#define ll long long
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
*/
