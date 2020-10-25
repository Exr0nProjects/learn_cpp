/*
 * Problem lca_0 (spoj/lca_0)
 * Create time: Sun 25 Oct 2020 @ 10:53 (PDT)
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

void setIO(const std::string &name = "lca_0")
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
const int MX = 1e3+11;

int T, N, Q, root, dep[MX], par[MX][16];

vector<int> hd[MX];

void kdep(int c, int d=1)
{
    dep[c] = d;
    for (int n : hd[c])
        kdep(n, d+1);
}

void kpar()
{
    for (int j=1; j<16; ++j)
        for (int i=1; i<=N; ++i)
            par[i][j] = par[par[i][j-1]][j-1];
}

int main()
{
    sc(T);
    while (T--)
    {
        sc(N);
        memset(dep, 0, sizeof dep);
        memset(par, 0, sizeof par);
        for (int i=1; i<=N; ++i)
        {
            int c = sc(), x;
            hd[i].reserve(c);
            while (c--) x=sc(), hd[i].pb(x), par[x][0] = i;
        }
        for (int i=1; i<=N; ++i) if (!par[i][0]) root = i;
        par[root][0] = root;
        kdep(root);
        kpar();
        sc(Q); F(i, Q) sc(), sc();

        for (int j=0; j<16; ++j) { for (int i=1; i<=N; ++i) printf("%3d", par[i][j]); printf("\n"); }
    }

}

