/*
 * Problem dinic2 (../algorithms/graphs/network_flow/dinic2)
 * Create time: Thu 15 Oct 2020 @ 19:06 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>

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

//void setIO(const std::string &name = "dinic2")
//{
//    //ios_base::sync_with_stdio(0); cin.tie(0);
//    if (fopen((name + ".in").c_str(), "r") != 0)
//        freopen((name + ".in").c_str(), "r", stdin),
//        freopen((name + ".out").c_str(), "w+", stdout);
//}
#define _gc getchar
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
const int MX = 1e5+11;

ll N, M, S, T, dep[MX];
// cap[MX][MX];

struct Edge { ll t, n, w; } edges[MX]; ll thead[MX], head[MX], ecnt=2;
void addEdge(ll a, ll b, ll w)
{
    //cap[a][b] = w;
    edges[ecnt].w = w;
    //printf("%d -> %d = %d\n", a, b, edges[ecnt].w);
    //edges[ecnt].f = a;
    edges[ecnt].t = b;
    edges[ecnt].n = head[a];
    head[a] = ecnt++;   // FIX: update head
}

bool kdep()
{
    memset(dep, 0, sizeof dep);
    queue<ll> q;
    q.push(S);
    dep[S] = 1; // FIX: don't return to source
    //bool flag=0;
    //memcpy(thead, head, N+1<<2);   // FIX: args--memcpy last arg is length, not end pointer
    copy(head, head+N+1, thead);
    while (!q.empty())
    {
        ll c = q.front(); q.pop();
        //printf("c = %d\n", c);
        //if (c == T) flag = 1;
        if (c == T) return 1;   // FIX: no need to wait

        //for (int n=1; n<=N; ++n)
        for (ll e=head[c]; e; e=edges[e].n)
            if (!dep[edges[e].t] && edges[e].w)
                dep[edges[e].t] = dep[c]+1, q.push(edges[e].t);
    }
    //for (int i=1; i<=N; ++i) printf("%3d", thead[i]); printf("\n");
    //return !q.empty();
    return 0;
}


ll aug(ll c, ll mn)
{
    //printf("%d %d\n", c, mn);
    if (!mn || c == T) return mn;
    ll flo=0;
    //for (int n=1; n<=N; ++n) if (dep[n] == dep[c]+1)
    for (ll e=thead[c]; e; e=edges[e].n)
    {
        if (dep[edges[e].t] == dep[c]+1)
            if (ll g = aug(edges[e].t, min(mn, edges[e].w)))
            {
                flo += g;
                edges[e].w -= g;    // FIX: typo--subtract from and add reverse smah
                edges[e^1].w += g;
                //cap[c][edges[e].t] -= g;
                //cap[edges[e].t][c] += g;
                mn -= g;
            }
        if (!mn) break;
        //if (mn) thead[c] = edges[thead[c]].n;
        //else break;
    }
    if (!flo) dep[c] = 0;   // FIX: if you have this along with the if (!mn) break; then it's basically the head optimization
    return flo;
}

int main()
{
    sc(N, M, S, T);
    for (ll i=1; i<=M; ++i)
    {
        ll u, v, w; sc(u, v, w);
        //cap[u][v] = w;
        addEdge(u, v, w);
        addEdge(v, u, 0);
    }

    ll flo=0;
    while (kdep())
    {
        flo += aug(S, 1e9);
    }
    printf("%lld\n", flo);
}

