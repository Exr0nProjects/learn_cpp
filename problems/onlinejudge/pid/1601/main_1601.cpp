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
const int MX = 16;    
const int MX_CELLS = 200;         // 3/4 * grid size
const int dx = {0, 1, 0, -1, 0}; // four directions + noop
const int dy = {1, 0, -1, 0, 0};
int W, H, N;

// cell: empty positions on the input board
typedef cell int; // ! one indexed
int x[MX_CELLS], y[MX_CELLS]; // map cell_id to <w, h>
cell maze[MX][MX]; // map <w, h> to cell_id
cell start[3], dest[3], cell_id=0; // starting and dest cells of each ghost
void setup()
{
  scanf("%d%d%d", &W, &H, &N);
  FOR(h, H)
  {
    scanf("\n");
    FOR(w, W)
    {
      char c;
      scanf("%c", &c);
      if (c != '#')
      {
        ++cell_id;
        x[cell_id] = w;
        y[cell_id] = h;
        maze[w][h] = cell_id;
        if (isLower(c)) s[c-'a'] = cell_id;
        if (isUpper(c)) s[c-'A'] = cell_id;
      }
    }
  }
}

// state: combo of the locations of three ghosts
// typedef state int;
struct state
{
  cell a, b, c;
  state(){};
  state(cell a, cell b, cell c) : a(a), b(b), c(c) {}
  state(const state &src, cn da, cn db, cn dc)
  {
    a = maze[x[src.a]+dx[da]][y[src.a]+dy[da]];
    b = maze[x[src.b]+dx[db]][y[src.b]+dy[db]];
    c = maze[x[src.c]+dx[dc]][y[src.c]+dy[dc]];
  }
};

vector<state> neighbors(state src)
{
  auto illegalPos = [](cell c) { return c == 0; };
  auto illegalMove = [](cell a0, cell a1, cell b0, cell b1) {
    return a1 == b1 || (a0 == b1 && b0 == a1);
  };
  vector<state> ret;
  FOR(da, 5)
  FOR(db, 5) FOR(dc, 5)
  {
    state next(src, da, db, dc);
    // in a wall
    if (illegalPos(next.ax, next.ay) || illegalPos(next.bx, next.by) || illegalPos(next.cx, next.cy))
      continue;
    if (illegalMove(src.a next.a, src.b, next.b)
     || illegalMove(src.b, next.b, src.c, next.c)
     || illegalMove(src.c, next.c, src.a, next.a))
      continue;
    ret.push_back(next);
  }
  return ret;
}

inline bool win(state s)
{
  return s.a == dest[0] && s.b == dest[1] && s.c == dest[2];
}

int bfs(state start)
{
  static queue<state> q;
  static map<state, int> dist;
  dist[start] = 0;
  for (q.push(start); !q.empty(); q.pop())
  {
    if (win(q.front()))
      return dist[q.front()];

    TRAV(n, neighbors(q.front()))
    {
      if (dist.count(q.front())) continue; // dejavu: already been here before
      dist[n] = dist[q.front()]+1;
      q.push(n);
    }
  }
  return -1;
}

int main()
{
  setIO();
  setup();

  // put additional ghosts in the corner to fill all three
  if (N <= 1)
  {
    ++cell_id;
    maze[0][0] = cell_id;
    x[cell_id] = y[cell_id] = 0;
    start[2] = dest[2] = cell_id;
  }
  if (N <= 2)
  {
    ++cell_id;
    maze[W-1][0] = cell_id;
    x[cell_id] = W-1;
    y[cell_id] = 0;
    start[2] = dest[2] = cell_id;
  }

  // go!
  state start(s[0], s[1], s[2]);
  printf("%d\n", bfs(start));

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
