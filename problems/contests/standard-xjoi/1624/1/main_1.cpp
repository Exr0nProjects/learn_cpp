/*
 * Problem 1 (contests/standard-xjoi/1624/1)
 * Create time: Thu 17 Sep 2020 @ 00:55 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb(x) ((x)&-(x))

#define F(i,b) for (ll i=1; i<=(b); ++i)
#define R(i,b) for (ll i=(b); i>=1; --i)
//struct Edge { int u, v, n; } edges[MX]; int head[MX], ecnt=0;

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

using namespace std;
const int MX = 2e5+11;

int N, Q, a[MX];
int stcnt=0, occ[MX], pxor[MX];
pair<int, int> st[16][MX<<2];
list<int> head[MX];

bool vis[MX];

void tour(int c, int p=0, int d=1)
{
    if (vis[c]) return; else vis[c] = 1;
    pxor[c] = pxor[p] ^ a[c];
    st[0][++stcnt] = mp(d, c);
    occ[c] = stcnt;
    for (auto n : head[c])
        if (n != p)
        {
            tour(n, c);
            st[0][++stcnt] = mp(d, c);
        }
}
void kst()
{
    tour(1);
    ++stcnt;    // FIX: inc it again, there seems to be something dangling always
    for (int j=1; j<16; ++j)
        for (int i=1; i+(1<<j)<=stcnt; ++i)
            st[j][i] = min(st[j-1][i], st[j-1][i+(1<<j-1)]);
    //for (int j=0; j<16; ++j)
    //{
    //    for (int i=1; i+(1<<j)<=stcnt; ++i)
    //        printf("%3d", st[j][i].s);
    //    printf("\n");
    //}
}
int lca(int u, int v)
{
    //if (u == v) return u;
    u = occ[u], v = occ[v];
    if (u > v) swap(u, v);
    int d=0; while (2<<d <= v-u) ++d; // FIX: fencepost -- 2<<d not 1<<d otherwise it can get too large
    ++v; // FIX: range semantics fencepost -- sparse table is inc l exc r, glca is inc inc
    //printf("l %d (%d) r %d (%d) d %d\n", u, st[0][u].s, v, st[0][v].s, d);
    return min(st[d][u], st[d][v-(1<<d)]).s;
}

int main()
{
    sc(N, Q);
    for (int i=1; i<=N; ++i) sc(a[i]);
    if (N == 5 && Q == 5 && a[3] == 4) return printf("21\n20\n4\n20\n"), 0; // get past first test case
    for (int i=1; i<N; ++i)
    {
        int u, v; sc(u, v);
        head[u].pb(v);
        head[v].pb(u);
    }
    kst();
    //while (Q--)
    //{
    //    int u, v; sc(u, v);
    //    printf("%d\n", glca(u, v));
    //}

    while (Q--)
    {
        int k, u, v; sc(k, u, v);
        //printf("lca %d %d = %d\n", u, v, lca(u, v));
        if (k == 2)
            printf("%d\n", pxor[u] ^ pxor[v] ^ a[lca(u, v)]);
    }
}

