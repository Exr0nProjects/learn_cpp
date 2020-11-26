/*
 * Problem 1 (contests/standard-xjoi/1644/1)
 * Create time: Tue 24 Nov 2020 @ 12:30 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <set>
#include <map>
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
const int MX = 1e5+11;

ll N, Q, a[MX], gcnt[256][MX];

int main()
{
    sc(N, Q);
    //for (int i=1; i<=N; ++i) sc(a[i]);
    for (int i=1; i<=N; ++i)    // mioles big brain (directly compute which numbers this can contrib to)
    {
        int x; sc(x);
        for (int j=1; j<256; ++j)
            gcnt[j][i] = gcnt[j][i-1] + !(x&~j);
    }
    //for (int i=1; i<=N; ++i) ++gcnt[a[i]][i];
    //for (int j=1; j<256; ++j)
    //    for (int i=1; i<=N; ++i) gcnt[j][i] += gcnt[j][i-1];
    //printf("\n\n=========\n\n");

    while (Q--)
    {
        int l, r, x; sc(l, r, x);
        ll num = gcnt[x][r] - gcnt[x][l-1];
        printf("%lld\n", num*(num-1)*(num-2)/6);
        //for (int i=1; i<256; ++i)
        //    cnt[i] = gcnt[i][r] - gcnt[i][l-1];
        ////for (int i=1; i<20; ++i) printf("%3d: %3d\n", i, cnt[i]);
        //for (int i=1; i<256; ++i) if (!(i&~x))
        //{
        //    if (i == x && cnt[i] >= 3) ans += cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
        //    for (int j=i+1; j<256; ++j) if (!(j&~x))
        //    {
        //        if ((i|j) == x && cnt[i] >= 2) ans += cnt[i]*(cnt[i]-1)*cnt[j]/2;
        //        if ((i|j) == x && cnt[j] >= 2) ans += cnt[j]*(cnt[j]-1)*cnt[i]/2;
        //        for (int k=j+1; k<256; ++k)
        //            if ((i|j|k) == x) ans += cnt[i]*cnt[j]*cnt[k];
        //    }
        //}
        //printf("%lld\n", ans);
    }
}

