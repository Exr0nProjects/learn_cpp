/*
ID: spoytie2
TASK: 1013
LANG: C++14
*/

/*
 * Problem 1013 ([!meta:srcpath!])
 * Create time: Sat 22 Feb 2020 @ 19:54 (PST)
 * Accept time: Sat 22 Feb 2020 @ 20:36 (PST)
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

void setIO(const std::string &name = "1013");

using namespace std;
const int MX = 60;
int N, step[MX][MX];
queue<pii> q;

void debug()
{
    return;
    if (!q.empty()) printf("current: %d %d\n", q.front().F, q.front().S);
    printf("   "); FOR(i, N+2) printf("%3d", i); printf("\n");
    FOR(i, N+2) { printf("%3d", i); FOR(j, N+2) printf("%3d", step[i][j]); printf("\n"); }
}

int main()
{
    //setIO();
    scanf("%d", &N);
    FOR(i, N+2) FOR(j, N+2) step[i][j] = -1;
    FOR(i, N)
    {
        FOR(j, N)
        {
            scanf("%d", &step[i+1][j+1]);
            step[i+1][j+1] *= -1; // convert 1 to -1
        }
    }

    debug();

    int length=INF, count=0;
    step[1][1] = 1;
    for (q.emplace(1, 1); !q.empty(); q.pop())
    {
        auto &curr = q.front();
        debug();
        // check end
        if (curr.F == N && curr.S == N)
        {
             length = step[curr.F][curr.S];
             //printf("found a shortest path!\n");
             ++count;
        }
        if (step[curr.F][curr.S] > length) break;

        // propogate
        const int dy[] = {0, 1, 0, -1};
        const int dx[] = {1, 0, -1, 0};
        FOR(d, 4)
        {
            int y=curr.F+dy[d];
            int x=curr.S+dx[d];
            if (!step[y][x] || step[y][x] > step[curr.F][curr.S]) // FIX: allow bfs to revisit nodes as long as its not going backwards
            {
                step[y][x] = step[curr.F][curr.S] +1;
                q.emplace(y, x);
            }
        }
        //printf("continuing for the other %d nodes...\n\n\n", q.size());
    }

    printf("%d\n%d\n", count, length);

    return 0;
}

/*
2
0 0
0 0
=> 2 3
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
