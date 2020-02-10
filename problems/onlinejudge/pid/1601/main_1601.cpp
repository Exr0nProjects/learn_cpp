/*
ID: spoytie2
TASK: 1601
LANG: C++14
*/

/*
 * Problem 1601 ([!meta:srcpath!])
 * Create time: Mon 10 Feb 2020 @ 07:18 (PST)
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

#define FOR_(i, b, e) for (int i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (int i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define SORT(a, n) std::sort((a), (a) + (n))
#define TRAV(a, x) for (auto &a : x)
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)
#define SORTV(v) std::sort((v).begin(), (v).end())

void setIO(const std::string &name = "1601");

using namespace std;
const int MX = 16;               // 3/4 * grid size
const int dx = {0, 1, 0, -1, 0}; // four directions + noop
const int dy = {1, 0, -1, 0, 0};

int maze[MX][MX];

// typedef state int;
struct state
{
  int ax, ay, bx, by, cx, cy;
  state(){};
  state(cn a, cn b, cn c, cn d, cn e, cn f) : ax(a), ay(b), bx(c), by(d), cx(e), cy(f) {}
  state(const state &src, cn da, cn db, cn dc)
  {
    ax = src.ax + dx[da];
    ay = src.ay + dy[da];
    bx = src.bx + dx[db];
    by = src.by + dy[db];
    cx = src.cx + dx[dc];
    cy = src.cy + dy[dc];
  }
} win_condition;

vector<state> neighbors(state src, vector<state> &ret)
{
  auto illegalPos = [](cn x, cn y) { return maze[x][y] == -1; };
  auto illegalMove = [](cn ax0, cn ay0, cn bx0, cn by0, cn ax1, cn ay1, cn bx1, cn by1) {
    return (ax1 == bx1 && ay1 == by1) ||
           ((ax0 == bx1 && ay0 == by1) || (ax1 == bx0 && ay1 == by1));
  };
  FOR(da, 5)
  FOR(db, 5) FOR(dc, 5)
  {
    state next(src, da, db, dc);
    // in a wall
    if (illegalPos(next.ax, next.ay) || illegalPos(next.bx, next.by) || illegalPos(next.cx, next.cy))
      continue;
    if (illegalMove(src.ax, src.ay, src.bx, src.by, next.ax, next.ay, next.bx, next.by) ||)
  }
  return ret;
}

inline bool win(state s)
{
  return s == win_condition;
}

int bfs(state start)
{
  static queue<state> q;
  for (q.push(start); !q.empty(); q.pop())
  {
    if (win(q.front()))
      return dist[q.front()];

    TRAV(n, neighbors(q.front()))
    {
      q.push(n);
    }
  }
  return -1;
}

int main()
{
  setIO();

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
