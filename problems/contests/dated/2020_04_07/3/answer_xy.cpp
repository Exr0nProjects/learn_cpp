#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 2000;
const ll inf = 1e14;
int n, m;
int a[maxn + 10]; 	// state boundaries, a[i] = a_i
int pre[maxn + 10];	// stores the most recent state boundary... pre[i] = max{s : a[s] <  i}
int nxt[maxn + 10];	// same but for the next state boundary...  nxt[i] = min{s : a[s] >= i}
ll sum[maxn + 10];	// prefix sum on expected product of each viral state range
ll f[maxn + 10][2]; 	// rolling array dp.. at each iter i:
			// 	f[j][0] = expected product from a[i-1]+1 thru j
			// 	f[j][1] = expected product from j thru a[i+1]
ll g[maxn + 10]; 	// cost? g[i] = cost to get a virus of this activity level to state 1

ll solve(int l, int r) {
	if (r <= a[1]) return 0;
	int pl = nxt[l], pr = pre[r];
	if (pl > pr) return inf;
	ll ans = sum[pr] - sum[pl];
	ans += f[l][1]; ans += f[r][0];
	return ans;
}

ll calc(int l, int r) { // expected cost * range of the range inc l inc r
	if (r <= a[1]) return 0;
	ll ans = inf;
	for (int i = 1; i <= l - 1; ++i)
		ans = min(ans, solve(l - i, r - i) + g[i] * (r - l + 1));
	return ans;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		memset(a, 0, sizeof a);
		memset(pre, 0, sizeof pre);
		memset(nxt, 0, sizeof nxt);
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		memset(sum, 0, sizeof sum);
		scanf("%d%d", &n, &m);
		// input states and pre/postfix sum on states
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; ++i)
			for (int j = a[i - 1] + 1; j <= a[i]; ++j) {
				pre[j] = i - 1; nxt[j] = i;
			}
		// knapsack
		for (int i = 1; i <= a[n]; ++i) g[i] = inf;	// TODO: why from i=1, not i=a[1]?
		for (int i = 1; i <= m; ++i) {			// for each operation
			int v, c; scanf("%d%d", &v, &c);
			for (int j = c; j <= a[n]; ++j)		// for every `j` we can do this operation on
				g[j] = min(g[j], g[j - c] + v);	// relax cost of `j` with this operation
		}
		// final dp logic.. TODO
		for (int i = 1; i <= n; ++i) {				// for each state
			for (int j = a[i - 1] + 1; j <= a[i]; ++j)	// for each activity level within
				f[j][0] = calc(a[i - 1] + 1, j);	// range from pre thru j
			for (int j = a[i - 1] + 1; j <= a[i]; ++j)
				f[j][1] = calc(j, a[i]);		// range from j thru post, for the rolling array
			sum[i] = sum[i - 1] + f[a[i]][0];
		}
		if (sum[n] >= inf) printf("-1\n");
		else printf("%lld\n", sum[n]);
	}
}

