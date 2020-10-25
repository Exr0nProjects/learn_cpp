/*
 * Problem 2760_netflo (zoj/2760_netflo)
 * Create time: Sat 24 Oct 2020 @ 17:07 (PDT)
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

void setIO(const std::string &name = "2760_netflo")
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

int N, M, S, T, dep[MX], cap[MX][MX], dist[MX];
int eg[MX][MX];

void kdist()
{
    typedef pair<int, int> State;
    gpq(State) pq;
    pq.push(mp(1, S));
    while (!pq.empty())
    {
        State cur = pq.top(); pq.pop();
        if (dist[cur.s] < cur.f) continue;
        dist[cur.s] = cur.f;

        if (dist[cur.s] > dist[T]) break;

        for (int i=0; i<N; ++i)
            if (dist[i] >  cur.f + eg[cur.s][i] && ~eg[cur.s][i])
                pq.push(mp(cur.f + eg[cur.s][i], i));
    }
}

bool kdep()
{
    memset(dep, 0, sizeof dep);
    queue<int> q;
    dep[S] = 2;
    q.push(S);
    while (!q.empty())
    {
        int c = q.front(); q.pop();
        //printf("c = %d\n", c);
        //for (int i=0; i<N; ++i) printf("    %d -> %d\n", i, dep[i]);
        if (c == T) return 1;
        for (int i=0; i<N; ++i)
            if (!dep[i] && i != c && cap[c][i])
                dep[i] = dep[c]+1, q.push(i);
    }
    return 0;
}

int aug(int c, int mn)
{
    //printf("at %d w/ %d\n", c, mn);
    if (!mn || c == T) return mn;
    int flo=0;
    for (int i=0; i<N && mn; ++i)
    {
        if (dep[i] == dep[c]+1)
        {
            int g = aug(i, min(mn, cap[c][i]));
            flo += g, mn -= g;
            cap[c][i] -= g, cap[i][c] += g;
        }
    }
    if (!flo) dep[c] = 0;
    return flo;
}

int main()
{
    while (sc(N))
    {
        memset(dist, 0x3f, sizeof dist);
        for (int i=0; i<N; ++i)
            for (int j=0; j<N; ++j)
                scanf("%d", &eg[i][j]);
        sc(S, T);
        //if (S == T) { printf("inf\n"); continue; }
        kdist();
        for (int i=0; i<N; ++i)
            for (int j=0; j<N; ++j)
                if (dist[j] == dist[i] + eg[i][j])
                    cap[i][j] = 1;
        int flo=0;
        while (kdep()) flo += aug(S, 1e9);
        printf("%d\n", flo);
    }
}

