/*
 * Problem intest (spoj/intest)
 * Create time: Sun 30 Aug 2020 @ 11:26 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>

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
#define _ilb inline bool
_ilb sc(int&a){ll x;bool b=sc(x);a=x;return b;}
_ilb sc(int&a,int&b){return sc(a)&&sc(b);}
_ilb sc(int&a,int&b,int&c){return sc(a,b)&&sc(c);}
_ilb sc(int&a,int&b,int&c,int&d){return sc(a,b)&&sc(c,d);}
_ilb sc(ll&a,ll&b){return sc(a)&&sc(b);}
_ilb sc(ll&a,ll&b,ll&c){return sc(a,b)&&sc(c);}
_ilb sc(ll&a,ll&b,ll&c,ll&d){return sc(a,b)&&sc(c,d);}

using namespace std;
const int MX = 1024;

int N, M, dist[MX][MX];
int u[MX], v[MX], f[MX], c[MX];
//struct Edge { int u=0, v=0, f=0, c=0; } edges[MX<<1]; int head[MX], ecnt=0;

//void addEdge(int u, int v, int f, int c)
//{
//    ++ecnt;
//    edges[ecnt].u = u;
//    edges[ecnt].v = v;
//    edges[ecnt].f = f;
//    edges[ecnt].c = c;
//    edges[ecnt].n = head[u];
//    //edges[++ecnt] = {u, v, head[u], f, c};
//    head[u] = ecnt;
//}

int main()
{
    sc(N, M);
    for (int i=1; i<=M; ++i)
    {
        sc(u[i], v[i], f[i], c[i]);
        //int u, v, f, c;
        //sc(u, v, c, f);
        //if (f > 1000) fprintf(stderr, "%d\n", *(int*)nullptr);
        //addEdge(u, v, f, c);
        //addEdge(v, u, f, c);
    }

    memset(dist, 0x3f, sizeof dist);
    F(i, MX) dist[1][i] = 0;

    for (int i=1; i<=N; ++i)
        for (int e=1; e<=ecnt; ++e)
            for (int j=0; j<=edges[e].f; ++j)
            {
                dist[edges[e].v][j] = min(dist[edges[e].v][j], dist[edges[e].u][j]+edges[e].c);
            }
    //printf("0\n"); return 0;

    //F(i, N) { F(j, 10) dist[i][j] > 1e6 ? printf("  .") : printf("%3d", dist[i][j]); printf("\n"); }
    dl best = 0;
    for (int i=1; i<=MX; ++i) best = max(best, (dl)i/dist[N][i]);

    printf("%d\n", (int)(best*1e6));

}

