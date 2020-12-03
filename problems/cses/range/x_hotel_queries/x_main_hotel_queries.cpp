/*
 * Problem hotel_queries (cses/range/hotel_queries)
 * Create time: Wed 02 Dec 2020 @ 21:30 (PST)
 * Accept time: Wed 02 Dec 2020 @ 21:48 (PST)
 *  segtree bins
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

void setIO(const std::string &name = "hotel_queries")
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
const int MX = 2e5+11;
int N, M;
ll tmax[MX<<2];

void comb(int k, int tl, int tr)
{ tmax[k] = max(tmax[k<<1], tmax[k<<1|1]); }
void update(int q, ll v, int k=1, int tl=1, int tr=N)
{
    //printf("%d for %d @ %d (%d..%d\n", q, v, k, tl, tr);
    if (q < tl || q > tr) return;
    if (tl == tr) { tmax[k] += v; return; }
    int mid = tl + (tr-tl>>1);
    if (q <= mid) update(q, v, k<<1, tl, mid);
    else update(q, v, k<<1|1, mid+1, tr);
    comb(k, tl, tr);
}
int bins(ll v, int k=1, int tl=1, int tr=N)
{
    //printf("find %d @ %d (%d..%d) has %d (%d %d)\n", v, k, tl, tr, tmax[k], v<tmax[k], tr < tl);
    if (v > tmax[k] || tr < tl) return 0;
    //printf("should have something\n");
    if (tl == tr && tmax[k] >= v) return tl;    // FIX: success condition
    int mid = tl + (tr-tl>>1);
    //printf("    max mid = %d\n", tmax[mid]);
    if (tmax[k<<1] >= v) return bins(v, k<<1, tl, mid); // FIX: k of mid is k<<1 not mid
    else return bins(v, k<<1|1, mid+1, tr);
}

int main()
{
    sc(N, M);
    F(i, N) update(i, sc());
    F(i, M)
    {
        int r; sc(r); int g = bins(r);
        //printf("got %d\n", g);
        if (g) update(g, -r);
        printf("%d ", g);
    }
    printf("\n");
}

