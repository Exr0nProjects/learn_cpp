#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXT = 1005;

long long n, m, c;
long long value[MAXN];
long long dp[2][MAXN];

vector<pair<int, int>> edges;

int main() {
	//freopen("time.in","r",stdin);
	//freopen("time.out","w",stdout);
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++) {
		cin >> value[i];
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edges.push_back(make_pair(a, b));
	}
	long long max_profit = 0;
	memset(dp, -1, sizeof dp);
	dp[0][1] = 0;
	for (int t = 1; t < MAXT; t++) {
		int p = t % 2;
		memset(dp[p], -1, sizeof dp[p]);
		for (auto& e : edges) {
			a = e.first;
			b = e.second;
			if (dp[1-p][a] >= 0) {
				dp[p][b] = max(dp[p][b], dp[1-p][a] + value[b]);
			}
		}
        //printf("%d\n", dp[p][1] - c*t*t);
        printf("%d - %d = %d\n", dp[p][1], c*t*t, dp[p][1] - c*t*t);
		max_profit = max(max_profit, dp[p][1] - c * t * t);
	}
	cout << max_profit << "\n";
}

