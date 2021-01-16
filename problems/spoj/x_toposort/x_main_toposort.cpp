/*
 * Problem toposort (spoj/toposort)
 * Create time: Sat 16 Jan 2021 @ 13:45 (PST)
 * Accept time: Sat 16 Jan 2021 @ 13:52 (PST)
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 1e4+10;
const ll MXE = 1e6+10;

ll N, M;
ll in[MX];
ll ans[MX], acnt=0;
struct Edge { ll t, n; } eg[MXE<<1]; ll hd[MX], ecnt=2;
void addEdge()
{
	ll u, v; scanf("%lld%lld", &u, &v);
	eg[ecnt] = { v, hd[u] }; hd[u] = ecnt++;
	++in[v];
}

int main()
{
	scanf("%lld%lld", &N, &M);
	for (int i=1; i<=M; ++i) addEdge();
	priority_queue<ll, deque<ll>, greater<ll> > pq;
	for (int i=1; i<=N; ++i) if (!in[i]) pq.push(i);
	while (pq.size()) {
		ll c = pq.top(); pq.pop();
		ans[++acnt] = c;
		for (int e=hd[c]; e; e=eg[e].n) {
			--in[eg[e].t];
			if (!in[eg[e].t]) pq.push(eg[e].t);
		}
	}
	if (acnt == N) for (int i=1; i<=N; ++i) printf("%d ", ans[i]);
	else printf("Sandro fails.");
	printf("\n");
}
