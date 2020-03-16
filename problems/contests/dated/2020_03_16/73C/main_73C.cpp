/*
TASK: 73C
LANG: C++14
*/

/*
 * Problem 73C (contests/dated/2020_03_16/73C)
 * Create time: Mon 16 Mar 2020 @ 15:23 (PDT)
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

void setIO(const std::string &name = "73C");

using namespace std;
const int MX = 111;
const int MXA = 6; // TODO: return to 26
char name[MX], bonus[MXA+4][MXA+4];
int N, K, M;
pii mem[MX][MX]; // tab[i][j][k] = best after letter i with letter i-1 = j and having k swaps remaining

pii dp(int i, int k, int layer=0)
{
    FOR(i, layer) printf("    "); printf("%d %d\n", i, k);

    if (mem[i][k].F) return mem[i][k];
    if (i <= 0) return {0, 0};
    if (k <= 0)
    {
        pii pre = dp(i-1, k, layer+1);
        return { pre.F + bonus[name[i-1]][name[i]], name[i] };
    }
    int ret = 0;
    FOR(pj, MXA) ret = max(ret, dp(i-1, pj, k, layer+1) + bonus[pj][j]);
    FOR(let, MXA) FOR(pj, MXA)
    {
        ret = max(ret, dp(i-1, pj, k-(let), layer+1) + bonus[pj][let]);
    }
    FOR(i, layer) printf("    "); printf("=> %d\n", ret);
    mem[i][j][k] = ret;
    return ret;
}

int main()
{
    // setIO();
    scanf("%s%n%d%d", name, &N, &K, &M);
    FOR(i, N) name[i] -= 'a';
    FOR(i, M)
    {
        char u, v;
        int w;
        scanf("\n%c%*c%c%d", &u, &v, &w);
        // printf("%c, %c -> %d\n", u, v, w);
        bonus[u-'a'][v-'a'] = w;
    }

    int ret=0;
    FOR(pj, MXA) ret = max(ret, dp(N-1, pj, K));
    printf("%d\n", ret);

    return 0;
}

/*
a 0
1
a a 1
=> 0

aaa 1
2
b b 2
b a 1
=> 1
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
