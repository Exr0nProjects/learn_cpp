/*
TASK: 11584
LANG: C++14
*/

/*
 * Problem 11584 (onlinejudge/pid/11584)
 * Create time: Thu 12 Mar 2020 @ 17:00 (PDT)
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

void setIO(const std::string &name = "11584");

using namespace std;
const int MX = 1111;
int N, dp[MX][MX];
char str[MX];

int main()
{
    // setIO();
    int kase;
    scanf("%d", &kase);
    // printf("kase = %d\n", kase);
    FOR(i, kase)
    {
        FOR(i, MX) FOR(j, MX) dp[i][j] = (i == j);
        memset(str, 0, MX*sizeof(char));
        scanf("%s%n", str, &N); --N; // scanf %n is one off
        // printf("len: %d\n", N);

        FORR(i, N) FOR_(j, i+1, N)
        {
            if (i+1 == j) { dp[i][j] = (str[i] == str[j]); continue; }
            if (dp[i+1][j-1] && str[i] == str[j]) dp[i][j] = 1;
            else dp[i][j] = 0;
        }

        printf("\n   "); FOR(i, N) printf("%3c", str[i]); printf("\n"); FOR(i, N) { printf("%3c", str[i]); FOR(j, N) printf("%3d", dp[i][j]); printf("\n"); }

        // skip count the palendrome groups
        int ret=0;
        for (int i=0; i<N; ++ret)
        {
            int j;
            for (j=N-1; j>=i; --j) if (dp[i][j]) break;
            // printf("i %d, j %d\n", i, j);
            i = j+1;
        }
        printf("%d\n", ret);
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
