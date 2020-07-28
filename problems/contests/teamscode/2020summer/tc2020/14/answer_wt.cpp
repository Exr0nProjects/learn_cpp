/*

1-idnexed

*/

#include <iostream>
#include <string>

using namespace std;
#define MAXVAL 10000999
#define INF 999999

string s;
int dp[100100], arr[100100];
bool isprime[MAXVAL + 1];

void computePrimes() {
    for (int i = 0; i <= MAXVAL; i++) {
        isprime[i] = true;
    }
    for (int p = 2; p * p <= MAXVAL; p++) {
        if (isprime[p]) {
            for (int i = p*p; i <= MAXVAL; i += p)
                isprime[i] = false;
        }
    }
}

int tonum(int lo, int hi) {
    int pow = 1, ans = 0;
    for (int i = hi; i >= lo; i--) {
        ans += pow * arr[i];
        pow *= 10;
    }
    return ans;
}

int main() {
    cin >> s;
    for (int i = 1; i <= s.size(); i++)
        arr[i] = s[i - 1] - '0';

    computePrimes();
    dp[0] = 0;

    for (int i = 1; i <= s.size(); i++) {
        dp[i] = INF;
        for (int j = 0; j < 7; j++) {
            if (i - j <= 0) break;
            int val = tonum(i-j, i);
            if (!isprime[val]) continue;
            dp[i] = min(dp[i], dp[i-j-1] + 1);
        }
    }

    if (dp[s.size()] == INF) cout << "-1" << endl;
    else cout << dp[s.size()] << endl;





}

