/*
 * Problem 5 (contests/standard-xjoi/1731/5)
 * Create time: Sun 18 Oct 2020 @ 16:10 (PDT)
 * Accept time: [!meta:end!]
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

#define gpq(T) priority_queue<T, deque<T>, greater<T> >
#define CMA , // https://stackoverflow.com/q/13842468/10372825
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb(x) ((x)&-(x))

#define F(i,b) for (ll i=1; i<=(b); ++i)
#define R(i,b) for (ll i=(b); i>=1; --i)
//struct Edge { int u, v, n; } eg[MX]; int hd[MX], ecnt=0;
//
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
#define gcd(_a, _b) ({auto a=_a;auto\
    b=_b;while(b)(a)%=(b),(a)^=(b)^=(a)^=(b);a;})

using namespace std;
const int MX = 1e4+11;
const int MOD = 9987;

ll N, M, S, T, dist[MX], pre[MX];

vector<pair<int, int> > hd[MX];

//struct Edge { ll t, w, n; } eg[MX*MX]; ll hd[MX], ecnt=2;
//void addEdge(ll u, ll v, ll w, bool b=1)
//{
//    eg[ecnt].t = v;
//    eg[ecnt].w = w;
//    eg[ecnt].n = hd[u];
//    hd[u] = ecnt++;
//    if (b) addEdge(v, u, w, 0);
//}

void addEdge(ll u, ll v, ll w, bool b=1)
{
    hd[u].pb(mp(w, v));
    hd[v].pb(mp(w, u));
}

int main()
{
    sc(N, M);
    S = 1, T = N;
    while (M--) addEdge(sc(), sc(), sc());
    //for (int i=1; i<=M; ++i)
    //{
    //    int u, v, w; sc(u, v, w);
    //    addEdge(u, v, w);
    //}

    // dijkstra
    typedef pair<ll, pair<int, int> > State;
    gpq(State) pq;
    dist[S] = 1;
    pq.push(mp(1, mp(S, 0)));
    memset(dist, 0x3f, sizeof dist);
    while (!pq.empty())
    {
        State c = pq.top(); pq.pop();
        //printf("%lld : %d <- %d\n", c.f, c.s.f, c.s.s);
        if (dist[c.s.f] < c.f) continue;
        dist[c.s.f] = c.f;
        pre[c.s.f] = c.s.s;
        if (c.s.f == T) break;

        //for (int e=hd[c.s.f]; e; e=eg[e].n)
        //{
        //    if (c.s.f + eg[e].w < dist[eg[e].t])
        //        pq.push(mp(c.f + eg[e].w, mp(eg[e].t, c.s.f)));
        //}
        for (auto n : hd[c.s.f])
            if (c.s.f * n.f % MOD < dist[n.s])
                pq.push(mp(c.f * n.f % MOD, mp(n.s, c.s.f)));
    }

    printf("%d\n", dist[T]);
    //int l=0, c=T; while (c) dist[l++] = c, c = pre[c];
    //while (l--) printf("%d%c", dist[l], l ? ' ' : '\n');
}

