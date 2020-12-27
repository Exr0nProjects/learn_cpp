/*
 * Problem 2 (contests/post2020dec/23/2)
 * Create time: Sun 27 Dec 2020 @ 11:49 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS_)
using namespace std;
const ll MX = 1e5;

ll N, c[MX], dp[MX][2]; // dp[i][j] = min cost to correct first i with i being reveresed?=j
bool cmp[MX][2][2];
string str[MX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    scanf("%lld", &N);
    for (int i=1; i<=N; ++i) scanf("%lld", c+i);
    for (int i=1; i<=N; ++i) cin >> str[i];
    for (int i=1; i<N; ++i)
        for (int a=0; a<2; ++a)
        {
            for (int b=0; b<2; ++b)
                cmp[i][a][b] = str[i] <= str[i+1],
                reverse(str[i+1].begin(), str[i+1].end());
            reverse(str[i].begin(), str[i].end());
        }
    //printf("%d %d %d %d\n", cmp[1][0][0], cmp[1][0][1], cmp[1][1][0], cmp[1][1][1]);
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0; dp[1][1] = c[1];  // FIX: equ--base case wrong
    for (int i=2; i<=N; ++i)
        for (int a=0; a<2; ++a)
            for (int b=0; b<2; ++b)
            {
                //db("i %d:   rev %d %d\n", i, a, b);
                if (cmp[i-1][a][b])
                    dp[i][b] = min(dp[i][b], dp[i-1][a] + b*c[i]);
            }
    ll ans = min(dp[N][0], dp[N][1]);
    printf("%lld\n", ans < 1e18 ? ans : -1);
}

