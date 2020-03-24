/*
TASK: oj1220
LANG: C++14
*/

/*
 * Problem oj1220 (contests/dated/2020_03_23/oj1220)
 * Create time: Mon 23 Mar 2020 @ 16:19 (PDT)
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

void setIO(const std::string &name = "oj1220");

using namespace std;
const int MX = 211;
int N, mem[MX][2];
vector<int> child[MX];
map<string, int> id_by_name;
int id(string nm)
{
    if (!id_by_name.count(nm))
    {
        // printf("%s -> %d\n", nm.c_str(), id_by_name.size());
        id_by_name[nm] = id_by_name.size();
    }
    return id_by_name[nm];
}

int op(int src, bool take)
{
    if (mem[src][take]) return mem[src][take];

    int sum=take;
    TRAV(c, child[src])
    {
        if (take) sum += op(c, 0);
        else sum += max(op(c, 1), op(c, 0));
    }
    mem[src][take] = sum;
    return sum;
}

int main()
{
    // setIO();
    while (scanf("%d", &N) == 1)
    {
        if (!N) break;
        FOR(i, MX-5) mem[i][0] = mem[i][1] = 0;
        FOR(i, MX-5) child[i].clear();
        id_by_name.clear(); // FIX: also clear id_by_name;

        string c, f;
        cin >> f;
        FOR(i, N-1)
        {
            cin >> c >> f;
            child[id(f)].push_back(id(c));
        }

        printf("%d ", max(op(0, 0), op(0, 1)));

        // check unique
        // bool unq = 1;
        // FOR(i, N) printf("%d: %d %d\n", i, op(i, 0), op(i, 1));
        // FOR(i, N) if (op(i, 0) == op(i, 1))
        // {
        //     unq = 0;
        //     break;
        // }
        if (mem[0][0] != mem[0][1]) printf("Yes\n");
        else printf("No\n");
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
