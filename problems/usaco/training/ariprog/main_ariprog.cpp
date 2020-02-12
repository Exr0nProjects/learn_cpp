/*
ID: spoytie2
TASK: ariprog
LANG: C++14
*/

/*
 * Problem ariprog ([!meta:srcpath!])
 * Create time: Tue 11 Feb 2020 @ 19:29 (PST)
 * Accept time: [!meta:end!]
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

void setIO(const std::string &name = "ariprog");

using namespace std;
const int MX = 125010;
int N, M;
bool bisquares[MX];
deque<int> next_bisquare;
set<pii> ret;

int main()
{
    setIO();
    scanf("%d%d", &N, &M);
    int largest_bisquare = 0;
    FOR(p, M + 1)
    FOR(q, M + 1)
    {
        int bisq = p*p+q*q;
        next_bisquare.push_back(bisq);
        bisquares[bisq] = 1;
        largest_bisquare = max(largest_bisquare, bisq);
    }

    TRAV(a, next_bisquare)
    {
        for (int b : next_bisquare)
        {
            if (b <= a) continue;
            b = b-a;
            if (a + (N-1)*b > largest_bisquare) continue;

            bool ok = 1;
            FOR(n, N)
            {
                if (!bisquares[a + n * b])
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
                ret.emplace(b, a);
        }
    }

    if (!ret.size())
        printf("NONE\n");
    TRAV(p, ret)
    {
        printf("%d %d\n", p.S, p.F);
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
