/*
ID: spoytie2
TASK: diamond
LANG: C++14
*/

/*
 * Problem diamond (usaco/silver/2016open/diamond)
 * Create time: Fri 07 Feb 2020 @ 17:26 (PST)
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

// for macro overloading, see https://stackoverflow.com/questions/11761703/overloading-macro-on-number-of-arguments
// this set is designed for one indexed collections
#define FOR_(i, b, e) for (int i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (int i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define SORT(a, n) std::sort((a), (a) + (n))
#define TRAV(a, x) for (auto &a : x)
#define SORTV(v) std::sort((v).begin(), (v).end())

void setIO(const std::string &name = "diamond");

typedef struct
{
    int f, t, w, n;
} Edge;
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)

const int MX = 50010;
//#define __USING_EDGELIST
//void addEdge(cn a, cn b, cn w=1);
//Edge edges[MX*MX];
//int ect=1, head[MX];

using namespace std;
int diamonds[MX];
int N, K;

int main()
{
    setIO();
    scanf("%d%d", &N, &K);
    FOR(i, N)
    {
        scanf("%d", &diamonds[i]);
    }
    sort(diamonds, diamonds + N);

    int below_bound[MX] = {}; // lowest index if upper index is i
    int above_bound[MX] = {}; // highest index if lower index is i
    int j=0; // idx of thing to set
    FOR(i, N)
    {
        while (diamonds[j]+K < diamonds[i]) ++j;
        below_bound[i] = j;
    }
    j = N-1;
    FORR(i, N)
    {
        while (diamonds[j]-K > diamonds[i]) --j;
        above_bound[i] = j;
    }

    //printf("idx:  "); FOR(i, N) printf("%3d", i);
    //printf("\ndia:  "); FOR(i, N) printf("%3d", diamonds[i]);
    //printf("\nbelow:"); FOR(i, N) printf("%3d", below_bound[i]);
    //printf("\nabove:"); FOR(i, N) printf("%3d", above_bound[i]);
    //printf("\n");

    int best_below[MX] = {}; // dp to find the best segment below i
    int best_above[MX] = {}; // same but for best segment above i
    FOR(i, N)
    {
        best_below[i] = i - below_bound[i] +1; // assume that we use the diamond at i; +1 because if best_below[i] == i we should have 1
        if (i > 0)
            best_below[i] = max(best_below[i], best_below[i-1]); // if not using the biggest we can use is better, then just don't use diamond[i]
    }
    FORR(i, N)
    {
        best_above[i] = above_bound[i] - i +1;
        if (i<N-1)
            best_above[i] = max(best_above[i], best_above[i-1]);
    }

    //printf("\nb-bot:"); FOR(i, N) printf("%3d", best_below[i]);
    //printf("\nb-top:"); FOR(i, N) printf("%3d", best_above[i]);
    //printf("\n");

    // find the best value of i
    int ret = 0;
    FOR(i, N-1)
    {
        ret = max(ret, best_below[i] + best_above[i+1]); // above is i+1 because both best_below and best_above are inclusive of i
    }

    printf("%d\n", ret);

    return 0;
}

/*
   5 1
   3 3 3 3 3
   => 5

   6 1
   1 2 3 4 5 6
   => 4

   6 1
   1 1 2 2 3 3
   => 6
   */

// boilerplate functions
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
