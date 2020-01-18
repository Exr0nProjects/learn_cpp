/*
ID: spoytie2
TASK: maxcross
LANG: C++14
*/

/*
 * Problem maxcross (usaco/silver/2017feb/maxcross)
 * Create time: Sat 18 Jan 2020 @ 10:48 (PST)
 * Accept time: Sat 18 Jan 2020 @ 10:55 (PST)
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
#define ii pair<int, int>
#define vii vector<ii>

#define MP make_pair
#define PB push_back
#define F first
#define B second
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

void setIO(const std::string &name = "maxcross");

typedef struct
{
  int f, t, w, n;
} Edge;
#define TRAVE(s, e) for (int e = head[s]; e; e = edges[e].n)

const int MX = 100010;
//#define __USING_EDGELIST
//void addEdge(cn a, cn b, cn w=1);
//Edge edges[MX*MX];
//int ect=1, head[MX];

using namespace std;
int mem[MX];
int N, K, B;

int main()
{
  setIO();
  scanf("%d%d%d", &N, &K, &B);
  FOR(i, B)
  {
    int d;
    scanf("%d", &d);
    mem[d] = -1;
  }
  FOR(i, N)
  {
    mem[i] += mem[i - 1] + 1; // mem[i] = # of working signals up to i
  }

  int m = 0;
  FOR(i, N)
  {
    if (i + K > N)
      break;
    m = max(m, mem[i + K] - mem[i]); // m is the number of working signals in a reigon of K
  }

  printf("%d\n", K - m);

  return 0;
}

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
