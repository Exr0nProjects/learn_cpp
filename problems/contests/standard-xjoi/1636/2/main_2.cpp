/*
 * Problem 2 (contests/standard-xjoi/1636/2)
 * Create time: Mon 23 Nov 2020 @ 11:48 (PST)
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

void setIO(const std::string &name = "2")
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
const ll MX = 1e5+11;
const ll mod = 1e9+7;

struct Edge { int t, n; } eg[MX<<1]; int hd[MX], ecnt=2;
void addEdge(int u, int v, int b=1)
{
    eg[ecnt].t = v;
    eg[ecnt].n = hd[u];
    hd[u] = ecnt++;
    if (b) addEdge(v, u, 0);
}
ll N, K, dp[MX][4], paint[MX];

ll op(int c, int x, int p=0, int d=0)
{
    //for (int _=d; _--;) printf("    "); printf("%d %d", c, x);
    ll &ret = dp[c][x]; if (ret) return ret;
    //ll &ret = dp[c][x]; if (ret) { printf(" => %d\n", ret); return ret; }
    if (paint[c]) if (paint[c] == x) return 0; else
    //if (paint[c]) if (paint[c] == x) { printf(" => 0\n"); return 0; } else
    {
        //printf("\n");
        ret = 1;
        for (int e=hd[c]; e; e=eg[e].n) if (eg[e].t != p)
            (ret *= op(eg[e].t, paint[c], c, d+1)) %= mod;
    }
    else
    {
        if (!eg[hd[c]].n) return 2;
        //if (!eg[hd[c]].n) { printf(" => 2\n"); return 2; } else printf("\n");
        for (int y=1; y<=3; ++y) if (y != x)
        {
            ll tmp = 1;
            for (int e=hd[c]; e; e=eg[e].n) if (eg[e].t != p)
                (tmp *= op(eg[e].t, y, c, d+1)) %= mod;
            //for (int _=d; _--;) printf("    "); printf("color %d -> %d\n", y, tmp);
            ret += tmp;
        }
    }
    //for (int _=d; _--;) printf("    "); printf("%d %d => %d\n", c, x, ret);
    return ret%mod;
    //for (int _=d; _--;) printf("    "); printf("%d %d", c, x);
    ////if (paint[c] && paint[c] != x) return 0;
    //if (paint[c] && paint[c] != x) { printf(" => 0\n"); return 0; }
    ////if (!eg[hd[c]].n) return 1;
    //if (!eg[hd[c]].n) { printf(" => 1\n"); return 1; } printf("\n");
    //ll &ret = dp[c][x]; if (ret) return ret;
    //for (int y=1; y<=3; ++y) if (y != x)
    //{
    //    for (int e=hd[c]; e; e=eg[e].n) if (eg[e].t != p)
    //    {
    //        //if (paint[eg[e].t] == x) return 0;
    //        //if (paint[eg[e].t] == x) { for (int _=d; _--;) printf("    "); printf("%d %d !> %d\n", c, x, 0); return 0; }
    //        (ret += op(eg[e].t, y, c, d+1)) %= mod;
    //    }
    //}
    //for (int _=d; _--;) printf("    "); printf("%d %d => %d\n", c, x, ret);
    //return ret;
}

int main()
{
    sc(N, K);
    for (int i=1; i<N; ++i)
    {
        int u, v; sc(u, v);
        addEdge(u, v);
    }
    int v; while (K--) sc(v), paint[v] = sc();

    printf("%lld\n", op(1, 0)%mod);
}

