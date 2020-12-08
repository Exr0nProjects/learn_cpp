/*
 * Problem cycle_finding (cses/graph/cycle_finding)
 * Create time: Mon 07 Dec 2020 @ 21:36 (PST)
 * Accept time: [!meta:end!]
 *
 */

#define nt long long
#include <set>
#include <map>
#include <tuple>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>

#define dl double

#define gpq(...) priority_queue<__VA_ARGS__, deque<__VA_ARGS__>, greater<__VA_ARGS__> >
#define pb push_back
#define pii pair<nt, nt>
#define mp make_pair
#define f first
#define s second
#define mt make_tuple
#define un(...) nt __VA_ARGS__; tie(__VA_ARGS__)
#define lb(x) ((x)&-(x))

#define F(i,b) for (nt i=1; i<=(b); ++i)
#define R(i,b) for (nt i=(b); i>=1; --i)
#define N(e,c) for (nt e=hd[c]; e; e=eg[e].n)
#define TN(e,c,p) N(e,c) if (eg[e].t != p)

inline nt pow(nt b, nt e, nt m)
{
    nt ret=1;
    for (; e; e>>=1, (b*=b)%=m)
        if (e&1) (ret *= b)%=m;
    return ret;
}

void setIO(const std::string &name = "cycle_finding")
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen((name + ".in").c_str(), "r") != 0)
        freopen((name + ".in").c_str(), "r", stdin),
        freopen((name + ".out").c_str(), "w+", stdout);
}
#define _gc getchar_unlocked
inline bool sc(nt &n)
{
    nt neg = 1;
    register char c;
    do c = _gc(); while (isspace(c));
    if (c == '-') neg = -1, c = _gc();
    for (n=0; c >= '0' && c <= '9'; c=_gc())
        (n *= 10) += (c-'0');
    n *= neg;
    return c != EOF;
}
inline nt sc() { nt x; sc(x); return x; }
#define _ilb inline bool
_ilb sc(nt&a,nt&b){return sc(a)&&sc(b);}
_ilb sc(nt&a,nt&b,nt&c){return sc(a,b)&&sc(c);}
_ilb sc(nt&a,nt&b,nt&c,nt&d){return sc(a,b)&&sc(c,d);}
nt gcd(nt a, nt b) { while (b^=a^=b^=a%=b); return a; }

using namespace std;
const nt MX = 2511;

nt N, M;
nt dist[MX], vis[MX], pre[MX];

struct Edge { nt t, w, n; } eg[MX<<3]; nt hd[MX], ecnt=2;
void addEdge(nt u=0, nt v=0, nt w=0, bool b=1)
{
    if (!u) sc(u, v, w);
    //printf("got %d %d %d\n", u, v, w);
    eg[ecnt] = { v, w, hd[u] };
    hd[u] = ecnt++;
    //if (b) addEdge(v, u, w, 0);
}

nt q[MX<<3], ql=1, qr=0;
nt nono = 0, ans[MX], acnt=0;

//bool dfs(int c, int og, int cost)
//{
//    //printf("at %d looking for %d\n", c, og);
//    if (c == og && cost < 0) return 1;
//    if (vis[c] < 0) return 0; vis[c] = -1;
//    N(e, c) if (dfs(eg[e].t, og, cost + eg[e].w))
//    { ans[acnt++] = c; return 1; }
//    return 0;
//}

nt maxvis = 0;

int main()
{
    sc(N, M);
    F(i, M) addEdge();

    F(i, N) q[++qr] = i; // make sure to push everything in case it is not connected

    for (; ql-1 != qr; ++ql%=MX)
    {
        maxvis = max(maxvis, vis[q[ql]]+1);
        if (++vis[q[ql]] > N) { nono = q[ql]; break; }
        else N(e, q[ql]) if (dist[eg[e].t] > dist[q[ql]] + eg[e].w)
            dist[q[++qr%=MX] = eg[e].t] = dist[q[ql]] + eg[e].w, pre[eg[e].t] = q[ql];
    }

    printf("maxvis %d\n", maxvis);

    if (!nono) { printf("NO\n"); return 0; }
    F(i, N) nono = pre[nono];   // back up N nodes to ensure we are on the cycle
    for (nt c=pre[nono]; c != nono; c=pre[c]) ans[acnt++] = c;

    printf("YES\n%d ", nono);
    while (acnt--) printf("%d ", ans[acnt]);
    printf("%d\n", nono);

    //N(e, nono) dfs(eg[e].t, nono, eg[e].w);
    ////printf("%d\n", acnt);
    ////if (nono) printf("YES\n"), dfs(nono, nono), printf("%d\n", nono);
    ////else printf("NO\n");
}

