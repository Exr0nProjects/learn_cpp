/*
TASK: 11584down
LANG: C++14
*/

/*
 * Problem 11584down (oj/pid/11584down)
 * Create time: Fri 13 Mar 2020 @ 15:50 (PDT)
 * Accept time: Fri 13 Mar 2020 @ 16:22 (PDT)
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

void setIO(const std::string &name = "11584down");

using namespace std;
const int MX = 1011;
char str[MX];
int N, ispal[MX][MX], bestsplit[MX];
bool checkPalVis[MX][MX];

int checkPal(int i, int j)
{
    if (j < 0 || i >= N || i > j) return 0;
    if (checkPalVis[i][j]) return ispal[i][j];
    int ret=0;
    if (i == j) ret=1;
    else if (i+1 == j) ret=(str[i] == str[j]);
    else ret = (checkPal(i+1, j-1) && str[i] == str[j]); // FIX: checkPal(i+1, j-1) not (i-1, j+1)

    checkPalVis[i][j] = 1;
    ispal[i][j] = ret;
    return ret;
}

int splitFrom(int beg)
{
    if (beg < 0 || beg >= N) return 0;
    if (bestsplit[beg]) return bestsplit[beg];
    int ret = 1<<30;
    FORR(end, N) if (checkPal(beg, end))
    {
        // printf("    end = %d\n", end);
        ret = min(ret, splitFrom(end+1) + 1);
    }
    bestsplit[beg] = ret;
    return ret;
}

int main()
{
    // setIO();
    int kase;
    scanf("%d", &kase);
    FOR(ks, kase)
    {
        memset(ispal, 0, sizeof(ispal));
        memset(bestsplit, 0, sizeof(bestsplit));
        memset(checkPalVis, 0, sizeof(checkPalVis));

        scanf("%s%n", str, &N);
        --N;
        // printf("N=%d\n", N);

        FOR(i, N) FOR_(j, i, N)
            checkPal(i, j);

        // FOR(i, N) { FOR(j, N) printf("%3d", ispal[i][j]); printf("\n"); }

        printf("%d\n", splitFrom(0));
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
