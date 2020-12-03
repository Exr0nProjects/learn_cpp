/*
 * Problem range_minimum_queries_ii (cses/range/range_minimum_queries_ii)
 * Create time: Wed 02 Dec 2020 @ 19:42 (PST)
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

void setIO(const std::string &name = "range_minimum_queries_ii")
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
int N, Q;
int tmin[MX], sett[MX], D;

void push(int &k, int tl, int tr)
{
    sett[k<<1] = sett[k<<1|1] = sett[k];
    tmin[k<<1] = tmin[k<<1|1] = sett[k];
    sett[k] = 0;
}
void apply(int &k, int setv, int tl, int tr)
{
    tmin[k] = sett[k] = setv;
}
void comb(int &k, int tl, int tr)
{ tmin[k] = min(tmin[k<<1], tmin[k<<1|1]); }

void update(int q, int setv, int k=1, int tl=1, int tr=N)
{
    if (q < tl || tr < q) return;
    if (tl == tr) apply(k, setv, tl, tr);
    int mid = tl + (tr-tl>>1);
    if (q <= mid) update(q, setv, k<<1, tl, mid);
    else update(q, setv, k<<1|1, mid+1, tr);
    comb(k, tl, tr);
}
int query(int ql, int qr, int k=1, int tl=1, int tr=N)
{
    if (qr < tl || tr < ql) return 1e9;
    if (ql <= tl && tr <= qr) return tmin[k];
    int mid = tl + (tr-tl>>1);
    return min(query(ql, qr, k<<1, tl, mid),
        query(ql, qr, k<<1|1, mid+1, tr));
}

int main()
{
    sc(N, Q);
    F(i, N) update(i, sc());
    F(i, Q)
    {
        int t, a, b; sc(t, a, b);
        if (t == 1) update(a, b);
        else printf("%d\n", query(a, b));
    }
}

