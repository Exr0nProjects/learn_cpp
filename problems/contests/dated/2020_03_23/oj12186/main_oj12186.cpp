/*
TASK: oj12186
LANG: C++14
*/

/*
 * Problem oj12186 (contests/dated/2020_03_23/oj12186)
 * Create time: Mon 23 Mar 2020 @ 15:55 (PDT)
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

void setIO(const std::string &name = "oj12186");

using namespace std;
const int MX = 100111;
int N, T, mem[MX];
vector<int> child[MX];

int require(int total)
{
    return total*100/T; // direct reporters required to pressure; TODO: might be wrong
}

int op(int n)
{
    if (mem[n]) return mem[n];
    if (child[n].size() == 0) return 1;
    sort(child[n].begin(), child[n].end(), [&](int l, int r){ return op(l) < op(r); }); // sort by workers required to pressure
    printf("%d:", n); TRAV(c, child[n]) printf("%3d", c); printf("\n");
    int ret=0;
    FOR(i, require(child[n].size())) ret += op(child[n][i]);
    mem[n] = ret;
    return ret;
}

int main()
{
    // setIO();
    while (scanf("%d%d", &N, &T) == 2)
    {
        if (!N || !T) break;
        memset(mem, 0, sizeof(mem));
        FOR(i, MX) child[i].clear();

        FOR(i, N)
        {
            int b;
            scanf("%d", &b);
            child[b].push_back(i+1); // FIX: +1 not -1
        }

        // top down dp
        printf("%d\n", op(0));
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
