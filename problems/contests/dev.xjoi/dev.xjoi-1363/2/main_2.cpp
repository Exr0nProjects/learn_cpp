/*
ID: spoytie2
TASK: 2
LANG: C++14
*/

/*
 * Problem 2 ([!meta:srcpath!])
 * Create time: Wed 19 Feb 2020 @ 09:09 (PST)
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

void setIO(const std::string &name = "2");

using namespace std;
const int MX = 500010;
int N, K, weight[MX];

int main()
{
    //setIO();
    scanf("%d%d", &N, &K);
    FOR(i, N) scanf("%d", &weight[i]);
    priority_queue<double> best;
    FOR(i, N)
    {
        int v;
        scanf("%d", &v);
        double ratio = (double) v/(double)weight[i];
        //printf("inserting %lf\n", ratio);
        best.push(ratio);
    }

    double ret = 0;
    FOR(i, K)
    {
        //printf("adding %lf\n", best.top());
        ret += best.top();
        best.pop();
    }

    //printf("sum: %lf\n", ret);

    /*
     * idk whats going on cuz the sample test case says the answer should be 0.75
     * but we can actually get 0.8??
     */

    printf("%.2lf\n", ret/K);

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
