/*
 * Problem P1896 (luogu/P1896)
 * Create time: Thu 07 Jan 2021 @ 16:51 (PST)
 * Accept time: [!meta:end!]
 * ways to place K kings on an NxN chessboard (bitmask dp)
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stdout, __VA_ARGS__)
using namespace std;

const ll MX = 10;
ll N, K, dp[MX*MX][MX][MX][1<<MX];  // dp[k][i][j][x] = # ways to populate up to (i, j) using k kings and prev row has x

bool legal(ll x)
{
    for (int i=1; i<N; ++i) if (x>>(i-1)&1  &&  x>>i&1) return 0;
    return 1;
}
int main()
{
    scanf("%lld%lld", &N, &K);

    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) for (int x=0; x<1<<N; ++x)
        dp[0][i][j][x] = 1;  // always one way to place zero kings
    dp[1][0][0][1] = 1;

    for (int k=1; k<=K; ++k) for (int i=0; i<N; ++i) for (int j=i?0:1; j<N; ++j)
    {
        for (int x=0; x<1<<N; ++x) if (legal(x))
        {

    }
}

