/*
 * Problem 1_brute (contests/standard-xjoi/1664/1_brute)
 * Create time: Sun 29 Nov 2020 @ 12:30 (PST)
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

void setIO(const std::string &name = "1_brute")
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

int N, M, w[MX], ans[MX];
int TODOmaxdeg = 0;
//int cnt[MX][MX];   // cnt[node][time]
int dep[MX], bl[20][MX];
struct Edge { int t, n; } eg[MX<<2]; int hd[MX], ecnt=2;
void addEdge(int u, int v, bool b=1)
{
    eg[ecnt] = {v, hd[u]};
    hd[u] = ecnt++;
    if (b) addEdge(v, u, 0);
}

void kdep(int c, int p=1, int d=1)
{
    dep[c] = d;
    bl[0][c] = p;
    int TODOtmpdeg = 0;
    for (int e=hd[c]; e; e=eg[e].n, ++TODOtmpdeg)
        if (eg[e].t != p) kdep(eg[e].t, c, d+1);
    TODOmaxdeg = max(TODOmaxdeg, TODOtmpdeg);
}

int lca(int u, int v)
{
    if (dep[u] > dep[v]) swap(u, v); // u is higher
    for (int j=20; j--;)
        if (dep[bl[j][v]] >= dep[u])
            v = bl[j][v];
    if (u == v) return u;
    for (int j=20; j--;)
        if (bl[j][u] != bl[j][v])
            u = bl[j][u], v = bl[j][v];
    //printf("%d, %d\n", u, v);
    return bl[0][u];
}

int main()
{
    sc(N, M);
    for (int i=1; i<N; ++i)
        addEdge(sc(), sc());

    int rt=1;
    // if we probably cant brute force it, assume its a chain I guess?
    if (N > 1e3) for (int i=1; i<=N; ++i)
        if (!eg[hd[i]].n) { rt = i; break; }

    kdep(rt);
    if (TODOmaxdeg <= 2)    // if its a chain
    {

    } else {    // use tle method
    for (int j=1; j<20; ++j)
        for (int i=1; i<=N; ++i)
            bl[j][i] = bl[j-1][bl[j-1][i]];
    //for (int i=1; i<=N; ++i) printf("%3d", i); printf("\n");
    //for (int i=1; i<=N; ++i) printf("%3d", dep[i]); printf("\n");
    //for (int j=0; j<20; ++j) { for (int i=1; i<=N; ++i) printf("%3d", bl[j][i]); printf("\n"); }

    //int u, v; while (sc(u, v)) printf("-> %d\n", lca(u, v)); // test LCA
    for (int i=1; i<=N; ++i) sc(w[i]);
    for (int i=1; i<=M; ++i)
    {
        int u, v; sc(u, v);
        int l = lca(u, v), d=dep[u]+dep[v]-2*dep[l];
        //printf("%d %d\n", u, v);
        ans[l] += (w[l] == dep[u]-dep[l]);
        for (int t=0; u!=l; u=bl[0][u], ++t)
        {
            //printf("/\\ %d @ %d\n", u, t);
            if (w[u] == t) ++ans[u];
        }
        for (int t=d; v!=l; v=bl[0][v], --t)
        {
            //printf("\\/ %d @ %d\n", v, t);
            if (w[v] == t) ++ans[v];
        }
        //for (int i=1; i<=N; ++i) printf("%d ", ans[i]); printf("\n");
    }
    }
    for (int i=1; i<=N; ++i) printf("%d ", ans[i]); printf("\n");
}

