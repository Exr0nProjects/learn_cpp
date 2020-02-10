/*
ID: spoytie2
TASK: [!meta:pid!]
LANG: C++14
*/

/*
 * Problem meetings usaco/silver/2019dec/meetings
 * Create time: Fri 07 Feb 2020 @ 19:50 (PST)
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

void setIO(const std::string &name = "meetings");

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
int N, L;
vector<pair<int, pii>> cows;
vi left_going, right_going;
vii endings; // <time, weight>

void input()
{
  scanf("%d%d", &N, &L);
  FOR(i, N)
  {
    int w, x, d;
    scanf("%d%d%d", &w, &x, &d);
    cows.emplace_back(x, MP(w, d));
  }
  sort(cows.begin(), cows.end());
}

int getTime()
{
  int total_weight = 0;
  TRAV(p, cows)
  {
    if (p.S.S == -1)
    {
      left_going.emplace_back(p.F);
    }
    else
    {
      right_going.emplace_back(p.F);
    }
    total_weight += p.S.F;
  }
  
  FOR(i, left_going.size()) endings.emplace_back(left_going[i], cows[i].S.F); // first z weights
  FOR(i, right_going.size()) endings.emplace_back(L-right_going[i], cows[i+left_going.size()].S.F); // other weights (sorted by reverse time taken)

  sort(endings.begin(), endings.end());

  int i=endings.size()-1;
  for (int done = total_weight; done > total_weight/2; --i)
  {
    done -= endings[i].S;
  }
  return endings[i].F;
}

int countCollisions(cn t)
{
  int count = 0;
  FOR(r, right_going.size())
  {
    FOR(l, left_going.size())
    {
//      printf("right: %d, left: %d\n", right_going[r], left_going[l]);
      if (left_going[l] > right_going[r] && left_going[l] - t <= right_going[r] + t)
      {
        ++count;
      }
    }
  }
  return count;
}

int main()
{
  setIO();
  input();
  TRAV(p, cows)
  {
//    printf("cow at %d with %d going %d\n", p.F, p.S.F, p.S.S);
  }
  int t = getTime();
  int n = countCollisions(t);

  printf("%d\n", n);

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
