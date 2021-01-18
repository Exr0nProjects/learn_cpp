/*
 * Problem all (spoj/all)
 * Create time: Sun 17 Jan 2021 @ 16:20 (PST)
 * Accept time: Sun 17 Jan 2021 @ 16:57 (PST)
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
const ll MX = 1e5+10;
const ll MXE = 2e5+10;
ll N1, N2, M;
ll ds[MX], in[MX], in2[MX];
struct Edge { ll t, n; } eg[MXE<<2]; ll hd[MX], ecnt=2;
void addEdge()
{
	ll u, v; scanf("%lld%lld", &v, &u);
	eg[ecnt] = { v, hd[u] }; hd[u] = ecnt++;
	++in[v];
}

ll bfs(queue<ll> &q, queue<ll> &q2)
{
	memset(ds, 0, sizeof ds);
	ll ans = 2, cnt = 0;
	while (q.size() || q2.size()) {
		if (!q.size()) swap(q, q2), ++ans;
		ll c = q.front(); q.pop();
		// db("at %d\n", c);
		if (ds[c]) continue;
		ds[c] = 1; ++cnt;
		for (int e=hd[c]; e; e=eg[e].n) {
			-- in[eg[e].t];
			if (ds[eg[e].t] || in[eg[e].t]) continue;
			if ((eg[e].t <= N1) == (c <= N1)) q.push(eg[e].t);
			else q2.push(eg[e].t);
		}
	}
	if (cnt < N1 + N2) return 1e16;
	return ans;
}

int main()
{
	while (~scanf("%lld%lld%lld", &N1, &N2, &M)) {
		if (!N1 && !N2 && !M) return 0;
		memset(eg, 0, sizeof eg);
		memset(hd, 0, sizeof hd);
		memset(in, 0, sizeof in);
		memset(in2, 0, sizeof in2);
		for (int i=1; i<=M; ++i) addEdge();
		memcpy(in2, in, sizeof in);
		queue<ll> q1, q2;
		ll ans = 1e16;
		// start with q1
		for (int i=1; i<=N1; ++i) if (!in[i]) q1.push(i);
		for (int i=1; i<=N2; ++i) if (!in[N1+i]) q2.push(N1+i);
		ans = min(ans, bfs(q1, q2));
		// db("first bfs got %lld\n", ans);
        // start with q2
		swap(in, in2);
		for (int i=1; i<=N1; ++i) if (!in[i]) q1.push(i);
		for (int i=1; i<=N2; ++i) if (!in[N1+i]) q2.push(N1+i);
		ans = min(ans, bfs(q2, q1));
		// db("second bfs now %lld\n", ans);
		printf("%lld\n", ans);
	}
}
