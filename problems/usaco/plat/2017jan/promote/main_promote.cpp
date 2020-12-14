/*
 * Problem promote (usaco/plat/2017jan/promote)
 * Create time: Sun 13 Dec 2020 @ 17:00 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MX = 1e5+10;

struct Edge { ll t, n; } eg[MX<<1]; ll hd[MX], ecnt=2;
void addEdge(ll u, ll v=0)
{
    scanf("%d", &v);
    eg[ecnt] = { u, hd[v] };
    hd[v] = ecnt++;
}

ll N, p[MX], ans[MX];
multiset<ll> sub[MX];

multiset<ll>& merge(multiset<ll> &a, multiset<ll> &b)
{
    if (a.size() < b.size()) swap(a, b);
    //for (auto n : b) a[n.first] += n.second;
    for (auto n : b) a.insert(n);
    return a;
}

multiset<ll>& dfs(ll c)
{
    //printf("at %d\n", c);
    for (int e=hd[c]; e; e=eg[e].n)
        merge(sub[c], dfs(eg[e].t));
    auto ins = sub[c].insert(p[c]);
    //printf("subset at %d: ", c); for (auto n : sub[c]) printf("%3d", n); printf("\n");
    ans[c] = distance(ins, sub[c].end())-1;
    return sub[c];
}

int main()
{
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w+", stdout);
    scanf("%d", &N);
    for (int i=1; i<=N; ++i) scanf("%d", p+i);
    for (int i=2; i<=N; ++i) addEdge(i);
    dfs(1);
    for (int i=1; i<=N; ++i) printf("%d\n", ans[i]);
}

