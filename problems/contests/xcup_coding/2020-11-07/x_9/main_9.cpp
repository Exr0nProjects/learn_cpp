/*
 * Problem 9 (contests/xcup_coding/2020-11-07/9)
 * Create time: Sat 07 Nov 2020 @ 14:12 (PST)
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

void setIO(const std::string &name = "9")
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
const int MX = 2e4+11;

struct Edge { int t, n; } eg[MX<<2]; int hd[MX], ecnt=2;
int N, sz[MX], dep[MX];
void addEdge(int a=sc(), int b=sc(), bool n=1)
{
    eg[ecnt].t = b;
    eg[ecnt].n = hd[a];
    hd[a] = ecnt++;
    if (n) addEdge(b, a, 0);
}

int ksz(int c, int p=0, int d=2)
{
    int s=1;
    dep[c] = d;
    for (int e=hd[c]; e; e=eg[e].n)
        if (eg[e].t != p)
            s += ksz(eg[e].t, c, d+1);
    sz[c] = s;
    return s;
}

int main()
{
    sc(N);
    for (int i=1; i<N; ++i) addEdge();

    ksz(1);
    //F(i, N) printf("%3d", sz[i]); printf("\n");
    bool has=0;
    F(i, N)
    {
        bool bad = 1;
        for (int e=hd[i]; e; e=eg[e].n)
            if (dep[eg[e].t] > dep[i] && sz[eg[e].t] > N/2) bad=0;

        //printf("i= %d   bad %d, N-sz[i] %d\n", i, bad, N-sz[i]);
        if (bad && N-sz[i] <= N/2) { has=1; printf("%d\n", i); }
    }
    if (!has) printf("NONE\n");
}

