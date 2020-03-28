/*
TASK: milkorder
LANG: C++14
*/

/*
 * Problem milkorder (usaco/gold/2018open/milkorder)
 * Create time: Sat 28 Mar 2020 @ 12:07 (PDT)
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

void setIO(const std::string &name = "milkorder");

using namespace std;
const int MX = 100111;
const int MMX = 50111;
int N, M, indeg[MX], order[MX];
list<pair<int, int> > observations[MMX];
list<int> head[MX];

bool check(int xx)
{
    if (xx > M) return 0;
    memset(indeg, 0, sizeof(indeg));
    memset(order, 0, sizeof(order));
    FOR(i, MX) head[i].clear();

    for (int iii=0; iii<xx; ++iii)
    {
        for (auto p : observations[iii])
        {
            head[p.F].pb(p.S);
            ++indeg[p.S];
        }
    }

    // FOR_(i, 1, N+1)
    // {
    //     printf("%d:", i);
    //     TRAV(n, head[i]) printf("%3d", n);
    //     printf("\n");
    // }

    priority_queue<int, deque<int>, greater<int> > pq; // FIX: min pq not max
    FOR_(i, 1, N+1) // FIX: 1 index
        if (!indeg[i]) pq.push(i);
    FOR(i, N)
    {
        if (pq.empty()) return 0; // cycle, because there weren't enough nodes with indeg 0
        int top = pq.top();
        pq.pop();

        order[i] = top;

        TRAV(n, head[top])
            if (!--(indeg[n]))
                pq.push(n);
    }
    return 1;
}

int main()
{
    setIO();
    scanf("%d%d", &N, &M);
    FOR(i, M)
    {
        int m, cur, pre;
        scanf("%d", &m);
        FOR(j, m)
        {
            scanf("%d", &cur);
            if (j) observations[i].eb(pre, cur);
            pre = cur;
        }
    }

    int l=0, r=MMX+10;
    FOR(i, 20)
    {
        if (l+1==r) break; // TODO: shouldn't be nessecary
        // int m = l/2+r/2+(l%2&r%2);
        int m = (l+r)/2;
        if (check(m)) l=m;
        else r=m;
    }

    FOR(i, N)
    {
        if (i) printf(" ");
        printf("%d", order[i]);
    }
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
