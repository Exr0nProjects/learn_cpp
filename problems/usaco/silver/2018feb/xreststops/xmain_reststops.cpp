/*
ID: spoytie2
TASK: reststops
LANG: C++14
*/

/*
 * Problem reststops ([!meta:srcpath!])
 * Create time: Tue 18 Feb 2020 @ 09:01 (PST)
 * Accept time: Wed 19 Feb 2020 @ 11:51 (PST)
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

void setIO(const std::string &name = "reststops");

using namespace std;
const int MX = 100010;
int L, N, dR;
pii stops[MX];
int best_after[MX]; // best rest stop after stop #i

int main()
{
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w+", stdout);
    int rf, rb;
    scanf("%d%d%d%d", &L, &N, &rf, &rb);
    dR = rf - rb;
    FOR(i, N)
    {
        int x, c;
        scanf("%d%d", &x, &c);
        stops[i] = {x, c};
    }
    sort(stops, stops+N);
    FORR(i, N) // suffix max
    {
        best_after[i] = i;
        if (i < N-1 && stops[best_after[i+1]].S > stops[i].S) best_after[i] = best_after[i+1];
        //printf("best after %d is %d\n", i, best_after[i]);
    }
    //FOR(i, N) printf("%3d", i); printf("\n");
    //FOR(i, N) printf("%3d", best_after[i]); printf("\n");

    ll idx=0, lead=0, prev=0, ret=0;
    do
    {
        idx = best_after[idx];
        lead = (stops[idx].F - prev)*dR;
        prev = stops[idx].F;
        ret += lead * stops[idx].S;
        ++idx;
    } while (idx < N);

    printf("%lld\n", ret);

    return 0;
}

void setIO(const string &name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // fast cin/cout
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w+", stdout);
}
