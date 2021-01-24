/*
 * Problem lca_2 (spoj/lca_2)
 * Create time: Sat 23 Jan 2021 @ 21:02 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define F(i, N) for (int i=1; i<=N; ++i)
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 1e3+10;
ll T, N, M;
ll par[MX][20];
ll dep[MX];

struct Edge { ll t, n; } eg[MX<<1]; ll hd[MX], ecnt=2;

void kdep(ll c, ll d=1)
{
	if (dep[c]) return;
	dep[c] = d;
	for (int e=hd[c]; e; e=eg[e].n)
		kdep(eg[e].t, d+1);
}

void lca()
{
	ll u, v; scanf("%lld%lld", &u, &v);
	if (u == v) { printf("%lld", u); return; }
	if (dep[u] < dep[v]) swap(u, v); // u is deeper
	for (ll i=19; i--;) {
		if (dep[par[u][i]] >= dep[v])
			i = par[u][i];
	}
	if (u == v) { printf("%lld\n", u); return; }
	for (ll i=19; i--;) {
		if (par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	}
	printf("%lld\n", par[u][0]);
}

int main()
{
	scanf("%lld", &T);
	F(tt, T) {
		scanf("%lld", &N);
		F(i, N) {
			scanf("%lld", &M);
			F(j, M) {
				ll x; scanf("%lld", &x);
				par[x][0] = i;
				eg[ecnt] = { x, hd[i] }; hd[i] = ecnt++;
			}
		}

		F(j, 19) F(i, N) {
			par[i][j] = par[par[i][j-1]][j-1];
		}

		F(i, N) { for (int j=0; j<20; ++j) db("%3d", par[i][j]); db("\n"); }

		ll Q; scanf("%lld", &Q);
		printf("Case %d\n", tt);
		F(i, Q) lca();
	}
}
