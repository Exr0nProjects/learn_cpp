/*
ID: spoytie2
TASK: mootube
LANG: C++14
*/

/*
 * Problem mootube ([!meta:srcpath!])
 * Create time: Wed 19 Feb 2020 @ 18:27 (PST)
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

void setIO(const std::string &name = "mootube");

using namespace std;
const int MX = 5010;
int N, Q;
int relevance[MX][MX];

// FIX: edgelist impl was flawwed, using more stl instead
list<pair<int, int> > head[MX];
void addEdge(cn a, cn b, cn w)
{
    head[a].emplace_back(b, w);
}

//struct Edge
//{
    //int f, t, w, n;
//} edges[MX]; // not MX^2 cuz its a tree
//int head[MX], ect=1;
//void addEdge(cn a, cn b, cn w)
//{
    //edges[ect].f = a;
    //edges[ect].t = b;
    //edges[ect].w = w;
    //edges[ect].n = head[a];
    //head[a] = ect;
    //++ect;
//}

void getDistances(cn src, cn cur, cn prev=0, cn dist=INF)
{
    //printf("getting dist from %d -> %d\n", src, cur);
    if (relevance[src][cur]) return;
    relevance[src][cur] = dist;

    TRAV(p, head[cur])
    {
        if (p.F == prev) continue;
        getDistances(src, p.F, cur, min(dist, p.S));
    }
    //TRAVE(e, cur)
    //{
        //if (edges[e].t == prev) continue;
        //getDistances(src, edges[e].t, cur, min(dist, edges[e].w));
    //}
}

int main()
{
    setIO();
    scanf("%d%d", &N, &Q);
    FOR(i, N-1)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        addEdge(a, b, w);
        addEdge(b, a, w); // undirected
    }

    FOR(i, N)
    {
        getDistances(i+1, i+1);
    }

    //printf("\n   "); FOR(i, N+1) printf("%3d", i); printf("\n");
    //FOR(i, N+1)
    //{
        //printf("%3d", i);
        //FOR(j, N+1) printf("%3d", relevance[i][j] < 1000 ? relevance[i][j] : 0);
        //printf("\n");
    //}

    FOR(i, Q)
    {
        int k, v;
        scanf("%d%d", &k, &v);
        int count=0;
        FOR(o, N) // FIX: o needs to be +1 everywhere cuz adjlist is one indexed
        {
            if (v == o+1) continue;
            if (relevance[v][o+1] >= k)
            {
                //printf("placing %d with %d\n", v, o+1);
                ++count;
            }
        }
        printf("%d\n", count);
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
