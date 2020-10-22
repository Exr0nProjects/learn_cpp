/*
 * Problem cstreet (spoj/cstreet)
 * Create time: Thu 22 Oct 2020 @ 16:36 (PDT)
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

void setIO(const std::string &name = "cstreet")
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
inline int sc() { ll x; sc(x); return x; }
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
const int MX = 1e4+11;
const int MXM = 3e5+10;

int T, N, M, P;
struct Edge { int u, v, w; bool operator<(const Edge& o)
    const{ return w < o.w; } } eg[MXM]; int ecnt=0;
//void addEdge(int u, int v, int w)
//{
//    eg[ecnt].t = v;
//    eg[ecnt].w = w;
//    eg[ecnt].n = 0;
//    eg[ecnt].n = hd[u];
//    hd[u] = ecnt++;
//}
int djs[MX], djf[MX];
int df(int n)
{
    if (djf[n] != n)
        djf[n] = df(djf[n]);
    return djf[n];
}
bool merge(int a, int b)
{
    a = df(a);
    b = df(b);
    if (a == b) return 0;
    if (djs[a] < djs[b]) a^=b^=a^=b;
    djs[a] += djs[b];
    djf[b] = a;
    return 1;
}

vector<pair<int, pair<int, int> > > edges;

int main()
{
    sc(T);
    while (T--)
    {
        sc(P, N, M);
        //memset(hd, 0, sizeof hd);
        //ecnt=2;
        //F(i, M) eg[ecnt++] = { sc(), sc(), sc() };
        //sort(eg, eg+M);
        F(i, M)
        {
            int u, v, w; sc(u, v, w);
            edges.pb(mp(w, mp(u, v)));
        }
        sort(edges.begin(), edges.end());
        F(i, N) djs[i] = 1, djf[i] = i;

        int cnt=0, sum=0;
        //for (int i=0; i<M && cnt < N-1; ++i)    // FIX: bounds-- <N-1 not <N because MST has N-1 edges
        //    if (df(eg[i].u) != df(eg[i].v))
        //        //printf("taking %d (%d->%d for %d)\n", i, eg[i].u, eg[i].v, eg[i].w),
        //        ++cnt, sum+=eg[i].w;
        for (auto e : edges)
        {
            if (df(e.s.f) != df(e.s.s))
            {
                merge(e.s.f, e.s.s);
                ++cnt, sum += e.f;
            }
            if (cnt + 1 == N) break;
        }

        printf("%d\n", sum * P);
    }
}

