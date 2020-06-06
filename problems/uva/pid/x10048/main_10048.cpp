/*
TASK: 10048
LANG: C++14
*/

/*
 * Problem 10048 (onlinejudge/pid/10048)
 * Create time: Mon 02 Mar 2020 @ 18:13 (PST)
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

void setIO(const std::string &name = "10048");

using namespace std;
const int MX = 110;
int N, M, Q;
int dist[MX][MX];

int main()
{
    setIO();
    int kase=0;
    while (1)
    {
        ++ kase;
        FOR(i, MX) FOR(j, MX) dist[i][j] = 1<<20; // FIX: reset before input duh
        // input
        scanf("%d%d%d", &N, &M, &Q);
        if (!N) break;
        FOR(i, M)
        {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            --a; --b;
            dist[a][b] = w;
            dist[b][a] = w;
            //printf("set dist %d %d -> %d\n", a, b, w);
        }

        // floyd
        FOR(k, N) FOR(i, N) FOR(j, N)
        {
            //printf("dist %d %d -> %d but %d %d, %d %d -> %d\n", i, j, dist[i][j], i, k, k, j, max(dist[i][k], dist[j][k]));
            if (dist[i][j] > max(dist[i][k], dist[k][j]))
            {
                dist[i][j] = max(dist[i][k], dist[k][j]);
            }
        }

        // handle queries
        if (kase > 1) printf("\n");
        printf("Case #%d\n", kase);
        FOR(q, Q)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            --a; --b; // FIX: don't forget to subtract to make everything zero indexed
            if (dist[a][b] == 1<<20) printf("no path\n");
            else printf("%d\n", dist[a][b]);
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
