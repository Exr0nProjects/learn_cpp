/*
 * Problem 1 (contests/standard-xjoi/1634/1)
 * Create time: Sun 22 Nov 2020 @ 14:00 (PST)
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
#define gcd(_a, _b) ({auto a=_a;auto\
    b=_b;while(b)(a)%=(b),(a)^=(b)^=(a)^=(b);a;})

using namespace std;
const int MX = 1e5+10;

int N, Q, ans[MX];

//vector<pair<int, pii> > eg; // < weight, < u, v > >
//vector<pair<pii, int> > qs; // < < relevance, node >, index >
pair<int, pii> eg[MX];  // < weight, < u, v > >
pair<pii, int> qs[MX];  // < < relevance, node >, index >

int djs[MX], djf[MX];
int find(int n)
{
    if (djf[n] != n) djf[n] = find(djf[n]);
    return djf[n];
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (djs[a] < djs[b]) swap(a, b);
    djs[a] += djs[b];
    djf[b] = a;
}

int main()
{
    sc(N, Q);
    //eg.reserve(N);
    //qs.reserve(Q);
    for (int i=1; i<N; ++i)
    {
        int u, v, w; sc(u, v, w);
        //eg.pb(mp(w, mp(u, v)));
        eg[i] = mp(w, mp(u, v));
    }
    for (int i=1; i<=Q; ++i)
    {
        int k, v; sc(k, v);
        //qs.pb(mp(mp(k, v), i));
        qs[i] = mp(mp(k, v), i);
    }

    sort(eg+1, eg+N, greater<pair<int, pii> >());
    sort(qs+1, qs+Q+1, greater<pair<pii, int> >());
    //for (int i=1; i<N; ++i) printf("%d (%d..%d)\n", eg[i].f, eg[i].s.f, eg[i].s.s);
    //for (int i=1; i<=Q; ++i) printf("(%d  %d) %d\n", qs[i].f.f, qs[i].f.s, qs[i].s);
    //for (auto p : eg) printf("%d (%d..%d)\n", p.f, p.s.f, p.s.s);
    //for (auto p : qs) printf("(%d  %d) %d\n", p.f.f, p.f.s, p.s);

    for (int i=0; i<=N; ++i) djs[i] = 1, djf[i] = i;
    //printf("djs inited!\n");
    int ei=1, qi=1;
    while (1)
    {
        //printf("ei %3d      (%2d %2d %2d)   qi %3d     (%2d %2d %2d)\n", ei, eg[ei].f, eg[ei].s.f, eg[ei].s.s, qi, qs[qi].f.f, qs[qi].f.s, qs[qi].s);
        for (; qi<=Q && qs[qi].f.f > eg[ei].f; ++qi)
            //printf("    qi %2d     ans[%2d for %2d] = %d\n", qi, qs[qi].f.s, qs[qi].f.f, djs[find(qs[qi].f.s)]),
            ans[qs[qi].s] = djs[find(qs[qi].f.s)]-1;
        for (; ei<N && eg[ei].f >= qs[qi].f.f; ++ei)
            //printf("    ei %2d     merge %2d %2d\n", qi, eg[ei].s.f, eg[ei].s.s),
            merge(eg[ei].s.f, eg[ei].s.s);
        if (qi > Q || ei == N) break;
    }
    for (; qi <= Q; ++qi) ans[qs[qi].s] = djs[find(qs[qi].f.s)]-1;
    for (int i=1; i<=Q; ++i) printf("%d\n", ans[i]);
}

