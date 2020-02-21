/*
ID: spoytie2
TASK: snowboots
LANG: C++14
*/

/*
 * Problem snowboots ([!meta:srcpath!])
 * Create time: Wed 19 Feb 2020 @ 12:10 (PST)
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

void setIO(const std::string &name = "snowboots");

using namespace std;
const int MX = 260;
int N, B, depth[MX], si[MX], di[MX]; // si is depth, di is distance
int tab[MX][MX];
int best=INF; // FIX: for some reason this makes it not bus error? I suppose it's simpler...

void dp(cn pos, cn boot, cn layer=0)
{ // FIX: remember what si and di mean
    //FOR(i, layer) printf("| "); printf("p %d b %d\n", pos, boot);
    if (tab[pos][boot]) return;
    tab[pos][boot] = true;
    if (pos >= N-1) { best = min(best, boot); return; }; // made it
    if (boot >= N) return; // impossible to get to the end; FIX: make sure there is a break condition for each arg possibility
    if (depth[pos] <= si[boot]) // can step w/ curr boots
    {
        for (int step=pos+1; step<=pos+di[boot] && step<N; ++step)
        {
            if (depth[step] > si[boot]) continue;
            dp(step, boot, layer+1);
        }
    }
    if (boot < B-1)
    {
        //printf("bus err: pos %d boot %d\n", pos, boot);
        dp(pos, boot+1);
        //ret = min(ret, dp(pos, boot+1, layer+1));
    }
    //printf("p %d b %d -> %d\n", pos, boot, ret);
    return;
}

int main()
{
    setIO();
    scanf("%d%d", &N, &B);
    FOR(i, N) scanf("%d", &depth[i]);
    FOR(i, B) scanf("%d%d", &si[i], &di[i]);
    dp(0, 0);
    printf("%d\n", best);

    return 0;
}

/*
1 1
1
1 1
=> 0

2 1
1 1
1 1
=> 0
2 2
1 2
1 1
1 2
=> 1
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
