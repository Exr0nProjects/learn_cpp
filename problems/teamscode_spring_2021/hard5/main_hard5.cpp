/*
 * Problem hard5 (teamscode_spring_2021/hard5)
 * Create time: Sat 24 Apr 2021 @ 14:22 (PDT)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define db(...) fprintf(stderr, __VA_ARGS__)
#define F(i, N) for (ll i=1; i<=N; ++i)

using namespace std;

const ll MX = 1e5;

ll N, M;

struct Edge { ll t, w, n; } eg[MX<<1]; ll hd[MX], ecnt=2;

ll pcost[MX];

void addEdge(ll u, ll v, ll w)
{
    eg[ecnt] = { v, w, hd[u] };
    hd[u] = ecnt++;
}

map<string, ll> nameid;
ll id(string &s)
{
    if (!nameid.count(s))
        printf("%s = %lu\n", s.c_str(), nameid.size()+1),
        nameid[s] = nameid.size()+1;
    return nameid[s];
}

ll par[MX][20];
ll dep[MX];

void kdep(ll c, ll p=0, ll d=1)
{
    dep[c] = d;
    for (int e=hd[c]; e; e=eg[e].n) if (eg[e].t != p)
        kdep(eg[e].t, c, d+1);
}

ll lca(ll a, ll b)
{
    ll mul = 1;
    ll cost = 0;
    if (dep[a] < dep[b]) swap(a, b), mul = -1;
    for (int i=19; ~i; --i) {
        if (dep[par[a][i]] >= dep[b]) {
            db("%lld  a %lld %lld b %lld %lld -> %d\n", i, a, dep[a], b, dep[b], par[a][i]),
            cost += pcost[a],
            a = par[a][i];
        }

    }
    printf("%lld %lld\n", a, b);
    return -1;
}

int main()
{
    scanf("%lld%lld", &N, &M);
    F(i, N-1) {
        string a, b;
        cin >> a >> b;
        ll fact; scanf("%lld", &fact);
        addEdge(id(a), id(b), fact);
        addEdge(id(b), id(a), -fact);
        par[id(b)][0] = id(a);
        printf("par[%lld][0] = %lld\n", id(b), par[id(b)][0]);
        pcost[id(b)] = fact;
    }

    F(i, N) if (!par[i][0]) par[i][0] = i, kdep(i);

    F(j, 19) F(i, N) par[i][j] = par[par[i][j-1]][j-1];

    F(j, 20) { F(i, N) printf("%3d", par[i][j-1]); printf("\n"); }

    F(i, M) {
        string a, b;
        cin >> a >> b;
        printf("%lld\n", lca(id(a), id(b)));
    }
}

