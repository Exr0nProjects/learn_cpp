/*
ID: spoytie2
TASK: reduce
LANG: C++14
*/

/*
 * Problem reduce (usaco/silver/2016open/reduce)
 * Create time: Fri 07 Feb 2020 @ 18:17 (PST)
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

void setIO(const std::string &name = "reduce");

typedef struct
{
  int f, t, w, n;
} Edge;
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)

const int MX = 50010;
//#define __USING_EDGELIST
//void addEdge(cn a, cn b, cn w=1);
//Edge edges[MX*MX];
//int ect=1, head[MX];

using namespace std;
int N;
priority_queue<ll> top, lef; // using lef and rig because left and right are already taken, and lhs and rhs should be reserved for comparison params
priority_queue<ll, deque<ll>, greater<ll>> bot, rig;
ll x[MX], y[MX], removed[MX];

ll reduce(cn rem)
{
  //  FOR(i, 5-rem) printf("  "); printf("top: %lld bot: %lld lef: %lld rig: %lld\n", top.size(), bot.size(), lef.size(), rig.size());
  if (rem == 0)
  {
    int vert = top.top() - bot.top();
    int horz = lef.top() - rig.top();
    //    printf("          area: %d * %d = %d\n", horz, vert, horz*vert);
    return horz * vert;
  }
  ll best = 1 << 30;
  FOR(i, N)
  {
    if (removed[i])
      continue;
    int does_something = false;
    if (x[i] == bot.top())
    {
      does_something |= 1;
      bot.pop();
    }
    if (x[i] == top.top())
    {
      does_something |= 2;
      top.pop();
    }
    if (y[i] == lef.top())
    {
      does_something |= 4;
      lef.pop();
    }
    if (y[i] == rig.top())
    {
      does_something |= 8;
      rig.pop();
    }
    //    FOR(i, 5-rem) printf("  "); printf("cow %d does something: %d\n", i, does_something);
    if (!does_something)
      continue; // only try if it does something, could be optimized to check that it doesn't pop a repeat
    removed[i] = true;
    best = min(best, reduce(rem - 1));
    removed[i] = false;
    if (does_something & 1)
      bot.push(x[i]);
    if (does_something & 2)
      top.push(x[i]);
    if (does_something & 4)
      lef.push(y[i]); // FIX: These should push y[i] not x[i]
    if (does_something & 8)
      rig.push(y[i]);
  }
  return best;
}

int main()
{
  setIO();
  scanf("%d", &N);
  FOR(i, N)
  {
    scanf("%lld%lld", &x[i], &y[i]);
    top.push(x[i]);
    bot.push(x[i]);
    lef.push(y[i]);
    rig.push(y[i]);
  }

  //  printf("top: %lld\nbot: %lld\nlef: %lld\nrig: %lld\n", top.size(), bot.size(), lef.size(), rig.size());

  printf("%lld\n", reduce(3));

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
