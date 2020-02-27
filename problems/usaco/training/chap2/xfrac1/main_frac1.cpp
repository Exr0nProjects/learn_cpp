/*
TASK: frac1
LANG: C++14
*/

/*
 * Problem frac1 (usaco/training/chap2/frac1)
 * Create time: Wed 26 Feb 2020 @ 19:17 (PST)
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

void setIO(const std::string &name = "frac1");

using namespace std;
const int MX = -1;
int N;
priority_queue<pair<dl, pii>, deque<pair<dl, pii> >, greater<pair<dl, pii> > > fracs;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    setIO();
    fracs.emplace(0, MP(0, 1));
    fracs.emplace(1, MP(1, 1));

    scanf("%d", &N);
    FOR_(i, 2, N+1)
    {
        FOR_(j, 1, i)
        {
            if (gcd((int)i, (int)j) != 1) continue;
            fracs.emplace((dl)j/i, MP(j, i));
        }
    }

    for (; !fracs.empty(); fracs.pop())
    {
        printf("%d/%d\n", fracs.top().S.F, fracs.top().S.S);
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
