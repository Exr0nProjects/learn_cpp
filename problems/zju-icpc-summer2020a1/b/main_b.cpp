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

inline ll choose(ll n, ll k)
{
    ll tot = 1;
    for (ll i=max(k, n-k)+1; i<=n; ++i) { tot *= i; }
    for (ll i=2; i<=min(k, n-k); ++i) { tot /= i; }
    return tot;
}

int main()
{
    int cs; scanf("%d", &cs);
    while (cs--)
    {
        int N; scanf("%d", &N);
        ll n = N;
        printf("%lld\n", n*choose(n-1, 2)*2);
    }

	return 0;
}

