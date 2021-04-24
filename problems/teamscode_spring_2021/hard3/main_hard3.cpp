/*
 * Problem hard3 (teamscode_spring_2021/hard3)
 * Create time: Sat 24 Apr 2021 @ 15:59 (PDT)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define F(i, N) for (ll i=1; i<=N; ++i)

using namespace std;
const int MX = 1e5+10;

ll N;
ll interesting[MX], pinterest[MX];
ll in[MX];

typedef pair<ll, ll> St;
priority_queue<St> pq;

struct Edge { ll t, n; } eg[MX<<1]; ll hd[MX], ecnt=2;
void addEdge(ll u=0, ll v=0)
{
    scanf("%lld%lld", &v, &u);
    eg[ecnt] = { v, hd[u] }; hd[u] = ecnt++;
    in[v] += 1;
}

bool vis[MX];

ll bit[MX];
ll bq(ll x)
{
    ll ans = 0;
    for (; x; x-=x&-x)
        ans += bit[x];
    return ans;
}
void bu(ll x, ll v)
{
    for (; x<=N; x += x&-x)
        bit[x] += v;
}

int main()
{
    scanf("%lld", &N);
    F(i, N) scanf("%lld", &interesting[i]);

    F(i, N-1) addEdge();

    F(i, N) if (!in[i])
        //printf("pushing %lld\n", i),
        pq.push(make_pair(interesting[i], i));

    ll ans = 0;
    while (!pq.empty())
    {
        ll v, c; tie(v, c) = pq.top(); pq.pop();
        ans += bq(c) + v * 3;
        //printf("at %lld , which has interesting %lld, ans += %lld = %lld\n", c, v, bq(c) + v*3, ans);
        bu(c, v);
        for (int e=hd[c]; e; e=eg[e].n) {
            --in[eg[e].t];
            if (!in[eg[e].t]) pq.push(make_pair(interesting[eg[e].t], eg[e].t));
        }
    }
    printf("%lld\n", ans);
}
