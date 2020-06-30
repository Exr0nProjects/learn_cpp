// 30 Jun 2020 LCA checker
#include <iostream>
#include <list>
using namespace std;
#define ll long long
#define pb push_back
const ll MX = 100111;
list<ll> head[MX];
ll N, U, V;

ll dfs_lca(ll cur, ll pre=0)
{
    if (cur == U || cur == V) return cur;
    ll has = 0;
    for (ll nxt : head[cur])
        if (nxt != pre)
        {
            ll got = dfs_lca(nxt, cur);
            if (got && has) return cur;
            if (got) has = got;
        }
    return has;
}

int main()
{
    scanf("%lld", &N);
    for (ll i=1; i<N; ++i)
    {
        ll u, v;
        scanf("%lld%lld", &u, &v);
        head[u].pb(v);
        head[v].pb(u);
    }
    for (ll i=1; i<=N; ++i)
    {
        for (ll j=1; j<=N; ++j)
        {
            U = i; V = j;
            printf("%3lld", dfs_lca(1));
        }
        printf("\n");
    }
}
