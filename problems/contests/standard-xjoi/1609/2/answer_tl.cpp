// TODO: why no negatives? why only compare value of `s` in knapsack?
#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> arr[120];
int dp[110][101001];

bool comp(pair<int, int> a, pair<int, int> b){
    return b.first < a.first;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    memset(dp, -10000000, sizeof(dp));
    dp[0][0] = 0;
    sort(arr + 1, arr + n + 1, comp);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 100000; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - arr[i].first >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i].first] + arr[i].second);
        }
    }
    int ans = 0;
    for(int i = 0; i <= 101000; i++){
        if(dp[n][i] < 0) continue;
        ans = max(ans, i + dp[n][i]);
    }
    cout << ans << endl;
}

