/*
 * Problem b (zju-icpc-summer2020a1/b)
 * Create time: Sun 12 Jul 2020 @ 19:23 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const ll mod = 10e9 + 7;

inline ll choose(ll n, ll k)
{
    ll tot = 1;
    for (ll i=max(k, n-k)+1; i<=n; ++i) { tot = i*tot % mod; }
    for (ll i=2; i<=min(k, n-k); ++i) { tot = tot/i % mod; }
    return tot;
}

int main()
{
    int cs; scanf("%d", &cs);
    while (cs--)
    {
        int N; scanf("%d", &N);
        ll n = N;
        printf("%lld\n", ((n*choose(n-1, 2))%mod)*2 % mod);
    }

	return 0;
}

