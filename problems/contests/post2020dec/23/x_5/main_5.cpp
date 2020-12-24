/*
 * Problem 5 (contests/post2020dec/23/5)
 * Create time: Wed 23 Dec 2020 @ 20:10 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <cstdio>
#include <utility>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

const ll MX = 210;

ll N;
char buf[MX];

bool match(char l, char r)
{ return ((l == '(' && r == ')') || (l == '[' && r == ']')); }

ll dp[MX][MX];
ll op(ll l, ll r)   // inc exc
{
    if (l == r) return 0;
    if (l+1 == r) return 1; // single paren
    if (dp[l][r] < 1e9) return dp[l][r];    // FIX: actually use memoization
    if (match(buf[l], buf[r-1])) dp[l][r] = min(dp[l][r], op(l+1, r-1));
    for (int k=l+1; k<r; ++k) dp[l][r] = min(dp[l][r], op(l, k) + op(k, r));
    return dp[l][r];
}

int main()
{
    scanf("%s", buf);
    N = strlen(buf);
    memset(dp, 0x3f, sizeof dp);
    printf("%lld\n", op(0, N));
}

