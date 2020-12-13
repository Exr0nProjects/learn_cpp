/*
 * Problem circlecross (usaco/gold/2017feb/circlecross)
 * Create time: Sat 12 Dec 2020 @ 16:29 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <bits/stdc++.h>
using namespace std;
#define ll int
const ll MX = 5e4+10;

ll N, bit[MX], seen[MX];

void bu(ll x, ll v)
{
    for (; x <= N; x+=x&-x)
        bit[x] += v;
}
ll bq(ll x)
{
    ll ans;
    for (; x; x-=x&-x)
        ans += bit[x];
    return ans;
}

int main()
{
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w+", stdout);
    printf("lolwut\n");
    scanf("%d", &N);
    printf("lolwut\n");
    ll ans = 0;
    for (int i=1; i<=2*N; ++i)
    {
        ll c; scanf("%d", &c);
        if (!seen[c]) bu(c, 1), seen[c] = 1;
        else bu(c, -1), ans += bq(c);
        printf("saw cow %d, now %d\n", c, ans);
    }
    printf("%d\n", ans);
}
