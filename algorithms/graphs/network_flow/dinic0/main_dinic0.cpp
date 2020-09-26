/*
 * dinic0 (../algorithms/graphs/network_flow/dinic0)
 * Create time: Sat 26 Sep 2020 @ 12:44 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>

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

void setIO(const std::string &name = "dinic0")
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
const int MX = 101;
//const int MXE = 1000;
//struct Edge { int u, v, n; } eg[MX]; int hd[MX], ecnt=0;

int N, U, V, dep[MX], dist[MX][MX];

bool kdep()
{
    queue<pii> q;
    q.push(mp(0, U));
    while (!q.empty())
    {
        pii c = q.front(); q.pop();
        printf("    c = %d %d\n", c.f, c.s);
        dep[c.s] = c.f;
        if (c.s == V) return 1;
        for (int i=1; i<=N; ++i)
            if (dist[c.s][i])
                q.push(mp(c.f+1, i));
    }
    return 0;
}

int aug(int c, int p, int mn, int lay=0)
{
    F(i, lay) printf("%2d <- %2d for %2d\n", c, p, mn);
    if (!mn || c == V) return mn;
    int flo = 0;
    for (int i=1; i<=N; ++i) if (dep[c]+1 == dep[i])
        if (int g = aug(i, c, min(mn, dist[c][i])))
        {
            flo += g;
            dist[p][c] -= g;
            dist[c][p] += g;
            mn = min(mn, dist[p][c]);
        }
    return flo;
}

int main()
{
    sc(N, U, V);
    F(i, N) F(j, N) sc(dist[i][j]);

    int sum=0;
    while (kdep())
    {
        sum += aug(U, 0, 1e9);
        F(i, N) { F(j, N) printf("%3d", dist[i][j]); printf("\n"); }
        break;
    }
    printf("%d\n", sum);
}

