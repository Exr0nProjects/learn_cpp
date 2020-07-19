#include <bits/stdc++.h>
using namespace std;
int n, maxw, dp[1010][1010], cost[1010], val[1010];
int main() {
    cin >> maxw >> n;
    for (int i = 0; i < n; i++) {
        cin >> cost[i] >> val[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= maxw; j++) {
            if (j - cost[i] >= 0)
                dp[i][j] = max(dp[i][j], max(dp[i-1][j-cost[i]]+val[i], dp[i-1][j]));
            else dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    cout << dp[n-1][maxw] << endl;
}

