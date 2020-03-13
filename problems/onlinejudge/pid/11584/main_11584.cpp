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
int N, dp[MX];
char str[MX];

int main()
{
    setIO();
    int kase;
    scanf("%d", &kase);
    FOR(i, kase)
    {
        memset(dp, 0, MX*sizeof(int));
        memset(str, 0, MX*sizeof(char));
        scanf("%s%n", str, &N); --N; // scanf %n is one off
        // printf("len: %d\n", N);

        // get length of same char stretch
        FORR(i, N)
        {
            if (str[i] != str[i+1]) dp[i] = 1;
            else dp[i] = dp[i+1] + 1;
        }
        // double extend pals (_bab_ -> ababa)
        FORR(i, N-1)
        {
            if (i+1 + dp[i+1] < N && str[i] == str[i+1+dp[i+1]]) // jumping pal len of one over in range && this character wraps the one over pal with the char on the other side
                dp[i] = max(dp[i], dp[i+1] +2);
            else if (dp[i+1] >= dp[i]) dp[i] = 1; // don't be too greedy... TODO: sketchy

        }

        // FOR(i, N) printf("%3d", dp[i]); printf("\n");

        // skip count the palendrome groups
        int ret=0;
        for (int i=0; i<N;)
        {
            ++ret;
            i += dp[i];
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
