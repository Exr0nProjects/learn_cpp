/*
 * Problem planets_and_kingdoms_2 (cses/graph/planets_and_kingdoms_2)
 * Create time: Sat 23 Jan 2021 @ 17:06 (PST)
 * Accept time: Sat 23 Jan 2021 @ 17:29 (PST)
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define F(i, N) for (int i=1; i<=N; ++i)
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 1e5+10;

ll N, M;
struct Edge { ll t, n; } eg[MX<<2]; ll hd[MX], ecnt=2;
void addEdge()
{
	ll u, v; scanf("%lld%lld", &u, &v);
	eg[ecnt] = { v, hd[u] }; hd[u] = ecnt++;
}

// NOTE: tarjan needs stack, preorder time, low number, and ans
ll tstack[MX], scnt=0;
ll vis[MX], vcnt=0, low[MX];
ll ans[MX], acnt=0;
ll tarj(ll c)
{
	// if (vis[c]) return low[c];
	vis[c] = ++vcnt;
	low[c] = vis[c];
	tstack[++scnt] = c;

	for (int e=hd[c]; e; e=eg[e].n) {
		// if (vis[eg[e].t] && !ans[eg[e].t]) // FIX: check that eg[e].t is not in stack for back edge (aka must be in the same SCC)
		// 	low[c] = min(low[c], vis[eg[e].t]);
		// else low[c] = min(low[c], tarj(eg[e].t));
		if (!vis[eg[e].t]) low[c] = min(low[c], tarj(eg[e].t));
		else if (!ans[eg[e].t]) low[c] = min(low[c], vis[eg[e].t]); // FIX: tarjan if statement ordering, etc is v important (can't just else, need else if)
	}

	if (vis[c] == low[c]) {
		ans[c] = ++acnt;
		while (tstack[scnt] != c)
			ans[tstack[scnt--]] = acnt;
		--scnt;
	}

	return low[c];
}

int main()
{
	scanf("%lld%lld", &N, &M);
	F(i, M) addEdge();

	F(i, N) if (!ans[i]) tarj(i);

	printf("%lld\n", acnt);
	F(i, N) printf("%d ", ans[i]); printf("\n");
}
