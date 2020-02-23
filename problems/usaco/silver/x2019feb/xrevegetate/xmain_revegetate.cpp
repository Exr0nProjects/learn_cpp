/*
ID: spoytie2
TASK: revegetate
LANG: C++14
*/

/*
 * Problem revegetate ([!meta:srcpath!])
 * Create time: Thu 20 Feb 2020 @ 08:42 (PST)
 * Accept time: Sat 22 Feb 2020 @ 11:24 (PST)
 *
 * The problem was that I had forgotten to check if the whole thing was even possible, and it was
 * hard to check that with my disjoint set method because it's hard to know whether to default
 * a connection or not w/o floodfilling the entire thing...
 *
 * Thus, I rewrote it with flood fill like the usaco soln uses, and it worked!
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

void setIO(const std::string &name = "revegetate");

using namespace std;
const int MX = 100010;
int N, M, vis[MX];
list<int> same[MX];
list<int> diff[MX];
bool impossible=0;

void floodFill(cn node, cn color)
{
    vis[node] = color;
    TRAV(next, same[node])
    {
        if (!vis[next]) floodFill(next, color);
        if (vis[next] != color)
        {
            impossible=1;
            return;
        }
    }
    TRAV(next, diff[node])
    {
        if (!vis[next]) floodFill(next, 3-color);
        if (vis[next] == color)
        {
            impossible=1;
            return;
        }
    }
}

int main()
{
    setIO();
    scanf("%d%d", &N, &M);
    // build djs
    FOR(i, M)
    {
        char c;
        int a, b;
        scanf("\n%c%d%d", &c, &a, &b);
        if (c == 'S')
        {
            same[a].push_back(b);
            same[b].push_back(a);
        }
        else if (c == 'D')
        {
            diff[a].push_back(b);
            diff[b].push_back(a);
        }
    }

    int ret=0;
    FOR_(i, 1, N+1)
    {
        if (! vis[i])
        {
            ++ret;
            floodFill(i, 1);
        }
    }

    if (impossible) { printf("0\n"); return 0; }
    printf("1");
    FOR(i, ret) printf("0"); // string bitshifting
    printf("\n");

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
