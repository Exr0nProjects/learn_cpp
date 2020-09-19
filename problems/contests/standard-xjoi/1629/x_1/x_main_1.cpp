/*
 * Problem 1 (contests/standard-xjoi/1629/1)
 * Create time: Sat 19 Sep 2020 @ 08:35 (PDT)
 * Accept time: Sat 19 Sep 2020 @ 09:17 (PDT)
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb(x) ((x)&-(x))

#define F(i,b) for (ll i=1; i<=(b); ++i)
#define R(i,b) for (ll i=(b); i>=1; --i)
//struct Edge { int u, v, n; } edges[MX]; int head[MX], ecnt=0;

void setIO(const std::string &name = "1")
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen((name + ".in").c_str(), "r") != 0)
        freopen((name + ".in").c_str(), "r", stdin),
        freopen((name + ".out").c_str(), "w+", stdout);
}
#define _gc getchar_unlocked
inline bool sc(ll &n)
{
    int neg = 1;
    register char c;
    do c = _gc(); while (isspace(c));
    if (c == '-') neg = -1, c = _gc();
    for (n=0; c >= '0' && c <= '9'; c=_gc())
        (n *= 10) += (c-'0');
    n *= neg;
    return c != EOF;
}
inline ll sc() { ll x; sc(x); return x; }
#define _ilb inline bool
_ilb sc(int&a){ll x;bool b=sc(x);a=x;return b;}
_ilb sc(int&a,int&b){return sc(a)&&sc(b);}
_ilb sc(int&a,int&b,int&c){return sc(a,b)&&sc(c);}
_ilb sc(int&a,int&b,int&c,int&d){return sc(a,b)&&sc(c,d);}
_ilb sc(ll&a,ll&b){return sc(a)&&sc(b);}
_ilb sc(ll&a,ll&b,ll&c){return sc(a,b)&&sc(c);}
_ilb sc(ll&a,ll&b,ll&c,ll&d){return sc(a,b)&&sc(c,d);}

using namespace std;
const int MX = 5e4+11;

int N, M, K, dist[MX], hay[MX], ans[MX];
typedef pair<int, int> state;
list<pair<int, int> > hd[MX];
priority_queue<state, deque<state>, greater<state> > pq;
bool vis[MX];

int main()
{
    sc(N, M, K);
    F(i, M)
    {
        int u, v, w; sc(u, v, w);
        hd[u].pb(mp(w, v));
        hd[v].pb(mp(w, u));
    }
    F(i, K)
    {
        int n, v; sc(n, v);
        hay[n] = v;
    }

    // dijkstra w/o hay
    memset(dist, 0x3f, sizeof dist);
    pq.push(mp(0, N));
    while (!pq.empty())
    {
        state cur = pq.top(); pq.pop();
        if (vis[cur.s]) continue;
        vis[cur.s] = 1;
        dist[cur.s] = cur.f;

        for (auto e : hd[cur.s])
            if (!vis[e.s]&&cur.f + e.f < dist[e.s])
                pq.push(mp(cur.f + e.f, e.s));
    }
    //for (int i=1; i<=N; ++i) printf("%3d : %3d\n", i, dist[i]);
    // eat the hay at every location
    for (int i=1; i<=N; ++i)
        if (hay[i])
        pq.push(mp(dist[i] - hay[i], i));
    // dijkstra again after eating hay
    while (!pq.empty())
    {
        state cur = pq.top(); pq.pop();
        //printf("at %2d after %2d\n", cur.s, cur.f);
        if (!vis[cur.s]) continue;
        vis[cur.s] = 0;
        if (cur.f <= dist[cur.s]) ans[cur.s] = 1;   // FIX: compare--le not lt because at most not less than

        for (auto e : hd[cur.s])
        {
            //printf("    %d for %d\n", e.s, cur.f+e.f);
            if (vis[e.s] &&cur.f + e.f <= dist[e.s])    // FIX: compare -- this also needs to be le not lt
                pq.push(mp(cur.f + e.f, e.s));
        }
    }
    for (int i=1; i<N; ++i) printf("%d\n", ans[i]);
}

