/*
TASK: 248
LANG: C++14
*/

/*
 * Problem 248 (usaco/gold/2016open/248)
 * Create time: Fri 27 Mar 2020 @ 12:13 (PDT)
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

void setIO(const std::string &name = "248");

using namespace std;
const int MX = 251;
int N, tab[MX][MX];

int main()
{
    setIO();
    scanf("%d", &N);
    FOR(i, N)
        scanf("%d", &tab[i][i+1]);

    int ret=0; // FIX: allow ranges of all sizes not just the entire thing

    FOR_(len, 1, N+1) // FIX: len is up through N
        FOR(i, N-len+1) // FIX: range end should go through N as well
        {
            FOR_(k, 1, len)
                if (tab[i][i+k] == tab[i+k][i+len] && tab[i][i+k] > 0)
                    tab[i][i+len] = max(tab[i][i+len], tab[i][i+k]+1);
            ret = max(ret, tab[i][i+len]);
        }

    // FOR(i, N+1) { FOR(j, N+1) printf("%3d", tab[i][j]); printf("\n"); }

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
