/*
TASK: 1629down
LANG: C++14
*/

/*
 * Problem 1629down (1629down)
 * Create time: Sat 14 Mar 2020 @ 10:39 (PDT)
 * Accept time: Sat 14 Mar 2020 @ 17:07 (PDT)
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

void setIO(const std::string &name = "1629down");

using namespace std;
const int MX = 23;
int N, M, K, cake[MX][MX], cherries[MX][MX][MX][MX], mem[MX][MX][MX][MX];

int countCherries(int i, int j, int k, int l)
{
    int &ret = cherries[i][j][k][l];
    if (i > k || j > l) ret = 0;
    if (i == k && j == l) ret = (bool)(cake[i][j]);
    if (ret >= 0) return ret;

    ret = countCherries(i, j, k-1, l) + countCherries(i, j, k, l-1) - countCherries(i, j, k-1, l-1) + (bool)(cake[k][l]);
    return ret;
}

int cut(int i, int j, int k, int l)
{
    int &ret = mem[i][j][k][l];
    if (countCherries(i, j, k, l) == 1) ret = 0;
    if (countCherries(i, j, k, l) == 0) ret = 1<<30; // FIX: each piece needs exactly one cherry
    if (ret <= 1<<30) return ret;

    FOR_(h, i, k) ret = min(ret, cut(i, j, h, l) + cut(h+1, j, k, l) + l-j+1);
    FOR_(v, j, l) ret = min(ret, cut(i, j, k, v) + cut(i, v+1, k, l) + k-i+1);

    return ret;
}

int main()
{
    // setIO();
    int kase=0;
    while (scanf("%d%d%d", &N, &M, &K) == 3)
    {
        // printf("n %d, m %d, k %d\n", N, M, K);
        memset(cake, 0, sizeof(cake));
        memset(cherries, 255, sizeof(cherries));
        memset(mem, 0b01111111, sizeof(mem));

        // printf("mem: %d\n", mem[2][2][2][2]);

        FOR(i, K)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            cake[a][b] = 1;
        }

        FOR_(i, 1, N) FOR_(j, 1, M) FOR_(k, 1, N) FOR_(l, 1, M) countCherries(i, j, k, l);

        printf("Case %d: %d\n", ++kase, cut(1, 1, N, M));

        // while (1)
        // {
            // int i, j, k, l;
            // scanf("%d%d%d%d", &i, &j, &k, &l);
            // printf("%3d\n", countCherries(i, j, k, l));
        // }
    }

    return 0;
}

/*
3 3 2 1 1 2 2

*/

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
