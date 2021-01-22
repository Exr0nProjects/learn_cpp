/*
 * Problem ezdijkst_3 (spoj/ezdijkst_3)
 * Create time: Fri 22 Jan 2021 @ 11:51 (PST)
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

ll T, N, M, A, B;
ll ds[MX];
struct Edge { ll t, w, n; } eg[MX<<1]; ll hd[MX], ecnt=2;
void addEdge()
{
	ll u, v, w; scanf("%lld%lld%lld", &u, &v, &w);
	eg[ecnt] = { v, w, hd[u] }; hd[u] = ecnt++;
}

int main()
{
	scanf("%lld", &T);
	F(tt, T) {
		scanf("%lld%lld", &N, &M);
		memset(ds, 0x3f, sizeof ds);
		memset(eg, 0, sizeof eg);
		memset(hd, 0, sizeof hd);
		ecnt = 2;

		F(i, M) addEdge();
		scanf("%lld%lld", &A, &B);

		typedef tuple<ll, ll> St;
		priority_queue<St, deque<St>, greater<St> > pq;
		pq.push(mt(0, A));
		while (pq.size()) {
			ll d, c; tie(d, c) = pq.top(); pq.pop();
			if (ds[c] <= d) continue; ds[c] = d;
			if (c == B) break;
			for (int e=hd[c]; e; e=eg[e].n)
				pq.push(mt(d+eg[e].w, eg[e].t));
		}
		if (ds[B] > 1e9) printf("NO\n");
		else printf("%lld\n", ds[B]);
	}
}
