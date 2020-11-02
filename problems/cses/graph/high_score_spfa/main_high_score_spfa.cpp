/*
 * Problem high_score_spfa (cses/graph/high_score_spfa)
 * Create time: Sun 01 Nov 2020 @ 18:04 (PST)
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

void setIO(const std::string &name = "high_score_spfa")
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
#define gcd(_a, _b) ({auto a=_a;auto\
    b=_b;while(b)(a)%=(b),(a)^=(b)^=(a)^=(b);a;})

using namespace std;
const int MX = 3e3+11;
const int MXE = 5e3+11;

struct Edge { ll f, t, w, n; } eg[MXE]; int hd[MX], ecnt=2;
void addEdge()
{
    int a = sc();
    eg[ecnt].f = a;
    eg[ecnt].t = sc();
    eg[ecnt].w = -sc();
    eg[ecnt].n = hd[a];
    //printf("add edge %3d %3d %3d %3d\n", eg[ecnt].f, eg[ecnt].t, eg[ecnt].w, eg[ecnt].n);
    hd[a] = ecnt++;
}
ll N, M, dist[MX], vis[MX], postvis[MX], q[MXE]; // FIX: bounds--SPFA queue needs to be MXE
bool ok=1;

void postdfs(int c)
{
    if (postvis[c]) return;
    postvis[c] = 1;
    if (c == N) { ok=0; return; }
    for (int e=hd[c]; e; e=eg[e].n)
        postdfs(eg[e].t);
}

int main()
{
    sc(N, M);
    for (int i=1; i<=M; ++i) addEdge();

    memset(dist, 0x3f, sizeof dist);    // FIX: init dist to inf smah
    dist[1] = 0; int ql=0, qr=0;
    for (int i=1; i<=N; ++i) q[qr++] = i;

    for (; ql != qr && ++vis[q[ql]] <= N; ql = (ql+1) % MXE)    // FIX: put infloop detection here, not in edge traversal
    {
        //printf("q[%3d.%3d] = %-3d      ", ql, qr, q[ql]); for (int i=1; i<=N; ++i) printf("%20lld", dist[i]); printf("\n");
        for (int e=hd[q[ql]]; e; e=eg[e].n)
        {
            //printf("    %3d - %2d -> %d               ->%d\n", eg[e].f, eg[e].w, eg[e].t, eg[e].n);
            if (dist[eg[e].t] > dist[eg[e].f] + eg[e].w)
            {
                dist[eg[e].t] = dist[eg[e].f] + eg[e].w;
                q[qr] = eg[e].t, qr = (qr+1)%MXE;   // FIX: queue can hold up to MXE things, not just N because it's not deduplicated
            }
        }
    }
    //for (; ql != qr; ql = (ql+1)%MXE)
    for (int i=1; i<=N; ++i) if (dist[i] < 1e18)
    {
        for (int e=hd[q[ql]]; e; e=eg[e].n)
            if (dist[eg[e].t] > dist[eg[e].f] + eg[e].w)
                postdfs(eg[e].t);
    }
    //printf("ok? %d     dist %lld\n", ok, dist[N]-1e18);
    if (ok && dist[N] < 1e18) printf("%lld\n", -dist[N]);
    else printf("-1\n");
}

