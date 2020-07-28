#include <iostream>
#include <utility>

using namespace std;

int n, s, dp[500];
pair<int,int> jboxes[20];


int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> jboxes[i].first >> jboxes[i].second;


    dp[0] = 1;
    for (int i = 1; i <= s; i++) {
        dp[i] = 0;
    }

    int aux[500];
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= s; j++) {
            aux[j] = 0;
            int volume = jboxes[i].second;

            for (int k = 1; k <= jboxes[i].first; k++) {
                if (j - volume * k < 0) break;
                aux[j] += dp[j - volume * k];
            }

        }
        for (int j = 1; j <= s; j++)
            dp[j] += aux[j];
    }

    cout << dp[s] << endl;
}

