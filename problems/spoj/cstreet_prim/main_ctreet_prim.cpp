/*
 * Problem cstreet_prim (spoj/cstreet_prim)
 * Create time: Mon 02 Nov 2020 @ 11:39 (PST)
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

void setIO(const std::string &name = "ctreet_prim")
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
const int MX = 1101;
const int MXE = 3e5+10;

struct Edge { int t, w, n; } eg[MXE]; int hd[MX], ecnt=2;
int T, P, N, M;
bool vis[MX];

void addEdge()
{
    int a=sc(), b=sc(), w=sc()*P;
    eg[ecnt].t = b;
    eg[ecnt].w = w;
    eg[ecnt].n = hd[a];
    hd[a] = ecnt++;
    // FIX: two way streets
    eg[ecnt].t = a;
    eg[ecnt].w = w;
    eg[ecnt].n = hd[b];
    hd[b] = ecnt++;
}

int main()
{
    sc(T);
    while (T--)
    {
        sc(P, N, M);
        memset(vis, 0, sizeof vis);
        memset(hd, 0, sizeof hd);
        ecnt=2;
        while (M--) addEdge();

        gpq(pii) pq;
        pq.push(mp(0, 1));
        int tot=0;
        while (!pq.empty())
        {
            pii c = pq.top(); pq.pop();
            //printf("cur %d w/ %d\n", c.s, c.f);
            if (vis[c.s]) continue;
            vis[c.s] = 1;
            //printf("    seems legit\n");
            tot += c.f;
            for (int e=hd[c.s]; e; e=eg[e].n)
                if (!vis[eg[e].t])
                     pq.push(mp(eg[e].w, eg[e].t));
        }
        printf("%d\n", tot);
    }
}

