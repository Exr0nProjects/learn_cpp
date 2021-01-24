/*
 * Problem planets_and_kingdoms_2 (cses/graph/planets_and_kingdoms_2)
 * Create time: Sat 23 Jan 2021 @ 17:06 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define F(i, N) for (int i=1; i<=N; ++i)
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 1e5;

ll N, M;
struct Edge { ll t, n; } eg[MX<<2]; ll hd[MX], ecnt=2;
void addEdge()
{
	ll u, v; scanf("%lld%lld", &u, &v);
	eg[ecnt] = { v, hd[u] }; hd[u] = ecnt++;
}

ll tstack[MX], scnt=0;
ll vis[MX], vcnt=0, low[MX];
ll ans[MX], acnt=0;
ll tarjan(ll c)
{
	vis[c] = ++vcnt;
	tstack[++scnt] = c;
	low[c] = vis[c];

	for (int e=hd[c]; e; e=eg[e].n) {
		if (vis[eg[e].t]) low[c] = min(low[c], vis[eg[e].t]);
		else low[c] = min(low[c], tarjan(eg[e].t));
	}

	if (vis[c] == low[c]) {
		ans[c] = ++acnt;
		while (tstack[vcnt] != c)
			ans[tstack[vcnt--]] = acnt;
	}

	return low[c];
}

int main()
{
	scanf("%lld%lld", &N, &M);
	F(i, M) addEdge();

	tarj(1);

	printf("%lld\n", acnt);
	F(i, N) printf("%d ", ans[i]); printf("\n");
}
