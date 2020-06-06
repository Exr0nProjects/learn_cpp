/*
TASK: 10285graph
LANG: C++14
*/

/*
 * Problem 10285graph (onlinejudge/pid/10285graph)
 * Create time: Fri 13 Mar 2020 @ 10:39 (PDT)
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
#define EXP(p) p.F][p.S

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

using namespace std;
const int MX = 111;
char name[MX];
int R, C, maze[MX][MX], mem[MX][MX];
list<pair<int, int>> edges[MX][MX];

int longest(int i, int j)
{
    int &ret=mem[i][j];
    if (ret) return ret;

    TRAV(p, edges[i][j])
        ret = max(ret, longest(p.F, p.S)+1);

    return ret;
}

int main()
{
    int kase;
    scanf("%d", &kase);
    FOR(ks, kase)
    {
        FOR(i, MX) FOR(j, MX) { mem[i][j] = 0; edges[i][j].clear(); }
        memset(maze, 0, sizeof(maze));
        scanf("%s%d%d", name, &R, &C);
        // edges.clear(); // FIX: clear the edges
        FOR(r, R) FOR(c, C) scanf("%d", &maze[r][c]);

        FOR(r, R) FOR(c, C)
        {
            const int dy[] = {0, 1, 0, -1};
            const int dx[] = {1, 0, -1, 0};
            FOR(d, 4)
            {
                int y = r+dy[d];
                int x = c+dx[d];
                if (y<0 || y>=R || x<0 || x>=C) continue;
                if (maze[y][x] < maze[r][c])
                {
                    edges[r][c].EB(y, x);
                }
            }
        }

        int ret=0;
        FOR(r, R) FOR(c, C)
            ret = max(ret, longest(r, c));

        printf("%s: %d\n", name, ret+1);
    }

    return 0;
}

/* DP doc section 2
int dp(int i) {
    &ans = d[i];
    if (ans > 0) return ans;
    ans = 1;
    for (int j = 1; j <= n; ++j) {
        if (g[i][j]) {
            ans = max(ans, dp(j) +  int 1);
        }
    }
    return ans;
}
*/

