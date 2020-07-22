#include <bits/stdc++.h>
using namespace std;
int n, dp[10011][2][2], inf = 10011;
vector <int> p[10011];
int dfs(int cur, int prev, bool curs, bool prevs) {
    if (dp[cur][curs][prevs] != -1) return dp[cur][curs][prevs];
    int s = p[cur].size(), ans = 0;
    if (curs) ans++;
    if (curs) {
        for (int i = 0; i < s; i++) {
            int next = p[cur][i];
            if (next == prev) continue;
            ans += min(dfs(next, cur, 0, 1), dfs(next, cur, 1, 1));
        }
    }
    else {
        if (prevs) {
            for (int i = 0; i < s; i++) {
                int next = p[cur][i];
                if (next == prev) continue;
                ans += dfs(next, cur, 0, 0);
                if (ans > n) {
                    dp[cur][curs][prevs] = ans;
                    return ans;
                }
            }
        }
        else {
            if (s == 1) {
                dp[cur][curs][prevs] = inf;
                return inf;
            }
            ans = inf;
            int cnt;
            for (int i = 0; i < s; i++) {
            	if (p[cur][i] == prev) continue;
                cnt = 0;
                for (int j = 0; j < s; j++) {
                    int next = p[cur][j];
                    if (next == prev) continue;
                    if (j == i) cnt += dfs(next, cur, 1, 0);
                    else cnt += dfs(next, cur, 0, 0);
                    if (cnt > n) break;
                }
                ans = min(ans, cnt);
            }
        }
    }
    dp[cur][curs][prevs] = ans;
    return ans;
}
int main() {
    int x, y;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            p[i].clear();
            dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -1;
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> x >> y;
            p[x].push_back(y);
            p[y].push_back(x);
        }
        p[1].push_back(0);
        cout << min(dfs(1, 0, 1, 0), dfs(1, 0, 0, 0)) << endl;
        cin >> x;
        if (x == -1) break;
    }
}
