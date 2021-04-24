/*
 * Problem hard1 (teamscode_spring_2021/hard1)
 * Create time: Sat 24 Apr 2021 @ 13:32 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define db(...) fprintf(stderr, __VA_ARGS__)
#define F(i, N) for (ll i = 1; i <= N; ++i)

using namespace std;

const ll MX = 2e4;
ll N, M, Q;
ll start[MX], direct[MX];

priority_queue<pair<ll, ll> > pq;
ll vis[MX];

struct Edge { int t, n; } eg[(int)3e7]; ll hd[MX], ecnt = 2;
void addEdge(ll u=0, ll v=0, ll b=0)
{
    if (!b) scanf("%lld%lld", &u, &v), addEdge(v, u, 1);
    //printf("adding edge %lld %lld\n", u, v);
    eg[ecnt] = { (int) v, (int) hd[u] }; hd[u] = ecnt++;
}

void dfs(ll c, ll p=0, ll cur=0)
{
    if (c == 1) return;
    if (!cur) cur = direct[c];
    //printf("at %lld with %lld\n", c, cur);
    pq.emplace(cur, -c);
    for (int e=hd[c]; e; e=eg[e].n) if (eg[e].t != p)
        dfs(eg[e].t, c, cur/2);
}

int main()
{
	scanf("%lld%lld%lld", &N, &M, &Q);
    F(i, M) {
        ll n, w; scanf("%lld%lld", &n, &w);
        direct[n] = w;
        start[i] = n;
    }
    F(i, Q) addEdge();

    F(i, M) dfs(start[i]);

    F(i, N-1) pq.push(make_pair(0, -i-1));

    F(i, N-1) {
        ll t, n; tie(t, n) = pq.top(); pq.pop();
        if (!vis[-n]) printf("%lld %lld\n", -n, t), vis[-n] = 1;
        else --i;
    }
}
