/*
 * Problem 1_poj2352 (contests/dated/2020_06_29/1_poj2352)
 * Create time: Tue 30 Jun 2020 @ 13:23 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 15111;
const ll MXN = 32111;
ll N, bidx[MXN], ans[MX];

void update(ll n, ll v)
{
    for (; n<=MXN; n+=n&-n)
        bidx[n] += v;
}
ll query(ll n)
{
    ll tot = 0;
    for (; n; n-=n&-n)
        tot += bidx[n];
    return tot;
}

int main()
{
    scanf("%lld", &N);
    for (ll i=0; i<N; ++i)
    {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        //printf("query %d got %d\n", x, query(x+1));
        ++ans[query(x+1)];
        update(x+1, 1);
    }
    for (ll i=0; i<N; ++i)
        printf("%lld\n", ans[i]);

	return 0;
}

