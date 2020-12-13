/*
 * Problem nocross (usaco/gold/2017feb/nocross)
 * Create time: Sat 12 Dec 2020 @ 17:21 (PST)
 * Accept time: Sat 12 Dec 2020 @ 17:24 (PST)
 *
 */
#include <bits/stdc++.h>
using namespace std;
const int MX = 1e3+10;

int N, a[MX], b[MX], dp[MX][MX];

int main()
{
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w+", stdout);
    scanf("%d", &N);
    for (int i=1; i<=N; ++i) scanf("%d", a+i);
    for (int i=1; i<=N; ++i) scanf("%d", b+i);

    // basically lcs
    for (int i=1; i<=N; ++i)
        for (int j=1; j<=N; ++j)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (abs(a[i] - b[j]) <= 4)
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
        }
    printf("%d\n", dp[N][N]);
}

