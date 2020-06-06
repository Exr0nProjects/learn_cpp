/*
TASK: 1629up
LANG: C++14
*/

/*
 * Problem 1629up (oj/pid/1629up)
 * Create time: Sat 14 Mar 2020 @ 17:11 (PDT)
 * Accept time: Sat 14 Mar 2020 @ 17:59 (PDT)
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

void setIO(const std::string &name = "1629up");

using namespace std;
const int MX = 25;
int N, M, K, cake[MX][MX], tab[MX][MX][MX][MX];

inline int countCherries(int i, int j, int k, int l)
{ return cake[k][l] + cake[i-1][j-1] - cake[i-1][l] - cake[k][j-1]; } // FIX: fencepost on (i, j)

int main()
{
    // setIO();
    int kase=0;
    while (scanf("%d%d%d", &N, &M, &K) == 3) // FIX: ==3 to stop the program properly
    {
        memset(cake, 0, sizeof(cake));
        memset(tab, 0, sizeof(tab));
        FOR(k, K)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            cake[a][b] = 1;
        }
        // printf("done inputing...\n");

        // prefix sum on cherries
        FOR_(n, 1, MX) FOR_(m, 1, MX) cake[n][m] += cake[n-1][m] + cake[n][m-1] - cake[n-1][m-1]; // FIX: +=, not = because otherwise we overwrite the input
        // FOR(i, N+3) { FOR(j, M+3) printf("%3d", cake[i][j]); printf("\n"); }
        // while (true)
        // {
        //     int i, j, k, l;
        //     scanf("%d%d%d%d", &i, &j, &k, &l);
        //     printf("=> %d\n", countCherries(i, j, k, l));
        // }

        // dp
        FOR(h, N) FOR(w, M) FOR_(i, 1, N+1) FOR_(j, 1, M+1) // FIX: i and j are one indexed, h and w are zero indexed (because they are added to i and j)
        {
            int k = i+h;
            int l = j+w;
            // printf("(%d %d) (%d %d)\n", i, j, k, l);
            if (k > N || l > M) continue;
            else if (countCherries(i, j, k, l) == 0) tab[i][j][k][l] = 1<<20;
            else if (countCherries(i, j, k, l) == 1) tab[i][j][k][l] = 0;
            else
            {
                int ret = 1<<20;
                FOR_(vert, i, k)
                    ret = min(ret, tab[i][j][vert][l] + tab[vert+1][j][k][l] + (int)w+1);
                FOR_(horz, j, l)
                    ret = min(ret, tab[i][j][k][horz] + tab[i][horz+1][k][l] + (int)h+1);
                tab[i][j][k][l] = ret;
            }
        }
        printf("Case %d: %d\n", ++kase, tab[1][1][N][M]);
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
