/*
 * Problem 3 (contests/standard-xjoi/1625/3)
 * Create time: Fri 18 Sep 2020 @ 11:58 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <stack>
#include <queue>

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

void setIO(const std::string &name = "3")
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
const int MX = 1e5+11;
typedef pair<int, pair<int, int> > edge; // cost from to

int N, M, T, num[MX];
int dist[MX], from[MX];
bool vis[MX];
list<pair<int, int> > head[MX];
stack<int> rwd; // calculating how many cows go thru each edge

int main()
{
    sc(N, M, T);
    for (int i=1; i<=N; ++i) sc(num[i]);
    for (int i=1; i<=M; ++i)
    {
        int u, v, w; sc(u, v, w);
        head[u].pb(mp(v, w));
        head[v].pb(mp(u, w));
    }

    // dijkstra
    memset(dist, 0x3f, sizeof dist);    // FIX: init dist to inf
    priority_queue<edge, deque<edge>, greater<edge> > pq;
    pq.push(mp(0, mp(0, 1)));
    while (!pq.empty())
    {
        edge cur = pq.top(); pq.pop();
        printf("cur: %3d for %d..%d\n", cur.f, cur.s.f, cur.s.s);
        if (vis[cur.s.s]) continue;
        vis[cur.s.s] = 1;
        from[cur.s.s] = cur.s.f;
        rwd.push(cur.s.s);

        for (auto e : head[cur.s.s])
        {
            if (cur.f + e.s <= dist[e.f])
                pq.push(mp(cur.f + e.s, mp(cur.s.s, e.f)));
        }
    }

    for (int i=1; i<=N; ++i) printf("from[%d] = %d\n", i, from[i]);
}

