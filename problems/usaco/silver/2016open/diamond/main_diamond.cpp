/*
ID: spoytie2
TASK: diamond
LANG: C++14
*/

/*
 * Problem diamond (usaco/silver/2016open/diamond)
 * Create time: Fri 07 Feb 2020 @ 17:26 (PST)
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

void setIO(const std::string &name = "diamond");

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
ll diamonds[MX];
int N, K;

int main()
{
  setIO();
  scanf("%d%d", &N, &K);
  FOR(i, N)
  {
    scanf("%d", &diamonds[i]);
  }
  sort(diamonds, diamonds + N);
  //  FOR(i, N) printf("%3d", i); printf("\n");
  //  FOR(i, N) printf("%3d", diamonds[i]); printf("\n");

  ll best = 0, best_upper = 0, best_lower = 0;
  FOR(i, N)
  {
    ll lower = lower_bound(diamonds, diamonds + N, diamonds[i] - K) - diamonds;
    if (i - lower > best)
    {
      best = i - lower;
      best_upper = i;
      best_lower = lower;
    }
  }
  //  printf("best = %d (%d..%d)\n", best, best_lower, best_upper);

  ll second_best = 0, second_best_lower = 0, second_best_upper = 0;
  FOR(i, N)
  {
    if (best_lower <= i && i <= best_upper)
      continue; // ignore upper in preivous range
    ll lower = lower_bound(diamonds, diamonds + N, diamonds[i] - K) - diamonds;
    if (best_lower <= lower && lower <= best_upper)
      lower = best_upper + 1; // ignore lower in prev range
    if (i - lower > second_best)
    {
      second_best = i - lower;
      second_best_upper = i;
      second_best_lower = lower;
    }
  }

  //  printf("second best = %d (%d..%d)\n", second_best, second_best_lower, second_best_upper);

  printf("%d\n", min(best + second_best + 2, (long long)N)); // incase all diamonds are held in one case, then the +2 should just be +1

  return 0;
}

/*
 5 1
 3 3 3 3 3
 => 5
 
 6 1
 1 2 3 4 5 6
 => 4
 
 6 1
 1 1 2 2 3 3
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
