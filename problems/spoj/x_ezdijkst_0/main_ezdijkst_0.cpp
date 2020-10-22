/*
 * Problem ezdijkst_0 (spoj/ezdijkst_0)
 * Create time: Wed 21 Oct 2020 @ 18:55 (PDT)
 * Accept time: [!meta:end!]
 * Dijkstra
 */

#include <set>
#include <list>
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

void setIO(const std::string &name = "ezdijkst_0")
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
const int MX = 1e4+11;

ll T, N, M, A, B, dist[MX];
struct Edge { int t, w, n; } eg[MX*MX]; ll hd[MX], ecnt=2;
void addEdge(ll u, ll v, ll w)
{
    eg[ecnt].n = 0; // TODO-learn: why do I need this line to clear adjlist?
    eg[ecnt].t = v;
    eg[ecnt].w = w;
    eg[ecnt].n = hd[u];
    hd[u] = ecnt++;
}

int main()
{
    sc(T); while (T--)
    {
        sc(N, M);
        ecnt = 2;   // FIX: clears--clear edgelist
        memset(hd, 0, sizeof hd);   // FIX: clears--clear edgelist head array
        while (M--) addEdge(sc(), sc(), sc());
        sc(A, B);

        memset(dist, 0x3f, sizeof dist);
        gpq(pair<ll CMA ll>) pq;
        pq.push(mp(0, A));
        while (!pq.empty())
        {
            pii c = pq.top(); pq.pop();
            if (dist[c.s] < c.f) continue;
            dist[c.s] = c.f;
            if (c.s == B) break;

            for (ll e=hd[c.s]; e; e=eg[e].n)
                if (dist[eg[e].t] > c.f + eg[e].w)
                    pq.push(mp(c.f + eg[e].w, eg[e].t));    // FIX: typo--c.f+w not c.s+w
        }
        if (dist[B] > 2e8) printf("NO\n");
        else printf("%lld\n", dist[B]);
    }
}

