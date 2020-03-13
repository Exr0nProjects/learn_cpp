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
int N, ispal[MX][MX], split[MX];
char str[MX];

int main()
{
    // setIO();
    int kase;
    scanf("%d", &kase);
    // printf("kase = %d\n", kase);
    FOR(i, kase)
    {
        FOR(i, MX) FOR(j, MX) ispal[i][j] = (i == j);
        memset(str, 0, MX*sizeof(char));
        memset(split, 0, sizeof(split));
        scanf("%s%n", str+1, &N); --N; // scanf %n is one off
        // printf("len: %d\n", N);

        FORR_(i, 1, N+1) FOR_(j, i+1, N+1)
        {
            if (i+1 == j) { ispal[i][j] = (str[i] == str[j]); continue; }
            if (ispal[i+1][j-1] && str[i] == str[j]) ispal[i][j] = 1;
            else ispal[i][j] = 0;
        }

        // printf("\n   "); FOR_(i, 1, N+1) printf("%3c", str[i]); printf("\n"); FOR_(i, 1, N+1) { printf("%3c", str[i]); FOR_(j, 1, N+1) printf("%3d", ispal[i][j]); printf("\n"); }

        // dp on split: least num pals needed to split string up to i
        split[0] = 0;
        FOR_(i, 1, N+1)
        {
            split[i] = 1<<30;
            FOR(j, i)
                if (ispal[j+1][i])
                    split[i] = min(split[i], split[j] +1);
            // printf("%3d", split[i]);
        }
        // printf("\n");

        printf("%d\n", split[N]);
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
