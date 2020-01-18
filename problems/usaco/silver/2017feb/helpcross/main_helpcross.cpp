/*
ID: spoytie2
TASK: helpcross
LANG: C++14
*/

/*
 * Problem helpcross (usaco/silver/2017feb/helpcross)
 * Create time: Sat 18 Jan 2020 @ 11:46 (PST)
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
#define FOR(i, e) FOR_(i, 1, (e) + 1)
#define FORR_(i, b, e) for (int i = (e); i >= (b); --i)
#define FORR(i, e) FORR_(i, 1, e)
#define SORT(a, n) std::sort((a) + 1, (a) + (n) + 1)
#define TRAV(a, x) for (auto &a : x)
#define SORTV(v) std::sort((v).begin() + 1, (v).end())

void setIO(const std::string &name = "helpcross");

typedef struct
{
  int f, t, w, n;
} Edge;
#define TRAVE(s, e) for (int e = head[s]; e; e = edges[e].n)

const int MX = 20010;
//#define __USING_EDGELIST
//void addEdge(cn a, cn b, cn w=1);
//Edge edges[MX*MX];
//int ect=1, head[MX];

using namespace std;
int C, N;
int chicken[MX];
pii cow[MX];

int main()
{
  setIO();
  scanf("%d%d", &C, &N);
  FOR(i, C)
  {
    scanf("%d", &chicken[i]);
  }
  FOR(i, N)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    cow[i] = MP(b, a);
  }
  SORT(chicken, C);
  SORT(cow, N);

  int id = 1, ret = 0;
  FOR(i, N)
  {
    auto &p = cow[i];
    if (id > C)
      break; // no more chickens to check
    for (; chicken[id] < p.S; ++id)
      ; // find a chicken that works
    if (chicken[id] > p.F)
      continue; // no chickens for this cow
    ++ret;
    ++id;
  }

  printf("%d\n", max(0, min(ret, min(N, C))));

  return 0;
}

/*
 1 1
 1
 1 1
 => 1
 
 1 1
 2
 1 1
 => 0
 
 1 1
 1
 1 100
 => 1
 
 1 1
 100
 1 100
 => 1
 
 5 1
 1 1 1 1 1
 1 1
 => 1
 
 1 5
 1
 1 1
 1 1
 1 1
 1 1
 1 1
 => 1
 
 10 10
 0 1 2 3 4 5 6 7 8 9
 0 0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 9 9 10 10
 => 9
 
 2 5
 0 2
 0 3 1 4 2 5 9 12 12 15
 => 2

 2 2
 2 3
 1 3
 2 2
 => 2
 
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
