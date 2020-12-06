/*
 * Problem high_score_spfa2 (cses/graph/high_score_spfa2)
 * Create time: Sat 05 Dec 2020 @ 17:25 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <set>
#include <map>
#include <tuple>
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
#define N(e,c) for (int e=hd[c]; e; e=eg[e].n)
#define TN(e,c,p) N(e,c) if (eg[e].t != p)

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
ll gcd(ll a, ll b) { while (b^=a^=b^=a%=b); return a; }

using namespace std;
const int MX = 2511;

struct Edge { ll f, t, w, n; } eg[MX<<2]; ll hd[MX], ecnt=2;
void addEdge()
{
    ll u, v, w; sc(u, v, w);
    eg[ecnt] = { u, v, -w, hd[u] };
    hd[u] = ecnt++;
}
ll N, M;
ll dist[MX], vis[MX], q[MX], ql=1, qr=0;
bool ok=1;

bool report(ll c)
{
    //if (c == q[ql]) printf("report %d\n", c);
    if (c == N) { ok=0; return 0; }
    if (vis[c] < 0) return 1;
    vis[c] = -1;
    N(e, c) if (!report(eg[e].t)) return 0;
    return 1;
}

int main()
{
    sc(N, M);
    for (ll i=1; i<=M; ++i) addEdge();

    memset(dist, 0x3f, sizeof dist); dist[1] = 0;
    q[++qr] = 1;
    for (; ql-1 != qr; (++ql)%=MX)  // FIX: wrap around queue (can have MXE items not just MX)
    {
        //printf("q %d..%d\n", ql, qr);
        if (++vis[q[ql]] > N) if (!report(q[ql])) break; else continue;
        N(e, q[ql]) if (dist[eg[e].t] > dist[q[ql]] + eg[e].w)
            q[(++qr)%=MX] = eg[e].t, dist[eg[e].t] = dist[q[ql]] + eg[e].w;
    }

    if (ok) printf("%lld\n", -dist[N]);
    else printf("-1\n");
}

