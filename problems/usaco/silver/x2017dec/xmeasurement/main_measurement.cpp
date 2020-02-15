/*
ID: spoytie2
TASK: measurement
LANG: C++14
*/

/*
 * Problem measurement (usaco/silver/2017dec/measurement)
 * Create time: Fri 31 Jan 2020 @ 10:25 (PST)
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

void setIO(const std::string &name = "measurement");

typedef struct
{
  int f, t, w, n;
} Edge;
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)

const int MX = -1;
//#define __USING_EDGELIST
//void addEdge(cn a, cn b, cn w=1);
//Edge edges[MX*MX];
//int ect=1, head[MX];

using namespace std;
int N, G = 5;
//set<int> ret; // FIX: Don't overcount the same day // FIXFIX: actually there is only one measurement per day so this isn't needed
int ret = 0;
map<int, int> id_prod;
map<int, int> prod_count;
// priority_queue<int> prod_pq;

int maxProd()
{
  if (prod_count.size() == 0)
    return G;
  int k = (*prod_count.rbegin()).first;
  if ((*prod_count.rbegin()).second > 0)
    return k;
  prod_count.erase(k);
  return maxProd();
}

bool changeNeeded(cn id, cn amt)
{
  //  printf("modifying %d %+d\n", id, amt);
  //  printf("in map: %d -> %d\n", id, (*id_prod.find(id)).S);
  if (id_prod.find(id) == id_prod.end())
  {
    //    printf("  new cow!\n");
    id_prod[id] = G;
    ++prod_count[G];
  }
  if (amt == 0)
    return false;

  //  bool ret = false;
  //  if (id_prod[id] == maxProd() ||        // from maxProd or
  //      id_prod[id] + amt == (*(prod_count.rbegin()+1)).second)    // to maxProd
  //    ret = true;

  int start = id_prod[id];
  int end = start + amt;
  int best = maxProd();

  --prod_count[start];
  if (prod_count[start] == 0)
    prod_count.erase(start);

  id_prod[id] += amt;
  ++prod_count[end];

  if (start < best)
  {
    return end >= maxProd();
  }
  else if (start == best)
  {
    if (end < maxProd())
      return true;             // got removed from the display
    else if (end >= maxProd()) // still on display
    {
      //      printf("still on display, %d && %d\n", prod_count.find(start) == prod_count.end(), prod_count[end] == 1);
      return !(prod_count.find(start) == prod_count.end() && prod_count[end] == 1); // only change if the display didnt go single to single
    }
  }
  throw 0; // this should never happen
}

void debug()
{
  return;
  vii out;
  TRAV(p, id_prod)
  out.emplace_back(p.S, p.F);
  sort(out.begin(), out.end());
  TRAV(p, out)
  printf("%3d -> %3d\n", p.S, p.F);
}

int main()
{
  setIO();
  scanf("%d%d", &N, &G);
  changeNeeded(-1, 0);

  vector<pair<int, pii>> journal;
  FOR(i, N)
  {
    int day, id, amt;
    scanf("%d%d%d", &day, &id, &amt);
    journal.emplace_back(day, make_pair(id, amt));
  }
  stable_sort(journal.begin(), journal.end());
  TRAV(pp, journal)
  {
    //        printf("%d: %d %+d\n", pp.F, pp.S.F, pp.S.S);
    if (changeNeeded(pp.S.F, pp.S.S))
    {
      //      ret.insert(pp.F);
      //      printf("change needed on day %d!\n", pp.F);
      ++ret;
    }
  }

  debug();
  printf("%d\n", ret);

  return 0;
}

/*
 2 5
 1 1 +1
 2 1 -1
 -> 2
 
 3 5
 1 1 +1
 2 1 -1
 3 1 -1
 -> 3
 
 4 5
 1 1 +1
 2 1 -1
 3 1 -1
 4 1 -1
 -> 3
 
 7 5
 1 1 -5
 2 2 -5
 3 3 -5
 6 4 +2
 4 4 -5
 5 4 +4
 7 4 +1
 -> 5
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
