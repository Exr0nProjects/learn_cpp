/*
TASK: 1064
LANG: C++14
*/

/*
 * Problem 1064 (xjoi.net/1064)
 * Create time: Fri 13 Mar 2020 @ 11:39 (PDT)
 * Accept time: Fri 13 Mar 2020 @ 12:55 (PDT)
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

// void setIO(const std::string &name = "1064");

using namespace std;
const int MX = 1011;
int N, M, in[MX];
vector<int> head[MX];
priority_queue<int, deque<int>, greater<int> > pq;

void fill(int src)
{
    // printf("fill %d (%d)\n", src, in[src]);
    --in[src]; // FIX: negative nums act as vis array
    pq.pop(); // FIX: pop imedietly...
    if (in[src]) return; // FIX: if in[src], not src
    printf("%d ", src);
    TRAV(n, head[src])
    {
        // printf("    pushing %d\n", n);
        pq.push(n);
        // printf("    pq.top() = %d\n", pq.top());
    }
}

int main()
{
    // setIO();
    scanf("%d%d", &N, &M);
    FOR(m, M)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        head[a].PB(b);
        ++in[b];
    }
    // FOR_(i, 1, N+1) printf("%d has %d\n", i, in[i]);

    // FIX: use pq to ensure picking smallest possible each time
    FOR_(i, 1, N+1)
        if (!in[i])
        {
            ++in[i]; // FIX: counter auto-subtracting when calling fill(i) from pq
            pq.push(i);
        }
    while (!pq.empty())
        fill(pq.top());
    printf("\n");

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
