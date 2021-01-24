/*
 * Problem 1078 (usaco/gold/2021jan/1078)
 * Create time: Sun 24 Jan 2021 @ 10:57 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define F(i, N) for (int i=1; i<=N; ++i)
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 4e4+10;
const ll MXK = 64;

ll N, K;

char adj[MXK][MXK];
ll dist[MX];
ll breed[MX];
ll pre[MX];

bool vis[MX];

vector<int> adjl[MXK];

struct Cow { ll i, n; } cows[MX]; ll bhd[MX], bcnt=1;
void addCow(ll i)
{
	ll b; scanf("%lld", &b);
	breed[i] = b;
	pre[cows[bhd[b]].i] = bcnt;
	cows[bcnt] = { i, bhd[b] }; bhd[b] = bcnt++;
}

int main()
{
	scanf("%lld%lld", &N, &K);
	F(i, N) addCow(i);
	// F(i, K) { for (int c=bhd[i]; c; c=cows[c].n) db("%3d", cows[c].i); db("\n"); }
	F(i, K) scanf("%s", adj[i]+1);
	// F(i, K) F(j, K) adj[i][j] -= '0';
	F(i, K) F(j, K) if (adj[i][j] == '1') adjl[i].push_back(j);
	// F(i, K) { F(j, K) db("%3d", adj[i][j]); db("\n"); }

	memset(dist, 0x3f, sizeof dist);
	typedef tuple<ll, ll> St;   // < dist, cur >
	priority_queue<St, deque<St>, greater<St> > pq;
	pq.push(mt(1, 1));
	ll ok = 0;
	while (pq.size()) {
		ll d, c; tie(d, c) = pq.top(); pq.pop();

		// db("at %d after %d\n", c, d);
		if (vis[c]) continue; vis[c] = 1;

		// db("pre[%d] = %d (%d, %d)\n", c, pre[c], cows[pre[c]].i, cows[pre[c]].n);
		if (pre[c]) pre[cows[c].n] = pre[c], cows[pre[c]].n = cows[c].n;
		// db("pre[%d] = %d (%d, %d)\n", c, pre[c], cows[pre[c]].i, cows[pre[c]].n);

		if (c == N) { printf("%lld\n", d-1); ok = 1; break; }

		// F(i, K) if (adj[breed[c]][i])
		for (int i : adjl[breed[c]])
			for (int e=bhd[i]; e; e=cows[e].n)
				if (dist[cows[e].i] > d+abs(c-cows[e].i))
					dist[cows[e].i] = d+abs(c-cows[e].i),
					pq.push(mt(       d+abs(c-cows[e].i), cows[e].i));
				// if (!dist[cows[e].i])
				// 	dist[cows[e].i] = dist[c]+abs(c-cows[e].i),
				// 	q.push(cows[e].i);
	}
	if (!ok) printf("-1\n");
}
