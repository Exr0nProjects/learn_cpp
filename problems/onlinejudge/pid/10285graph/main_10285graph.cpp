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

void setIO(const std::string &name = "10285graph");

using namespace std;
const int MX = 111;
char name[MX];
int R, C, maze[MX][MX], dist[MX][MX];
list<pair<pii, pii> > edges;

int main()
{
    // setIO();
    int kase;
    scanf("%d", &kase);
    FOR(ks, kase)
    {
        // FOR(i, MX) FOR(j, MX) dist[i][j] = (1<<30) * (i != j);
        FOR(i, MX) FOR(j, MX) dist[i][j] = 0;
        scanf("%s%d%d", name, &R, &C);
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
                    printf("(%d %d) -> (%d %d)\n", r, c, y, x);
                    edges.EB(MP(r, c), MP(y, x));
                }
            }
        }
        FOR(i, R*C)
        {
            TRAV(e, edges)
            {
                dist[e.S.F][e.S.S] = max(dist[e.S.F][e.S.S], dist[e.F.F][e.F.S] + 1);
            }
        printf("\n"); FOR(r, R) { FOR(c, C) printf("%3d", dist[r][c]); printf("\n"); }
        }

        FOR(r, R) { FOR(c, C) printf("%3d", dist[r][c]); printf("\n"); }

        int ret=0;
        FOR(r, R) FOR(c, C) ret = max(ret, dist[r][c]);
        printf("%s: %d\n", name, ret);
    }

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
