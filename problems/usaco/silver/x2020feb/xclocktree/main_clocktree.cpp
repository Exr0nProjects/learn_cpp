/*
ID: spoytie2
TASK: clocktree
LANG: C++14
*/

/*
 * Problem clocktree ([!meta:srcpath!])
 * Create time: Sun 23 Feb 2020 @ 15:24 (PST)
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

void setIO(const std::string &name = "clocktree");

using namespace std;
const int MX = 2510;
int N, position[MX];

list<int> head[MX];

int stor[MX], solved=0;
bool solve(cn curr, cn prev = 0, cn layer=0)
{
    //FOR(i, layer) printf("    "); printf("solving %d - clocks: ", curr);
    //FOR(i, N) printf("%3d", stor[i+1]); printf("\n");

    ++stor[curr]; // increment for entering this room

    TRAV(next, head[curr])
    {
        if (next == prev) continue;
        solve(next, curr, layer+1);
        ++stor[curr]; // increment for reentering this room
        stor[curr] = (stor[curr] + 12 - stor[next] ) %12;
        stor[next] = 0;
        ++solved;

    }
    //FOR(i, layer) printf("    "); printf("       total:%3d  =>", solved); FOR(i, N) printf("%3d", stor[i+1]); printf("\n");
    if (solved+1 == N) return stor[curr] == 1 || stor[curr] == 0;
    return 0;
}

int main()
{
    setIO();
    scanf("%d", &N);
    FOR(i, N) scanf("%d", &position[i+1]);
    FOR(i, N-1)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        head[a].PB(b);
        head[b].PB(a);
    }

    int ret=0;
    FOR_(i, 1, N+1)
    {
        copy(position+1, position+N+1, stor+1);
        solved=0;
        --stor[i];
        //printf("starting solve at %d\n", i);
        if (solve(i))
        {
            ++ret;
        }
    }

    printf("%d\n", ret);

    return 0;
}

/*
4
12 11 11 11
1 2
2 3
3 4
=> 2
4
11 11 11 11
1 2
2 3
3 4
=> 4
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
