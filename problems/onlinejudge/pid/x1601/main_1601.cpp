/*
ID: spoytie2
TASK: 1601
LANG: C++14
*/

/*
 * Problem 1601 ([!meta:srcpath!])
 * Create time: Mon 10 Feb 2020 @ 07:18 (PST)
 * Accept time: [!meta:end!]
 ! Wrong answer
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4476
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
const int MX_CELLS = 200;          // 3/4 * grid size
const int dx[] = {0, 1, 0, -1, 0}; // four directions + noop
const int dy[] = {1, 0, -1, 0, 0};
int W, H, N;

// cell: empty positions on the input board
typedef char cell;                   // ! one indexed
int x[MX_CELLS], y[MX_CELLS];        // map cell_id to <w, h>
cell maze[MX][MX];                   // map <w, h> to cell_id
cell start[3], dest[3], cell_id = 0; // starting and dest cells of each ghost

int dist[MX_CELLS][MX_CELLS][MX_CELLS]; // distance from source

bool setup()
{
    // reset globals
    FOR(i, MX_CELLS)
    x[i] = y[i] = 0;
    FOR(i, MX)
    FOR(j, MX)
    maze[i][j] = 0;
    FOR(i, 3)
    start[i] = dest[i] = 0;
    cell_id = 0;
    FOR(i, MX_CELLS)
    FOR(j, MX_CELLS)
    FOR(k, MX_CELLS)
    dist[i][j][k] = 0;

    // input
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
                if (islower(c))
                    start[c - 'a'] = cell_id;
                if (isupper(c))
                    dest[c - 'A'] = cell_id;
            }
        }
    }
    return W != 0 || H != 0 || N != 0;
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
        a = maze[x[src.a] + dx[da]][y[src.a] + dy[da]];
        b = maze[x[src.b] + dx[db]][y[src.b] + dy[db]];
        c = maze[x[src.c] + dx[dc]][y[src.c] + dy[dc]];
    }
    bool operator<(const state &other) const { return (a << 16 | b << 8 | c) < (other.a << 16 | other.b << 8 | other.c); }
};

vector<state> neighbors(state src)
{
    auto illegalPos = [](cell c) { return c == 0; };
    auto illegalMove = [](cell a0, cell a1, cell b0, cell b1) {
        return a1 == b1 || (a0 == b1 && b0 == a1);
    };
    vector<state> ret;
    FOR(da, 5)
    FOR(db, 5)
    FOR(dc, 5)
    {
        state next(src, da, db, dc);
        // in a wall
        if (illegalPos(next.a) || illegalPos(next.b) || illegalPos(next.c))
            continue;
        if (illegalMove(src.a, next.a, src.b, next.b) || illegalMove(src.b, next.b, src.c, next.c) || illegalMove(src.c, next.c, src.a, next.a))
            continue;
        ret.push_back(next);
    }
    return ret;
}

inline bool win(state s)
{
    //  printf("    win: %d && %d && %d\n", s.a == dest[0], s.b == dest[1], s.c == dest[2]);
    return s.a == dest[0] && s.b == dest[1] && s.c == dest[2];
}

int bfs(state src)
{
    queue<state> q;
    dist[src.a][src.b][src.c] = 1;
    for (q.push(src); !q.empty(); q.pop())
    {
        state c = q.front();
        //        printf("%d...", dist[c.a][c.b][c.c]); FOR(i, dist[c.a][c.b][c.c]) printf(" "); printf("%d %d %d", c.a, c.b, c.c); printf("\n");
        if (win(c))
            return dist[c.a][c.b][c.c] - 1;

        TRAV(n, neighbors(q.front()))
        {
            //      printf(". %d %d %d: %d\n", n.a, n.b, n.c, dist[n]);
            if (dist[n.a][n.b][n.c] > 0)
                continue; // dejavu: already been here before
            dist[n.a][n.b][n.c] = dist[c.a][c.b][c.c] + 1;
            q.push(n);
        }
    }
    return -1;
}

void debug()
{
    return;
    printf("\n######################################\n    ");
    FOR(w, W)
    printf("%3d", w);
    FOR(h, H)
    {
        printf("\n%3d:", h);
        FOR(w, W)
        {
            if (maze[w][h])
                printf("%3d", maze[w][h]);
            else
                printf("  .");
        }
    }
    printf("\nid: ");
    FOR_(i, 1, cell_id + 1)
    printf("%3d", i);
    printf("\nx:  ");
    FOR_(i, 1, cell_id + 1)
    printf("%3d", x[i]);
    printf("\ny:  ");
    FOR_(i, 1, cell_id + 1)
    printf("%3d", y[i]);

    printf("\n");
}

int main()
{
    setIO();
    while (setup())
    {
        // put additional ghosts in the corner to fill all three
        if (N <= 1)
        {
            ++cell_id;
            maze[0][0] = cell_id;
            x[cell_id] = y[cell_id] = 0;
            start[1] = dest[1] = cell_id; // FIX: set the second ghost, not the third
        }
        if (N <= 2)
        {
            ++cell_id;
            maze[W - 1][0] = cell_id;
            x[cell_id] = W - 1;
            y[cell_id] = 0;
            start[2] = dest[2] = cell_id;
        }

        debug();

        // go!
        state src{start[0], start[1], start[2]};

        //          printf("%d %d %d -> %d %d %d\n", start[0], start[1], start[2], dest[0], dest[1], dest[2]);

        //  find neighbors works...
        //  TRAV(s, neighbors(src))
        //  { printf("a %d, b %d, c %d\n", s.a, s.b, s.c); }

        printf("%d\n", bfs(src));
    }

    return 0;
}

/*
 5 5 2
 #####
 #A#B#
 #   #
 #b#a#
 #####
 16 4 3
 ################
 ## ########## ##
 #    ABCcba    #
 ################
 16 16 3
 ################
 ### ##    #   ##
 ##  #  ##   # c#
 #  ## ########b#
 # ##  # #   #  #
 #  # ##   # # ##
 ##  a#  # # #  #
 ### ## #### ## #
 ##   #   #  #  #
 #  ##### # ## ##
 ####   #B# #   #
 ##  C#   #   ###
 #  # # ####### #
 # ######  A##  #
 #        #    ##
 ################
 0 0 0


 5 5 1
 #####
 #A  #
 # # #
 #  a#
 #####
 */

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
