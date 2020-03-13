/*
TASK: 10285down
LANG: C++14
*/

/*
 * Problem 10285down (onlinejudge/pid/10285down)
 * Create time: Fri 13 Mar 2020 @ 09:55 (PDT)
 * Accept time: Fri 13 Mar 2020 @ 10:27 (PDT)
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

void setIO(const std::string &name = "10285down");

using namespace std;
const int MX = 111;
char name[MX]; // TODO: might not be enough chars
int R, C, maze[MX][MX], mem[MX][MX];

int dp(int r, int c)
{
    // printf("r %d, c %d\n", r, c);
    int &ret = mem[r][c];
    if (ret) return ret;
    if (r < 0 || r >= R || c < 0 || c >= C) return 0;
    const int dy[] = {0, 1, 0, -1};
    const int dx[] = {1, 0, -1, 0};
    FOR(d, 4)
    {
        int y = r + dy[d];
        int x = c + dx[d];
        if (y < 0 || y >= R || x < 0 || x >= C) continue;
        if (maze[y][x] < maze[r][c]) // FIX: lt not le
            ret = max(ret, dp(r + dy[d], c + dx[d])+1);
    }
    return ret; // FIX: must return ret exactly for memoization to work
}

int main()
{
    setIO();
    int kase;
    scanf("%d", &kase);
    FOR(ks, kase)
    {
        FOR(i, MX) FOR(j, MX) mem[i][j] = 0;
        scanf("%s%d%d", name, &R, &C);
        FOR(i, R) FOR(j, C) scanf("%d", &maze[i][j]);
        int ret=0;
        FOR(i, R) FOR(j, C) ret = max(ret, dp(i, j));

        // FOR(i, R) { FOR(j, C) printf("%3d", mem[i][j]); printf("\n"); }

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
