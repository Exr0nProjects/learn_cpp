/*
 * Problem 10034 (uva/10034)
 * Create time: Sun 17 Jan 2021 @ 21:27 (PST)
 * Accept time: Fri 22 Jan 2021 @ 11:14 (PST)
 * dense prim
 */
#include <bits/stdc++.h>
#define ll long long
#define dl double
#define F(i, N) for (int i=1; i<=(N); ++i)
#define mt make_pair
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 110;
ll T, N, vis[MX];
dl x[MX], y[MX], dist[MX];

int main()
{
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld", &N);
		F(i, N) scanf("%lf%lf", &x[i], &y[i]);

		memset(vis, 0, sizeof vis);
		F(i, N) dist[i] = 1e16;

		dl ans = 0;
		ll cur = 1; dist[cur] = 0;
		F(i, N) {
			vis[cur] = 1;
			ans += dist[cur];
			dist[cur] = 1e16;
			// F(i, N) db("%6.3lf", dist[i]); db("\n");
			F(i, N) if (i != cur) dist[i] = min(dist[i], sqrt( (x[i]-x[cur])*(x[i]-x[cur]) + (y[i]-y[cur])*(y[i]-y[cur]) )); // FIX: dont reset own dist
			F(i, N) if (!vis[i]) if (dist[i] < dist[cur]) cur = i;
		}
		printf("%.2lf\n", ans);
        if (T) printf("\n");
	}
}
