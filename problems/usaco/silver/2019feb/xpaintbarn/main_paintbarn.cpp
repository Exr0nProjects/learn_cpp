/*
ID: spoytie2
TASK: paintbarn
LANG: C++14
*/

/*
 * Problem paintbarn ([!meta:srcpath!])
 * Create time: Thu 20 Feb 2020 @ 13:47 (PST)
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
int dp[MX][MX]; // dp[i][j] = layers of paint at [i][j]
// 1: dp[i][j] = num begin rects - num end rects
// dp[i][j] = dp[i-1][j-1] + (dp[i][j-1] - dp[i-1][j-1]) + (dp[i-1][j] - dp[i-1][j-1]) -> (original + delta above + delta left) -> dp[i][j-1] + dp[j][i-1] - dp[i-1][j-1]
int N, K;

int main()
{
    setIO();
    scanf("%d%d", &N, &K);
    FOR(i, N)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        ++ dp[a][b]; // start the rectangle
        -- dp[a][d]; // end the rectangle (upper right)
        -- dp[c][b]; // end the rectangle (lower left)
        ++ dp[c][d]; // undo the double end in the corner
    }

    ll ret=0;
    FOR(i, MX) FOR(j, MX) // FIX: not N
    {
        if (i) dp[i][j] += dp[i-1][j];
        if (j) dp[i][j] += dp[i][j-1];
        if (i && j) dp[i][j] -= dp[i-1][j-1];
        //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        if (dp[i][j] == K) ++ret;
    }

    printf("%lld\n", ret);

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
