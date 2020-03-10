/*
TASK: 3587up
LANG: C++14
*/

/*
 * Problem 3587up (xjoi.net/3587up)
 * Create time: Mon 09 Mar 2020 @ 18:25 (PDT)
 * Accept time: Mon 09 Mar 2020 @ 18:31 (PDT)
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

void setIO(const std::string &name = "3587up");

using namespace std;
const int MX = 1111;
int A, B, dp[MX][MX];
char a[MX], b[MX];

int main()
{
    // setIO();
    scanf("%s%n%s%n", a+1, &A, b+1, &B);
    B -= A; --B;
    FOR_(i, 1, A+1) FOR_(j, 1, B+1)
    {
        dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] + (a[i] == b[j]));
    }

    printf("%d\n", dp[A][B]);

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
