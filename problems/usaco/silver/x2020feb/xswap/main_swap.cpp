/*
ID: spoytie2
TASK: swap
LANG: C++14
*/

/*
 * Problem swap ([!meta:srcpath!])
 * Create time: Sun 23 Feb 2020 @ 13:24 (PST)
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

void setIO(const std::string &name = "swap");

using namespace std;
const int MX = 100010;
int N, M, K, lef[110], rig[110];

int cows[MX];

bool vis[MX];
int father[MX], offset[MX];
vector<int> chains[MX];
int findChain(cn src, cn cur, cn off=0)
{
    //printf("    %d gets to %d after %d steps\n", src, cur, off);
    if (src == cur && off > 0) return off;
    vis[cur] = 1;
    father[cur] = src;
    offset[cur] = off;
    chains[src].PB(cur);
    return findChain(src, cows[cur], off+1);
}

int main()
{
    setIO();
    scanf("%d%d%d", &N, &M, &K);
    FOR(i, M)
    {
        scanf("%d%d", &lef[i], &rig[i]);
        --lef[i];
        --rig[i];
    }
    // simulate M reversals
    iota(cows, cows+N, 0);
    FOR(m, M)
    {
        //printf("m=%d\n", m);
        FOR(i, (rig[m]-lef[m]+1)/2)
        {
            //printf("    i = %d\n", i);
            swap(cows[lef[m]+i], cows[rig[m]-i]);
        }
    }
    //FOR(i, N) printf("%3d", cows[i]+1); printf("\n");

    FOR(i, N)
    {
        if (!vis[i])
        {
            //printf("finding chain %d\n", i);
            findChain(i, i);
        }
    }

    //FOR(i, N)
    //{
        //printf("chain %d (father %d offset %d):", i+1, father[i]+1, offset[i]);
        //FOR(j, chains[father[i]].size()) printf("%3d", chains[father[i]][(j+offset[i])%chains[father[i]].size()]+1);
        //printf("\n");
    //}

    FOR(i, N)
    {
        auto &chain = chains[father[i]];
        printf("%d\n", chain[(offset[i]+K)%chain.size()]+1);
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
