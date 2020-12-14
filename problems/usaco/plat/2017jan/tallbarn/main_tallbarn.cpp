/*
 * Problem tallbarn (usaco/plat/2017jan/tallbarn)
 * Create time: Sun 13 Dec 2020 @ 16:20 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MX = 1e5+10;

ll N, K, a[MX];

bool check(ll x)
{
    ll rem = K;
    for (int i=1; i<=N; ++i)
        rem -= a[i]/(x+1) +1;
    return rem >= 0;
}

int main()
{
    scanf("%lld%lld", &N, &K);
    for (int i=1; i<=N; ++i) scanf("%lld", a+i);

    ll l=0, r=1e5, m;
    for (; l+1 < r; (check(m)?r:l)=m)
        m = l + (r-l>>1);
    printf("%d\n", r);
}

