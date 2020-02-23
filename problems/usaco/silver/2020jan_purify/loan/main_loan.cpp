/*
ID: spoytie2
TASK: loan
LANG: C++14
*/

/*
 * Problem loan ([!meta:srcpath!])
 * Create time: Sun 23 Feb 2020 @ 09:55 (PST)
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

#define cn const int
#define ll long long
#define cl const long long
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 0x7FFFFFFF

#define FOR_(i, b, e) for (int i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (int i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define SORT(a, n) std::sort((a), (a) + (n))
#define TRAV(a, x) for (auto &a : x)
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)
#define SORTV(v) std::sort((v).begin(), (v).end())

void setIO(const std::string &name = "loan");

using namespace std;
const int MX = -1;
ll N, K, M;

bool check(ll x)
{
    ll debt=N, days=K;
    while (debt > 0 && days > 0)
    {
        ll y = floor(debt/x);
        if (y < M) return debt <= M*days;
        ll max_debt = (y*x)+x-1; // max debt for y to be the same as this debt
        ll num_days = (max_debt - y*x) / x; // number of days that FJ pays y to bessie
        printf("max debt %d num days %d\n", max_debt, num_days);

        days -= num_days;
        debt -= y*num_days;
    }
    return debt <= 0;
}

int main()
{
    setIO();
    scanf("%d%d%d", &N, &K, &M);

    ll l=1, r=(ll)1<<60;
    FOR(i, 100)
    {
        ll m=(l+r)/2;
        if (check(m)) l=m;
        else r=m;
    }

    printf("%lld\n", l);

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
