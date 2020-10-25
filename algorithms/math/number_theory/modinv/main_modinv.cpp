/*
 * Problem modinv (../algorithms/math/number_theory/modinv)
 * Create time: Sat 24 Oct 2020 @ 18:10 (PDT)
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

void setIO(const std::string &name = "modinv")
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

ll N, P;
//int pri[MX>>3], phi[MX], pcnt=0;
//bool sev[MX];
//
//void ksev()
//{
//    for (int i=2; i<=N; ++i)
//    {
//        if (!sev[i]) pri[pcnt++] = i, phi[i] = i-1;
//        for (int j=0; i*pri[j] < N; ++i)
//        {
//            sev[i*pri[j]] = 1;
//            phi[i*pri[j]] = phi[i] * phi[pri[j]];
//            if (i % pri[j] == 0)
//            {
//                phi[i*pri[j]] = phi[i] * pri[j];
//                break;
//            }
//        }
//    }
//}

ll kpow(ll b, ll e)
{
    ll ans=1;
    for (; e; e>>=1)
    {
        if (e&1) (ans *= b) %= P;
        (b *= b) %= P;
    }
    return ans % P;
}

int main()
{
    sc(N, P);
    //ksev();
    for (int i=1; i<=N; ++i)
        printf("%lld\n", kpow(i, P-2));
}

