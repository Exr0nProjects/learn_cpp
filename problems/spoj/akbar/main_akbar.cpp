/*
 * Problem akbar (spoj/akbar)
 * Create time: Mon 11 Jan 2021 @ 16:13 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#define ll long long
#define db(...) fprintf(stdout, __VA_ARGS__)
#define mp make_pair
using namespace std;

const ll MX = 2e6+10;
const ll MXE = 2e7+10;

ll T, N, M, S;
ll dist[MX], ans=0;

struct Edge { ll t, n; } eg[MXE]; ll hd[MX], ecnt=2;
void addEdge(ll u=0, ll v=0)
{
    //printf("addEdge %d %d\n", u, v);
    if (!u) scanf("%lld%lld", &u, &v), addEdge(v, u);
    eg[ecnt] = { v, hd[u] }; hd[u] = ecnt++;
}

ll q[MX], ql=1, qr=0;
//void bfs()
//{
//    ll src, len;
//    ql=1, qr=0;
//    memset(q, 0, sizeof q);
//    scanf("%lld%lld", &src, &len);
//    //db("src %d len %d, dist set to %d\n", src, len, dist[src]);
//    if (dist[src]) return ans = -MX, void(); else dist[src] = len+1;
//    for (q[++qr] = src; ql-1 != qr; ++ql%=MX)
//    {
//        //db("queue %d..%d is %d (dist %d)\n", ql, qr, q[ql], dist[q[ql]]);
//        ++ans;
//        if (dist[q[ql]] == 1) continue; // FIX: typo continue not return
//        for (int e=hd[q[ql]]; e; e=eg[e].n)
//            if (!~dist[eg[e].t]) ans=-MX;
//            else if (!dist[eg[e].t])
//                //db("going %d->%d\n", q[ql], eg[e].t),
//                dist[eg[e].t] = dist[q[ql]]-1,
//                q[++qr%=MX] = eg[e].t;
//    }
//    for (int i=1; i<=qr; ++i)
//        //db("    setting %d\n", i),
//        dist[q[i]] = -1;
//}
void bfs()
{
    ll s, d; scanf("%lld%lld", &s, &d);
    queue<pair<int, int> > q;
    vector<int> q2;
    q.push(mp(s, d));
    while (q.size())
    {
        ll c, d; tie(c, d) = q.front(); q.pop();
        if (dist[c] == -1) ans = -MX;
        if (dist[c]) continue;
        dist[c] = d;
        ++ans; q2.push_back(c);
        if (d > 0)
        for (int e=hd[c]; e; e=eg[e].n)
            q.push(mp(eg[e].t, d+1));
    }
    for (auto v : q2) dist[v] = -1;
}

int main()
{
    scanf("%lld", &T);
    for (int i=1; i<=T; ++i)
    {
        scanf("%lld%lld%lld", &N, &M, &S);
        memset(dist, 0, sizeof dist);
        ans = 0;
        memset(eg, 0, sizeof eg);   // FIX: clear adjlist
        memset(hd, 0, sizeof hd);
        ecnt = 2;
        for (int i=1; i<=M; ++i) addEdge();
        for (int i=1; i<=S; ++i) bfs();
        //db("ans = %d\n", ans);
        if (ans == N) printf("YES\n"); else printf("NO\n");
    }
}

