/*
TASK: haircut
LANG: C++14
*/

/*
 * Problem haircut (usaco/gold/2020open/haircut)
 * Create time: Sun 29 Mar 2020 @ 12:30 (PDT)
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

using namespace std;
const int MX = 200111;
ll N, A[MX];
ll presum[MX], presumrolling[MX], invs[MX];

int main()
{
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w+", stdout);
    scanf("%lld", &N);
    FOR(i, N) scanf("%lld", &A[i]);

    FOR(j, N)
    {
        FOR(i, N)
        {
            // printf("%d %d: ", i, j);
            if (i < A[j])
                ++presumrolling[i];
            // if (j)
            // {
            //     presum[i][j] += presum[i][j-1];
            // }
        }
        // FOR(k, N) printf("%3d", presumrolling[k]); printf("\n");
        presum[A[j]] = presumrolling[A[j]];
    }

    // FOR(i, N) { FOR(j, N) printf("%3d", presum[i][j]); printf("\n"); }
    // FOR(i, N) printf("(%d) presum[%d]: %d\n", i, A[i], presum[A[i]]);

    FOR(i, N)
    {
        // printf("(%d) %d += %d\n", i, A[i], presum[A[i]+1][i]);
        // invs[A[i]] += presum[A[i]][i];
        invs[A[i]] += presum[A[i]];
    }

    printf("0\n");
    FOR(i, N-1)
    {
        invs[i+1] += invs[i];
        printf("%lld\n", invs[i]);
        // printf("%lld\n", inversions(i+1));
    }

    return 0;
}
