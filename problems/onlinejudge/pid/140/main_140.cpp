/*
ID: spoytie2
TASK: 140
LANG: C++14
*/

/*
 * Problem 140 (onlinejudge/pid/140)
 * Create time: Sun 26 Jan 2020 @ 16:38 (PST)
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

void setIO(const std::string &name = "140");

typedef struct
{
  int f, t, w, n;
} Edge;
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)

const int MX = 10;
#define __USING_EDGELIST
Edge edges[MX * MX];
int ect = 1, head[MX];
void addEdge(cn a, cn b)
{
  edges[ect].f = a;
  edges[ect].t = b;
  edges[ect].n = head[a];
  ++ect;
}

using namespace std;

int main()
{
  while (true)
  {
    set<int> nodes;

    // input
    while (true)
    {
      char a;
      scanf("%c:", &a);
      if (a == '#')
        return 0;
      a -= 'B';
      nodes.insert(a);

      char b = 0;
      while (true)
      {
        scanf("%c", &b);
        if (b == ';' || b == '\n')
          break;
        b -= 'B';

        nodes.insert(b);
        addEdge(a, b);
        addEdge(b, a);
      }
      if (b == '\n')
        break; // end of this graph
    }

    for (int i = 0; i < 100; ++i)
      printf("%3d", edges[i].t);

    FOR(i, nodes.size())
    {
      printf("%d ->", i);
      TRAVE(e, i + 1)
      {
        printf("%3d", edges[e].t);
      }
      printf("\n");
    }

    // actual computation
    vector<int> letters; // ordering[i] is the position of i in the ordering
    vector<int> ret;
    TRAV(n, nodes)
    letters.push_back(n);

    vector<int> ordering(letters.size());
    iota(ordering.begin(), ordering.end(), 0);

    int lowest = INF;
    while (next_permutation(ordering.begin(), ordering.end()))
    {
      int bandwidth = 0;
      for (int j = 0; j < ordering.size(); ++j)
      { // for each node
        //        printf("%d\n", head[j+1]);
        for (int e = head[j + 1]; e; e = edges[e].n)
        { // for each relation
          bandwidth = max(bandwidth, abs(ordering[j] - ordering[edges[e].t]));
          printf("dist between %d and %d = %d\n", j, edges[e].t, abs(ordering[j] - ordering[edges[e].t]));
        }
      }
      if (bandwidth < lowest) // not <= to preserve lexographical ordering
      {
        lowest = bandwidth;
        ret = ordering;
      }
    }

    char out[MX];
    FOR(i, ret.size())
    out[ret[i]] = i + 'B';
    FOR(i, ret.size())
    printf("%c ", out[i]);
    printf("-> %d\n", lowest);
  }

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
