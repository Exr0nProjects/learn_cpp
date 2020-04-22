/*
TASK: 116up
LANG: C++14
*/

/*
 * Problem 116up (oj/pid/116up)
 * Create time: Wed 22 Apr 2020 @ 16:27 (PDT)
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

void setIO(const std::string &name = "116up");

using namespace std;
const int MXN = 20;
const int MXM = 110;
int M, N, tab[MXN][MXM];

inline int mod(int num)
{ return (num+N) %N; }

int main()
{
    scanf("%d%d", &N, &M);
    FOR(n, N) FOR(m, M)
	scanf("%d", &tab[n][m]);

    FOR_(j, 1, M)
	FOR(i, N)
	    tab[i][j] += min(tab[i][j-1], min(tab[mod(i-1)][j-1], tab[mod(i+1)][j-1]));

    int ret=1<<30;
    FOR(i, N)
	ret = min(ret, tab[i][M-1]);

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
