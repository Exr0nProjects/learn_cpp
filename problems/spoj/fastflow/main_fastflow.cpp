/*
 * Problem fastflow (spoj/fastflow)
 * Create time: Tue 06 Oct 2020 @ 17:06 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>

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

void setIO(const std::string &name = "fastflow")
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
const int MX = 5011;
const int MXM = 3e4+10;

struct Edge { ll f, t, w, n; } eg[MXM]; int hd[MX], ecnt=2;
void addEdge(int u, int v, ll w, bool b=1)
{
    eg[ecnt] = { u, v, w, hd[u] };
    hd[u] = ecnt++;
    if (b) addEdge(v, u, w, 0);
}
int N, M;
int dep[MX];

bool bfs()
{
    int q[MX], ql=1, qr=0;
    dep[1] = 1, q[++qr] = 1;
    for (ql <= qr, ++ql)
    {
        if (q[ql] == N) return 1;
        for (int e=hd[q[ql]]; e; e=eg[e].n) if (eg[e].w > 0)
            dep[eg[e].t] = dep[q[ql]]+1, q[++qr] = eg[e].t;
    }
    return 0;
}

ll kflo(int c, int mn)
{
    if (c == N || !mn) return mn;
    ll flo=0;
    for (int e=hd[c]; e && mn; e=eg[e].n)
        if (dep[eg[e].t] == dep[c]+1)
        {
            int g = flo(eg[e].n, min(mn, eg[e].w));
            eg[e].w -= g;
            eg[e^1].w += g;
            flo += g;
            mn -= g; // ????
        }
    if (!flo) dep[c] = 0;
    return flo;
}

int main()
{
    //setIO();
    sc(N, M);
    F(i, M) addEdge(sc(), sc(), sc());
    ll ans = 0;
    while (bfs())
        ans += kflo(1);
    printf("%lld\n", ans);
}

