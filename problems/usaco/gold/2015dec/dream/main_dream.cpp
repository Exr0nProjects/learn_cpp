/*
TASK: dream
LANG: C++14
*/

/*
 * Problem dream (usaco/gold/2015dec/dream)
 * Create time: Thu 26 Mar 2020 @ 16:36 (PDT)
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
#include <array>
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
#include <iterator>
#include <exception>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define g(t, i) get<i>(t)
#define mt make_tuple

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

void setIO(const std::string &name = "dream");

using namespace std;
const int MX = 1011;
const int Dy[] = {0, 1, 0, -1};
const int Dx[] = {1, 0, -1, 0};
int N, M, maze[MX][MX];

typedef pair<pair<int, bool>, pair<int, int> > State; // <<dist, orange smelling>, <y, x>>
set<State> ps; // priority set
set<pair<bool, pair<int, int> > > vis; // state without the dist
// map<pair<int, int>, int> maze;

State move(State state, int dir)
{
    int dy = state.S.F + Dy[dir];
    int dx = state.S.S + Dx[dir];

    if (maze[dy][dx] == 0) return state; // cannot pass
    else if (maze[dy][dx] == 3 && !state.F.S) return state; // doesn't smell like oranges

    state.S.F = dy;
    state.S.S = dx;
    ++state.F.F;

    if (maze[dy][dx] == 2)
        state.F.S = 1;

    if (maze[dy][dx] == 4)
    {
        state.F.S = 0;
        return move(state, dir);
    }
    else
        return state;
}

int main()
{
    setIO();
    scanf("%d%d", &N, &M);
    FOR_(n, 1, N+1)
    {
        FOR_(m, 1, M+1)
        {
            scanf("%d", &maze[n][m]);
        }
    }

    // BFS
    ps.clear();
    ps.insert(mp(mp(0, 0), mp(1, 1)));
    while (!ps.empty())
    {
        State cur = *ps.begin();
        ps.erase(ps.begin());
        vis.insert(mp(cur.F.S, cur.S));

        if (cur.S.F == N && cur.S.S == N)
        {
            printf("%d\n", cur.F.F);
            break;
        }

        FOR(i, 4)
        {
            State nxt = move(cur, i);
            if (nxt != cur && !vis.count(mp(nxt.F.S, nxt.S)))
                ps.insert(nxt);
        }
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
