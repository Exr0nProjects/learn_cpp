#include<bits/stdc++.h>
using namespace std;
const int maxn = 122, maxs = 8, inf = 1000000000;
int s, m, n, c[maxn], sub[maxn], dp[maxn][1 << maxs][1 << maxs];
int DP(int cur, int s0, int s1, int s2) {
	if (cur == m + n) return s2 == (1 << s) - 1 ? 0 : inf;
	int &ans = dp[cur][s1][s2];
	if (ans >= 0) return ans;
	ans = inf;
	if (cur >= m) ans = DP(cur + 1, s0, s1, s2);
	int m0 = s0 & sub[cur], m1 = s1 & sub[cur];
	s0 ^= m0;
	s1 = (s1 ^ m1) | m0;
	s2 |= m1;
	ans = min(ans, c[cur] + DP(cur + 1, s0, s1, s2));
	return ans;
}
int main() {
	string line;
	int x;
	while (getline(cin, line)) {
		stringstream ss(line);
		ss >> s >> m >> n;
		if (s == 0) break;
		for (int i = 0; i < m + n; i++) {
			getline(cin, line);
			stringstream ss(line);
			ss >> c[i];
			sub[i] = 0;
			while (ss >> x) sub[i] |= (1 << (x - 1));
		}
		memset(dp, -1, sizeof(dp));
        int got = DP(0, (1 << s) - 1, 0, 0);
        if (got >= inf) got = -1;
		cout << got << endl;
	}
	return 0;
}

