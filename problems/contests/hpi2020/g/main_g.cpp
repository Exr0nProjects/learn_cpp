/*
TASK: g
LANG: C++14
*/

/*
 * Problem g (contests/hpi2020/g)
 * Create time: Sat 07 Mar 2020 @ 08:45 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
#include <list>
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

#define ll long long
#define dl double
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define MP make_pair
#define PB push_back
#define EB emplace_back
#define F first
#define S second

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

void setIO(const std::string &name = "g");

using namespace std;
const int MX = 1111;
int M, N, K;
pii src, dst;
vector<pii> moves;
int maze[MX][MX];

int main()
{
    setIO();
    scanf("%d%d%d", &M, &N, &K);
    FOR(i, MX) FOR(j, MX) maze[i][j] = -1;
    FOR_(m, 1, M+1)
    {
        scanf("\n");
        FOR_(n, 1, N+1)
        {
            char c;
            scanf("%c", &c);
            if (c == 'X') maze[m][n] = -1;
            if (c == '.') maze[m][n] = 0;
            if (c == 'A') { src.F = m; src.S = n; }
            if (c == 'B') { dst.F = m; dst.S = n; }
        }
    }
    FOR(k, K)
    {
        int dx, dy;
        scanf("%d%d", &dx, &dy);
        dy *= -1;
        moves.EB(dy, dx);
    }
    printf("M=%d , N=%d, K=%d\n", M, N, K);
    FOR(i, M+2) { FOR(j, N+2) printf("%3d", maze[i][j]); printf("\n"); }
    printf("%d moves: ", K); TRAV(m, moves) printf("(%d %d) ", m.F, m.S);

    maze[1][1] = 1;
    queue<pii> bfs;
    for (bfs.push(src); !bfs.empty(); bfs.pop())
    {
        pii front=bfs.front();
        TRAV(move, moves)
        {
            int dy = front.F+move.F;
            int dx = front.S+move.S;
            if (dy < 0 || dy > MX || dx < 0 || dx > MX) continue;
            FOR(i, maze[dy][dx]) printf("    "); printf("going to %d %d\n", dy, dx);
            if (maze[dy][dx]) continue;
            if (front.F == dst.F && front.S == dst.S)
            {
                printf("YES\n%d\n", maze[front.F][front.S]);
                return 0;
            }
            maze[dy][dx] = maze[front.F][front.S] + 1;
            bfs.emplace(dy, dx);
        }
    }

    ll min_dist=1<<20, min_steps=1<<20;
    FOR(m, M) FOR(n, N)
    {
        int dist = abs(m-dst.F) + abs(n - dst.S);
        if (dist <= min_dist)
        {
            min_steps = min(min_steps, (ll)maze[m][n]);
        }
    }

    printf("NO\n%d%d\n", min_dist, min_steps);

    return 0;
}
/*
5 5 3
.X.A.
....X
.B.X.
...X.
X...X
-1 0
0 -1
1 2
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
