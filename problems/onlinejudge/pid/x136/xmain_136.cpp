/*
ID: spoytie2
TASK: 136
LANG: C++14
*/

/*
 * Problem 136 ([!meta:srcpath!])
 * Create time: Mon 17 Feb 2020 @ 10:20 (PST)
 * Accept time: Tue 18 Feb 2020 @ 10:53 (PST)
 *
 */

#include <iostream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
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

void setIO(const std::string &name = "136");

using namespace std;
const int MX = -1;
const int P[] = {2, 3, 5};

int main()
{
    setIO();
    set<ll> vis;
    priority_queue<ll, deque<ll>, greater<ll> > pq;
    vis.insert(1);
    pq.push(1);
    for(int i=1;; ++i) // i=1 because we already push 1
    {
        ll ith = pq.top();
        pq.pop();
        //printf("%dth: %d\n", i, ith);
        if (i == 1500)
        {
            printf("The 1500'th ugly number is %d.\n", ith); // FIX: needed newline
            return 0;
        }
        TRAV(p, P) if (vis.count(ith*p) == 0)
        {
            vis.insert(ith*p);
            pq.push(ith*p);
        }
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
