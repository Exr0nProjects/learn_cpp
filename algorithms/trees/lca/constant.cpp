// 30 Jun 2020 constant time LCA with sparse table

#include <utility>
#include <algorithm>

#define mp make_pair
#define ll long long
#define f first
#define s second
using namespace std;

const ll MX = 100000;
struct Edge { ll f, t, n; } edges[MX<<1];
ll N, head[MX], alc=1;
pair<ll, ll> sparse[MX][16];
void addEdge(ll a, ll b)
{
    edges[alc].f = a;
    edges[alc].t = b;
    edges[alc].n = head[a];
    head[a] = alc++;
}
ll par[MX], occ[MX], sparse_idx=0;

void dfs(ll cur, ll pre=0, ll dep=1)
{
    par[cur] = pre;
    sparse[0][sparse_idx] = mp(dep, cur);
    occ[cur] = sparse_idx++;
    for (ll e=head[cur]; e; e=edges[e].n)
        if (edges[e].t != pre)
        {
            dfs(edges[e].t, cur, dep+1);
            sparse[0][sparse_idx++] = mp(dep, cur);
            printf("sparse_idx = %d\n", sparse_idx);
        }
}
ll sparse_query(ll l, ll r)  // inc l inc r
{
    if (r < l) swap(l, r);
    ++r; // FIX: fencepost goes here, not outside since we dunno which will end up being bigger
    ll range = 63-__builtin_clzll(r-l); // FIX: 63- not 64- cuz 1 is 1<<0 not 1<<1
    printf("range = %d-%d -> %d\n", r, l, range);
    printf("querying min(%d..%d and %d..%d)\n", l, l+(1<<range), r-range, r-(1<<range)+(1<<range));
    printf("    so min(%d, %d by %d, %d)\n", sparse[range][l].f, sparse[range][l].s,
            sparse[range][r-(1<<range)].f, sparse[range][r-(1<<range)].s);
    return min(sparse[range][l], sparse[range][r-(1<<range)]).s;
}

void init_lca()
{
    dfs(1);
    for (ll i=1; i<16; ++i)
        for (ll j=0; j+(1<<i)<=sparse_idx; ++j)
            sparse[i][j] = min(
                    sparse[i-1][j],
                    sparse[i-1][j+(1<<i-1)]);

    for (ll i=16; i>=0; --i)
    {
        printf("%2d (%4d): ", i, 1<<i);
        for (ll j=0; j+(1<<i)<=sparse_idx; ++j) // FIX: comparison--le sparse_idx no lt cuz the add
        {
            printf("%3d +%-2d", sparse[i][j].f, sparse[i][j].s);
        }
        printf("\n");
    }
    for (ll i=1; i<=N; ++i)
        printf("%d -> %d\n", i, occ[i]);
}

int main()
{
    scanf("%lld", &N);
    for (ll i=0; i<N-1; ++i)
    {
        ll u, v;
        scanf("%lld%lld", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    init_lca();
    printf("n is %d\n", N);
    for (ll i=1; i<=N; ++i)
    {
        for (ll j=1; j<=N; ++j)
            printf("%3d x %3d: %3d\n", i, j, sparse_query(occ[i], occ[j]));
        printf("\n");
    }
    //ll Q; scanf("%lld", &Q);
    //for (ll i=0; i<Q; ++i)
    //{
    //    ll u, v; scanf("%lld%lld", &u, &v);
    //    printf("lca of %d and %d = %d\n", u, v, sparse_query(occ[u], occ[v]+1));
    //}
}

/*
5
1 2
1 3
2 4
3 5
*/
