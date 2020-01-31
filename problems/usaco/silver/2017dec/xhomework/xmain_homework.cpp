/*
ID: spoytie2
TASK: homework
LANG: C++14
*/

/*
 * Problem homework (usaco/silver/2017dec/homework)
 * Create time: Fri 31 Jan 2020 @ 09:53 (PST)
 * Accept time: Fri 31 Jan 2020 @ 10:14 (PST)
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

void setIO(const std::string &name = "homework");

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
int N;
int scores[MX];
int mn = INF, min_by[MX];
int sum = 0;

int main()
{
  setIO();
  scanf("%d", &N);
  FOR(i, N)
  {
    scanf("%d", &scores[i]);
    sum += scores[i];
  }

  FORR(i, N)
  {
    mn = min(mn, scores[i]);
    min_by[i] = mn;
  }
  //  FOR(i, N) printf("%3d", min_by[i]);

  //  printf("sum = %d\n", sum);

  set<int> sol;
  double best = 0;
  const double FLOAT_TOLERANCE = 0.0000001;
  FOR(i, N - 1)
  {
    double avg = (double)(sum - min_by[i]) / (double)(N - i - 1); // -1 because we remove the lowest scoring
    if (avg - best > FLOAT_TOLERANCE)
    {
      best = avg;
      sol = {};
    }
    if (abs(avg - best) < FLOAT_TOLERANCE && i > 0)
      sol.insert(i);
    //    printf("pos %d: avg = %d\n", i, avg);
    sum -= scores[i]; // eat a problem
  }

  TRAV(i, sol)
  printf("%d\n", i);

  return 0;
}

/*
3
1 1 3
-> 1

4
1 3 3 3
-> 1 2

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
