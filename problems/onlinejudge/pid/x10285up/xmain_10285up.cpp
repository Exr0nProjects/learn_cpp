/*
TASK: 10285up
LANG: C++14
*/

/*
 * Problem 10285up (onlinejudge/pid/10285up)
 * Create time: Fri 13 Mar 2020 @ 10:28 (PDT)
 * Accept time: Fri 13 Mar 2020 @ 10:38 (PDT)
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

void setIO(const std::string &name = "10285up");

using namespace std;
const int MX = 111;
char name[MX];
int R, C, maze[MX][MX], tab[MX][MX];

int main()
{
    setIO();
    int kase;
    scanf("%d", &kase);
    FOR(ks, kase)
    {
        FOR(i, MX) FOR(j, MX) tab[i][j] = 0;
        scanf("%s%d%d", name, &R, &C);
        vector<pair<int, pii> > order;
        FOR(r, R) FOR(c, C)
        {
            scanf("%d", &maze[r][c]);
            order.EB(maze[r][c], MP(r, c));
        }
        sort(order.begin(), order.end());

        // TRAV(p, order) printf("h %d: (%d %d)\n", p.F, p.S.F, p.S.S);

        int ret=0;
        TRAV(p, order)
        {
            const int dy[] = {0, 1, 0, -1};
            const int dx[] = {1, 0, -1, 0};
            FOR(d, 4)
            {
                int y = p.S.F + dy[d];
                int x = p.S.S + dx[d];
                if (y < 0 || y >= R || x < 0 || x >= C) continue;
                if (maze[y][x] < p.F)
                    tab[p.S.F][p.S.S] = max(tab[p.S.F][p.S.S], tab[y][x] +1);
            }
            ret = max(ret, tab[p.S.F][p.S.S]);
        }
        printf("%s: %d\n", name, ret+1);
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
