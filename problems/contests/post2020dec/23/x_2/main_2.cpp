/*
 * Problem 2 (contests/post2020dec/23/2)
 * Create time: Sun 27 Dec 2020 @ 11:49 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS_)
using namespace std;
const ll MX = 1e5+10;

ll N, c[MX], dp[MX][2]; // dp[i][j] = min cost to correct first i with i being reveresed?=j
//bool cmp[MX][2][2];
string str[MX][2];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;   // FIX: replace scanf with cin??
    for (int i=1; i<=N; ++i) cin >> c[i];
    for (int i=1; i<=N; ++i) cin >> str[i][0];
    for (int i=1; i<=N; ++i)
        str[i][1] = str[i][0],
        reverse(str[i][1].begin(), str[i][1].end());    // FIX: opt--pre-reverse strings and reverse, don't recalculate each time
    //for (int i=1; i<N; ++i)
    //    for (int a=0; a<2; ++a)
    //        for (int b=0; b<2; ++b)
    //            cmp[i][a][b] = str[i][a] <= str[i+1][b],
    //printf("%d %d %d %d\n", cmp[1][0][0], cmp[1][0][1], cmp[1][1][0], cmp[1][1][1]);
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0; dp[1][1] = c[1];  // FIX: equ--base case wrong
    for (int i=2; i<=N; ++i)
        for (int a=0; a<2; ++a)
            for (int b=0; b<2; ++b)
            {
                //db("i %d:   rev %d %d\n", i, a, b);
                //if (cmp[i-1][a][b])
                if (str[i-1][a] <= str[i][b])   // FIX: opt--compare strings on the spot, don't store them bc thats faster?
                    dp[i][b] = min(dp[i][b], dp[i-1][a] + b*c[i]);
            }
    ll ans = min(dp[N][0], dp[N][1]);
    printf("%lld\n", ans < 1e18 ? ans : -1);
}

