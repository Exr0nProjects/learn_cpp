/*
 * Problem high_score_queued (cses/high_score_queued)
 * Create time: Fri 30 Oct 2020 @ 20:41 (PDT)
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
#define pii pair<ll, ll>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb(x) ((x)&-(x))

#define F(i,b) for (ll i=1; i<=(b); ++i)
#define R(i,b) for (ll i=(b); i>=1; --i)
//struct Edge { ll u, v, n; } eg[MX]; ll hd[MX], ecnt=0;

inline ll pow(ll b, ll e, ll m)
{
    ll ret=1;
    for (; e; e>>=1, (b*=b)%=m)
        if (e&1) (ret *= b)%=m;
    return ret;
}

void setIO(const std::string &name = "high_score_queued")
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen((name + ".in").c_str(), "r") != 0)
        freopen((name + ".in").c_str(), "r", stdin),
        freopen((name + ".out").c_str(), "w+", stdout);
}
#define _gc getchar_unlocked
inline bool sc(ll &n)
{
    ll neg = 1;
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
_ilb sc(ll&a,ll&b){return sc(a)&&sc(b);}
_ilb sc(ll&a,ll&b,ll&c){return sc(a,b)&&sc(c);}
_ilb sc(ll&a,ll&b,ll&c,ll&d){return sc(a,b)&&sc(c,d);}
#define gcd(_a, _b) ({auto a=_a;auto\
    b=_b;while(b)(a)%=(b),(a)^=(b)^=(a)^=(b);a;})

using namespace std;
const ll MX = 2511;
const ll MXE = 5100;

struct Edge { ll f, t, w, n; } eg[MXE]; ll hd[MX], ecnt=2;
ll N, M;
bool previs[MX], postvis[MX], ok=0; ll dist[MX], q[MX], ql, qr;

void addEdge()
{
    int a = sc();
    eg[ecnt].f = a;
    eg[ecnt].t = sc();
    eg[ecnt].w = -sc();
    eg[ecnt].n = hd[a];
    hd[a] = ecnt++;
}

//void predfs(ll c)
//{
//    if (previs[c]) return;
//    previs[c] = 1;
//    for (ll e=hd[c]; e; e=eg[e].n)
//        predfs(eg[e].t);
//}
void postdfs(ll c)
{
    //printf("postdfs %d\n", c);
    if (postvis[c]) return;
    postvis[c] = 1;
    if (c == N) { ok=1; return; }
    for (ll e=hd[c]; e; e=eg[e].n)
        postdfs(eg[e].t);
}

int main()
{
    sc(N, M);
    for (int i=1; i<=M; ++i) addEdge();
    //predfs(1);
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    //F(i, N) printf("%d ", previs[i]); printf("\n");

    ql=0, qr=0;
    for (; qr<N; ++qr) q[qr] = qr+1;    // add all nodes to queue, FIX: typo--insert using qr not ql
    for (; ql != qr; ql=(ql+1)%MX) // not \lt because pointers may wrap
    {
        //printf("q[%3d..%3d] = %d\n", ql, qr, q[ql]);
        for (int e=hd[q[ql]]; e; e=eg[e].n)
        {
            //printf("    eg{ %2d %2d %2d %2d }\n", eg[e].f, eg[e].t, eg[e].w, eg[e].n);
            if (dist[eg[e].t] > dist[eg[e].f] + eg[e].w)
                dist[eg[e].t] = dist[eg[e].f] + eg[e].w,
                q[qr++] = eg[e].t, qr %= MX;
        }
    }
    //F(i, N) printf("%20lld", dist[i]); printf("\n");
    for (int i=1; i<=N; ++i) if (dist[i] <= 1e18)
        for (int e=hd[i]; e; e=eg[e].n)
            if (dist[eg[e].t] > dist[eg[e].f] + eg[e].w)
                postdfs(eg[e].t);

    if (ok) printf("-1\n");
    else printf("%lld\n", -dist[N]);
}

