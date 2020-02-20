/*
ID: spoytie2
TASK: paintbarn
LANG: C++14
*/

/*
 * Problem paintbarn ([!meta:srcpath!])
 * Create time: Thu 20 Feb 2020 @ 08:27 (PST)
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

void setIO(const std::string &name = "paintbarn");

using namespace std;
const int MX = 1010;
int N, K, wall[MX][MX];

int main()
{
    setIO();
    scanf("%d%d", &N, &K);
    FOR(i, N)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int x=x1; x<x2; ++x)
            for (int y=y1; y<y2; ++y)
                ++wall[x][y];
    }

    //printf("   "); FOR(i, MX) printf("%3d", i); printf("\n");
    //FOR(i, MX)
    //{
        //printf("%3d", i);
        //FOR(j, MX) printf("%3d", wall[i][j]);
        //printf("\n");
    //}

    int ret=0;
    FOR(x, MX) FOR(y, MX)
    {
        if (wall[x][y] == K) ++ret;
    }

    printf("%d\n", ret);

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
