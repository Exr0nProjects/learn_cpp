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

int N, Q, a[MX];

int main()
{
    sc(N, Q);
    for (int i=1; i<=N; ++i) sc(a[i]);
    printf("\n\n=========\n\n");

    while (Q--)
    {
        int l, r, x; sc(l, r, x);
        map<int, ll> cnt = {};
        ll ans=0;
        // insert valid numbers
        for (int i=l; i<=r; ++i)
            if (!(a[i]&~x)) ++cnt[a[i]];

        for (auto i=cnt.begin(); i!=cnt.end(); ++i)
        {
            if (i->f == x && i->s >= 3) printf("%3d     <     <           (x %5d)\n", i->f, i->s*(i->s-1)*(i->s-2)), ans += i->s * (i->s-1) * (i->s-2);
            for (auto j=next(i); j!=cnt.end(); ++j)
            {
                //if ((i->f | j->f) == x && i->s >= 2) ans += i->s * (i->s-1) * j->s;
                //if ((i->f | j->f) == x && j->s >= 2) ans += j->s * (j->s-1) * i->s;
                if ((i->f | j->f) == x && i->s >= 2) printf("%3d     <   %3d           (x %5d)\n", i->f, j->f, i->s*(i->s-1)*j->s), ans += i->s * (i->s-1) * j->s;
                if ((i->f | j->f) == x && j->s >= 2) printf("%3d     >   %3d           (x %5d)\n", i->f, j->f, j->s*(j->s-1)*i->s), ans += j->s * (j->s-1) * i->s;
                for (auto k=next(j); k!=cnt.end(); ++k)
                {
                    if ((i->f | j->f | k->f) == x)
                    {
                        printf("%3d   %3d   %3d           (x %5d)\n", i->f, j->f, k->f, i->s*j->s*k->s),
                        ans += i->s * j->s * k->s;
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
}

