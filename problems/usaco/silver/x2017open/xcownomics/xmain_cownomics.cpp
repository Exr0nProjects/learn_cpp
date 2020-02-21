/*
ID: spoytie2
TASK: cownomics
LANG: C++14
*/

/*
 * Problem cownomics ([!meta:srcpath!])
 * Create time: Sat 08 Feb 2020 @ 10:00 (PST)
 * Accept time: Sat 08 Feb 2020 @ 10:14 (PST)
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

#define FOR_(i, b, e) for (int i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (int i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define SORT(a, n) std::sort((a), (a) + (n))
#define TRAV(a, x) for (auto &a : x)
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)
#define SORTV(v) std::sort((v).begin(), (v).end())

void setIO(const std::string &name = "cownomics");

using namespace std;
const int MX = 6000;
const int MXLEN = 600;
int N, M;
char genome[MX][MXLEN];

int main()
{
  setIO();
  scanf("%d%d", &N, &M);
  FOR(i, N)
  {
    scanf("%s", genome[i]);
  }
  FOR(i, N)
  {
    scanf("%s", genome[i + N]);
  }

  int ret = 0;
  FOR(a, M)
  {
    FOR_(b, a + 1, M)
    {
      FOR_(c, b + 1, M)
      {
        set<pair<char, pair<char, char>>> seq;
        FOR(i, N)
        {
          seq.emplace(genome[i][a], MP(genome[i][b], genome[i][c]));
        }
        bool legit = true;
        FOR(i, N)
        {
          if (seq.count(MP(genome[N + i][a], MP(genome[N + i][b], genome[N + i][c]))))
          {
            legit = false;
            break;
          }
        }
        if (!legit)
          continue;
        ++ret;
      }
    }
  }

  printf("%d\n", ret);

  return 0;
}

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
