/*
ID: spoytie2
TASK: lifegaurds
LANG: C++14
*/

/*
 * Problem lifegaurds ([!meta:srcpath!])
 * Create time: Wed 19 Feb 2020 @ 19:14 (PST)
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

void setIO(const std::string &name = "lifegaurds");

using namespace std;
const int MX = 100010;
int N;
vii shift;

int main()
{
    setIO();
    scanf("%d", &N);
    FOR(i, N)
    {
        int b, e;
        scanf("%d%d", &b, &e);
        shift.emplace_back(b, e);
    }
    sort(shift.begin(), shift.end());
    // make all shifts represent alone time
    FOR(i, N)
    {
        FOR(j, i)
        {
            if (shift[j].F <= shift[i].F && shift[i].F <= shift[j].S)
            {
                swap(shift[j].F, shift[i].S);
            }
        }
    }

    printf("n = %d\n", N);


    ll max_time=shift[0].S - shift[0].F, total=0;
    FOR(i, N)
    {
        ll time = shift[i].S - shift[i].F;
        if (time > max_time)
        {
            max_time = time;
            printf("max time: %d\n", time);
        }
        total += time;
    }

    printf("%lld\n", total - max_time);

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
