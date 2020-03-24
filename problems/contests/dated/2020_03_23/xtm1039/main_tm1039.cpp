/*
TASK: tm1039
LANG: C++14
*/

/*
 * Problem tm1039 (contests/dated/2020_03_23/tm1039)
 * Create time: Mon 23 Mar 2020 @ 16:59 (PDT)
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

void setIO(const std::string &name = "tm1039");

using namespace std;
const int MX = 6111;

int N, value[MX], mem[MX][2];
bool has_father[MX]; // used to figure out who the root is
list<int> child[MX];

int op(int src, bool take)
{
    // printf("op %d %d\n", src, take);
    if (mem[src][take]) return mem[src][take];
    int sum = take * value[src];
    TRAV(c, child[src])
    {
        if (take) sum += op(c, 0);
        else sum += max(op(c, 0), op(c, 1));
    }
    mem[src][take] = sum;
    return sum;
}

int main()
{
    // setIO();
    scanf("%d", &N);
    FOR(i, N)
        scanf("%d", &value[i+1]);
    FOR(i, N)
    { // TODO: unsure if the tree is gaurenteed to be connected
        int a, b;
        scanf("%d%d", &a, &b);
        child[b].push_back(a);
        has_father[a] = 1;
    }

    FOR_(i, 1, N+1)
        if (!has_father[i])
        {
            printf("%d\n", max(op(i, 0), op(i, 1)));
            break;
        }
    // FOR(i, N) printf("%d: %d %d\n", i, mem[i][0], mem[i][1]);

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
