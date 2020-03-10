/*
TASK: 3587down
LANG: C++14
*/

/*
 * Problem 3587down (xjoi.net/3587down)
 * Create time: Mon 09 Mar 2020 @ 18:00 (PDT)
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

void setIO(const std::string &name = "3587down");

using namespace std;
const int MX = 1111;
int A, B, dp[MX][MX];
char a[MX], b[MX];

int recurse(int i, int j)
{
    if (i < 1 || j < 1) return 0;
    int &ret = dp[i][j];
    if (ret) return ret;

    ret = max(ret, recurse(i-1, j));
    ret = max(ret, recurse(i, j-1));
    ret = max(ret, recurse(i-1, j-1) + (a[i] == b[j])); // FIX: order of ops, need to put equality in parens

    // printf("%d %d -> %d\n", i, j, ret);
    return ret;
}

int main()
{
    // setIO();
    scanf("%s%n%s%n", a+1, &A, b+1, &B); // FIX: one index so recursive doesn't access negative array index
    B -= A; --B; // FIX: fencepost and adding of scanf's character count
    // printf("%d: %s\n%d: %s\n", A, a+1, B, b+1);

    printf("%d\n", recurse(A, B));

    // FOR(i, A+1) { FOR(j, B+1) printf("%3d", dp[i][j]); printf("\n"); }

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
