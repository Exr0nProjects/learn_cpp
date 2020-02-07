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
using namespace std;

int main()
{
  while (true)
  {
    set<int> nodes;
    vector<int> u;
    vector<int> v;

    // input
    while (true)
    {
      char a;
      scanf("%c:", &a);
      if (a == '#')
        return 0;
      a -= 'A';
      nodes.insert(a);

      char b = 0;
      while (true)
      {
        scanf("%c", &b);
        if (b == ';' || b == '\n')
          break;
        b -= 'A';

        nodes.insert(b);
        u.emplace_back(a);
        v.emplace_back(b);
      }
      if (b == '\n')
        break; // end of this graph
    }

    vector<int> ret;
    vector<int> ordering(nodes.size()); // ordering[i] is the position of i in the ordering
    iota(ordering.begin(), ordering.end(), 0);

    printf("  edges:\n");
    FOR(i, u.size())
    {
      printf("  %d - %d\n", u[i], v[i]);
    }

    int lowest = INF;
    do
    {
      printf("  ");
      TRAV(i, ordering)
      printf("%d ", i);
      printf("\n");
      int bandwidth = 0;
      for (int e = 0; e < u.size(); ++e)
      {
        printf("    e = %d\n", e);
        bandwidth = max(bandwidth, abs(ordering[u[e]] - ordering[v[e]]));
      }
      printf("    bandwidth: %d\n", bandwidth);
      if (bandwidth < lowest)
      {
        lowest = bandwidth;
        ret = ordering;
      }
    } while (next_permutation(ordering.begin(), ordering.end()));

    TRAV(n, nodes)
    {
      printf("%c ", n + 'A');
    }
    printf("-> %d\ndone\n", lowest);
  }

  return 0;
}

/*
 // TODO: Doesn't work
 A:B
 B:C
 #
 -> A B -> 1
 -> B C -> 1
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
