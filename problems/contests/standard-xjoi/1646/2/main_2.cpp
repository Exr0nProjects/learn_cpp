/*
 * Problem 2 (contests/standard-xjoi/1646/2)
 * Create time: Wed 25 Nov 2020 @ 11:54 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <set>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>


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

inline ll pow(ll b, ll e, ll m)
{
    ll ret=1;
    for (; e; e>>=1, (b*=b)%=m)
        if (e&1) (ret *= b)%=m;
    return ret;
}

void setIO(const std::string &name = "2")
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
ll gcd(ll a, ll b) { while (b^=a^=b^=a%=b); return a; }

using namespace std;
const int MX = 1e5+11;

struct Edge { int v, w, n; } eg[MX<<2]; int hd[MX], ecnt=2;
void addEdge(int u, int v, int w);
{
    eg[ecnt].v = v;
    eg[ecnt].w = w;
    eg[ecnt].n = hd[u];
    hd[u] = ecnt++;
}

int N, M, K, weird[MX];
int dist[MX], src[MX];

int main()
{
    sc(N, M, K);
    for (int i=0; i<M; ++i)
    {
        int u, v, w; sc(u, v, w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    gpq(pair<int CMA pii>) pq;
    for (int i=1; i<=K; ++i)
        sc(weird[i]), src[i] = i,
        pq.push(mp(0, mp(i, i)));
    while (!pq.empty())
    {
        pair<int, pii> cur = pq.top(); pq.pop();
        if (dist[cur.s.f] < cur.f) continue;
        dist[cur.s.f] = cur.f;
        src[cur.s.f] = src[cur.s.s];
        for (int e=hd[c]; e; e=eg[e].n)
            if (dist[eg[e].t] < eg[e].w + cur.f)
                dist[eg[e].t] = eg[e].w + cur.f,
                pq.push(mp(eg[e].w + cur.f, mp(eg[e].t, cur.s.f)));
    }
}

