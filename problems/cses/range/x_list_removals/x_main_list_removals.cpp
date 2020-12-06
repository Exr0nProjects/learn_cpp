/*
 * Problem list_removals (cses/range/list_removals)
 * Create time: Sat 05 Dec 2020 @ 23:05 (PST)
 * Accept time: Sat 05 Dec 2020 @ 23:38 (PST)
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

void setIO(const std::string &name = "list_removals")
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

//struct Edge { int t, n; } eg[MX*MX]; int hd[MX], ecnt=2;
using namespace std;
const int MX = 2e5+11;

int N, a[MX], tsum[MX<<2];

void comb(int k, int tl, int tr) { tsum[k] = tsum[k<<1] + tsum[k<<1|1]; }
void update(int q, int v, int k=1, int tl=1, int tr=N)
{
    //printf("update %d, %d at %d(%d..%d)\n", q, v, k, tl, tr);
    //if (q < tl || tr < q) return;
    if (tl == tr) { tsum[k] += v; return; }
    int mid = tl + (tr-tl>>1);
    if (q <= mid) update(q, v, k<<1, tl, mid);
    else update(q, v, k<<1|1, mid+1, tr);
    comb(k, tl, tr);
}
int query(int n, int k=1, int tl=1, int tr=N)
{
    //printf("query %d at %d (%d..%d)\n", n, k, tl, tr);
    if (tl == tr) return tl;
    if (n > tsum[k]) return -1; // FIX: typo--sum of here is tsum[k] not tsum[tr]
    int mid = tl + (tr-tl>>1);
    if (n <= tsum[k<<1]) return query(n, k<<1, tl, mid);    // FIX: typo--tsum of left is k<<1 not mid
    else return query(n-tsum[k<<1], k<<1|1, mid+1, tr);
}

void dump(int k=1, int tl=1, int tr=N)
{
    queue<pair<int, pii> > q; q.push(mp(1, mp(1, N)));
    while (q.size())
    {
        int k, tl, tr; pii temp;
        tie(k, temp) = q.front(); q.pop();
        tie(tl, tr) = temp;
        //if (tr-tl >= 2) printf("|---------------");
        F(i, ((tr-tl)/2)) printf("<---------------");
        printf("%2d (%2d..%2d) %2d  ", k, tl, tr, tsum[k]);
        F(i, ((tr-tl)/2 + (tr-tl)&1) ) printf("--------------->");
        //if (tr-tl >= 2) printf("---------------|");
        int mid = tl + (tr-tl>>1);
        if (tr > tl)
            q.push(mp(k<<1, mp(tl, mid))),
            q.push(mp(k<<1|1, mp(mid+1, tr)));
        if (tr == N) printf("\n");
    }
    //if (tl == 1) printf("\n");
    //F(i, tr-tl) printf("                ");
    //printf("%2d (%2d..%2d) %2d  ", k, tl, tr, tsum[k]);
}

int main()
{
    sc(N);
    F(i, N) sc(a[i]), update(i, 1);
    F(i, N)
    {
        //dump(); printf("\n\n");
        int p = query(sc());
        printf("%d ", a[p]);
        //printf("gotttt %d \n", p);
        update(p, -1);
    }
    printf("\n");
}

