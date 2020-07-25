#include <iostream>

using namespace std;

int n, k[10100];
char seq[10100][26];

int dp[40][40];

// longest common subsequence between seq[a], seq[b]
int lcs(int a, int b) {
    int toreturn = 0;
    for (int i = 0; i < k[a]; i++)
        for (int j = 0; j < k[b]; j++)
            dp[i][j] = 0;

    // cout << "--" << endl;
    for (int i = 0; i < k[a]; i++) {
        for (int j = 0; j < k[b]; j++) {
            int prev = 0;
            if (i > 0 && j > 0) prev = dp[i-1][j-1];
            if (seq[a][i] == seq[b][j])
                prev++;
            dp[i][j] = prev;
            toreturn = max(toreturn, dp[i][j]);
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    // cout << "--" << endl;

    return toreturn;
}

int main() {
    cin >> n; n++;
    for (int i = 0; i < n; i++)
        cin >> k[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k[i]; j++)
            cin >> seq[i][j];

    int ans = 0;
    for (int i = 1; i < n; i++)
        ans += lcs(0, i);

    cout << ans << endl;

}

