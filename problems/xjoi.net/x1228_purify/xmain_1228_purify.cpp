/*
ID: spoytie2
TASK: 1228_purify
LANG: C++14
*/

/*
 * Problem 1228_purify ([!meta:srcpath!])
 * Create time: Sat 22 Feb 2020 @ 20:40 (PST)
 * Accept time: Sat 22 Feb 2020 @ 21:08 (PST)
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

void setIO(const std::string &name = "1228_purify");

using namespace std;
const int MX = 16;
int N, ret=0;
bool horz[MX], diag1[MX*2], diag2[MX*2];

void dfs(cn col)
{
    if (col == N) // can get away with this because we can only put one queen per col anyways
    {
        ++ret;
        return;
    }
    FOR(i, N)
    {
        if (horz[i] || diag1[i+col] || diag2[i+N-col]) continue;
        horz[i] = diag1[i+col] = diag2[i+N-col] = 1;
        dfs(col+1);
        horz[i] = diag1[i+col] = diag2[i+N-col] = 0;
    }
}

int main()
{
    //setIO();
    scanf("%d", &N);

    dfs(0);

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
