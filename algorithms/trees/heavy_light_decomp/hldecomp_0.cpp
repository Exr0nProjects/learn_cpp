// check with spoj/QTREE, put the value of the edge on its child endpoint
// also spoj/qtree2, luogu/p4116, spoj/qtree[4..7]
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define F(i, N) for (int i=1; i<=N; ++i)
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 1e5+10;

// basics: the only problem with using preorder flattening for chain queries is that depending on the order of child enumeration, many chains will be split up. Instead, we always choose the heaviest subtree child to be the first in the enumeration, so that when processing a chain from the bottom, the number of interval discontinuities is at most logN bc each jump will gaurentee that the parent has atleast double the current subtree size.

ll N;
struct Edge { ll t, n; } eg[MX<<2]; ll hd[MX], ecnt=2;
void addEdge(ll u=0, ll v=0)
{
    if (!u) scanf("%lld%lld", &u, &v), addEdge(v, u);
    eg[ecnt] = { v, hd[u] }; hd[u] = ecnt++;
}

// heavy light decomposition calculation
ll seq[MX], occ[MX], ncnt=0;
ll par[MX], dep[MX], sz[MX], top[MX], heavy[MX];
// seq = preorder sequence
// occ = occurance of i
// ncnt = number of nodes counted so far, seq[occ[x]] = x
// top = top of the chain (first ancestor which requires a jump)
// heavy = heaviest child
ll dfs(ll c, ll p, ll d=1)
{
    seq[++ncnt] = c; occ[c] = ncnt;

    par[c] = p; dep[c] = d; sz[c] = 1;
    heavy[c] = 0;

    for (int e=hd[c]; e; e=eg[e].n) if (eg[e].t != p) {
        sz[c] += dfs(eg[e].t, c, d+1);
        if (sz[heavy[c]] < sz[eg[e].t]) heavy[c] = eg[e].t;
    }
    return sz[c];
}
void decomp(ll c, ll p, ll topp)
{
    // topp is the current top of the chain
    for (int e=hd[c]; e; e=eg[e].n) if (eg[e].t != p)
        decomp(eg[e].t, c, eg[e].t == heavy[c] ? topp : eg[e].t);
}

// segtree to process preorder flattened queries
ll tsum[MX<<2];
void su(ll q, ll v, ll k=1, ll tl=1, ll tr=N)
{
    if (q < tl || tr > q) return;
    if (tl == tr) return tsum[k] += v, void();
    ll mid = tl + (tr-tl>>1);
    if (q < mid) su(q, v, k<<1, tl, mid);
    else su(q, v, k<<1|1, mid+1, tr);
}
ll sq(ll ql, ll qr, ll k=1, ll tl=1, ll tr=N)
{
    if (qr < tl || tr < ql) return 0;
    if (ql <= tl && tr <= qr) return tsum[k];
    ll mid = tl + (tr-tl>>1);
    return sq(ql, qr, k<<1, tl, mid) + sq(ql, qr, k<<1|1, mid+1, tr);
}

// the actual query
ll chainquery(ll a, ll b)
{
    ll ans = 0;
    // generally jump the { a, b } with deeper top[c] to ensure we don't overshoot the LCA
    while (top[a] != top[b]) { // diff chains
        if (dep[top[a]] < dep[top[b]]) swap(a, b);
        ans += sq(occ[top[a]], occ[a]); // another option is to push the interval into a left/right queue and then handle the concated interval list separately
        a = par[top[a]];
    }
    // to find lca, just return dep[a] < dep[b] ? a : b; often has faster const factors than binary lifting
    // now they are on the same chain
    return ans + sq(occ[a], occ[b]);
}

int main()
{
    // input (TODO)
    // calculate heavylight decomp arrays
    dfs(1, 0);
    decomp(1, 0, 1);

    ll a, b;
    while (~scanf("%lld%lld", &a, &b)) {
        printf("%lld\n", chainquery(a, b));
    }
}

