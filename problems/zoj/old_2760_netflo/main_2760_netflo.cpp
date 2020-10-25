/*
 * Problem 2760_netflo (zoj/2760_netflo)
 * Create time: Sat 26 Sep 2020 @ 18:39 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>

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
const int MX = 111;

int N, U, V, dep[MX], dist[MX], cap[MX][MX];
int pre[MX];
list<pii> hd[MX];
queue<int> was_shortest;

void kdep()
{
    memset(dist, 0x3f, sizeof dist);
    //memset(dep, 0, sizeof dep);
    //dep[U] = 1;
    //priority_queue<pii, deque<pii>, greater<pii> > pq;
    gpq(pair<int CMA pii>) pq;
    pq.push(mp(1, mp(U, 0)));
    while (!pq.empty())
    {
        pair<int, pii> c = pq.top(); pq.pop();
        if (dist[c.s.f] < c.f) continue;
        dist[c.s.f] = c.f;
        dep[c.s.f] = dep[c.s.s] +1;
        if (c.s.f == V)
            was_shortest.push(c.s.s);
        else
            pre[c.s.f] = c.s.s;

        for (auto p : hd[c.s.f])
            if (dist[p.s] > c.f + p.f)
                pq.push(mp(c.f+p.f, mp(p.s, c.s.f)));
    }
}

int aug(int c, int p, int mn, int lay=1)
{
    //F(i, lay) printf("|   "); printf("%3d <- %3d  with %3d %d\n", c, p, mn, cap[p][c]);
    if (!mn || c == V) return cap[p][c] -= mn, mn;
    int flo=0;
    for (int n=1; n<=N; ++n)
    {
        //F(i, lay) printf("|   "); printf("n = %d mn = %d\n", n, mn);
        if (dep[n] -1 == dep[c])
        {
            if (int g = aug(n, c, min(mn, cap[c][n]), lay+1))
            {
                flo += g;
                //F(i, lay) printf("|   "); printf("got %d -> %d\n", g, cap[p][c]);
                cap[p][c] -= g;
                cap[c][p] += g;
                mn = min(mn, cap[p][c]);
            }
        }
    }
    return flo;
}

int main()
{
    while (sc(N))
    {
        F(i, N) F(j, N)
        {
            //if ((int w = sc(), w > 0)) // TODO: how to abuse language?
            int w=sc();
            if (w > 0)
                hd[i].pb(mp(w, j)), cap[i][j] = w;
        }
        sc(U, V); ++U, ++V;


        kdep();
        memset(cap, 0, sizeof cap);
        cap[0][U] = 1e9;    // FIX: logic--use U after it gets inputted  AND after cap memsetted smah

        // reconstruct paths
        while (!was_shortest.empty())
        {
            int c = was_shortest.front();
            was_shortest.pop();
            cap[c][V] = 1;
            while (c != U)
            {
                if (cap[pre[c]][c]) break;  // TODO: why this inf loop
                cap[pre[c]][c] = 1,
            //    //dep[pre[c]] = dep[c]-1,
                c = pre[c];
            }
        }

        //F(i, N) { F(j, N) printf(" %c", cap[i][j] ? 'X' : '.'); printf("\n"); }

        int sum = 0;
        while (sum - (sum += aug(U, 0, 1e9)));
        printf("%d\n", sum);
        //printf("%d\n", aug(U, 0, 1e9));
        //printf("9\n");
    }
}

