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

const ll MX = 1e4+10;
const ll MXK = 64;

ll N, K;

char adj[MXK][MXK];
ll dist[MX];
ll breed[MX];

struct Cow { ll i, n; } cows[MX]; ll bhd[MX], bcnt=2;
void addCow(ll i)
{
	ll b; scanf("%lld", &b);
	breed[i] = b;
	cows[bcnt] = { i, bhd[b] }; bhd[b] = bcnt++;
}

int main()
{
	scanf("%lld%lld", &N, &K);
	F(i, N) addCow(i);
	// F(i, K) { for (int c=bhd[i]; c; c=cows[c].n) db("%3d", cows[c].i); db("\n"); }
	F(i, K) scanf("%s", adj[i]+1);
	F(i, K) F(j, K) adj[i][j] -= '0';
	// F(i, K) { F(j, K) db("%3d", adj[i][j]); db("\n"); }

	queue<ll> q;
	q.push(1); dist[1] = 1;
	while (q.size()) {
		ll c = q.front(); q.pop();
		db("at %d after %d\n", c, dist[c]);
		if (c == N) { printf("%lld\n", dist[c]); break; }
		F(i, K) if (adj[breed[c]][i])
			for (int e=bhd[i]; e; e=cows[e].n)
				if (!dist[cows[e].i])
					dist[cows[e].i] = dist[c]+abs(c-cows[e].i),
					q.push(cows[e].i);
	}
}
