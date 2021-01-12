/*
 * Problem akbar (spoj/akbar)
 * Create time: Mon 11 Jan 2021 @ 16:13 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <cstdio>
#include <cstring>
#define ll long long
#define db(...) fprintf(stdout, __VA_ARGS__)
using namespace std;

const ll MX = 1e6+10;
const ll MXE = 1e7+10;

ll T, N, M, S;
ll dist[MX], ans=0;

struct Edge { ll t, n; } eg[MXE]; ll hd[MX], ecnt=2;
void addEdge(ll u=0, ll v=0)
{
    if (!u) scanf("%lld%lld", &u, &v), addEdge(v, u);
    eg[ecnt] = { v, hd[u] }; hd[u] = ecnt++;
}

ll q[MX], ql=1, qr=0;
void bfs()
{
    ll src, len;
    dist[src] = len+1;
    scanf("%lld%lld", &src, &len);
    for (q[++qr] = src; ql-1 != qr; ++ql%=MX)
    {
        if (dist[q[ql]] == 1) return;
        ++ans;
        for (int e=hd[q[ql]]; e; e=eg[e].n)
            if (dist[eg[e].t]) ans=-MX;
            else
                dist[eg[e].t] = dist[q[ql]]-1,
                q[++qr%=MX] = eg[e].t;
    }
}

int main()
{
    scanf("%lld", &T);
    for (int i=1; i<=T; ++i)
    {
        scanf("%lld%lld%lld", &N, &M, &S);
        memset(dist, 0, sizeof dist);
        ans = 0;
        for (int i=1; i<=M; ++i) addEdge();
        for (int i=1; i<=S; ++i) bfs();
        if (ans == N) printf("YES\n"); else printf("NO\n");
    }
}

