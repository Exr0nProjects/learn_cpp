/*
 * Problem 2_poj2481 (contests/dated/2020_06_29/2_poj2481)
 * Create time: Wed 01 Jul 2020 @ 11:55 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
#include <utility>
#include <iterator>
#include <exception>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 100111;
pair<pair<ll, ll>, ll> cows[MX];  // <end, -start>, og_idx
ll N, bidx[MX], ans[MX];

void update(ll n, ll v)
{
    for (; n<=MX; n+=n&-n)
        bidx[n] += v;
}
ll query(ll l, ll r)
{
    ll tot = 0; --l;
    for (; r>l; r-=r&-r)
        tot += bidx[r];
    for (; l>r; l-=l&-l)
        tot -= bidx[l];
    return tot;
}

int main()
{
    while (scanf("%lld", &N) == 1 && N)
    {
        memset(cows, 0, sizeof cows);
        memset(bidx, 0, sizeof bidx);
        for (ll i=0; i<N; ++i)
        {
            scanf("%lld%lld", &cows[i].f.s, &cows[i].f.f);
            ++cows[i].f.f; ++cows[i].f.s;
            cows[i].f.s *= -1;
            cows[i].s = i;
        }
        sort(cows, cows+N);
        ll lastend = 0, lastend_idx=0;
        for (ll i=0; i<N; ++i)
        {
            printf("cow %d (%d..%d)\n", cows[i].s, -cows[i].f.s-1, cows[i].f.f-1);
            if (cows[i].f.f != lastend)
            {
                for (ll j=lastend_idx; j<i; ++j)
                {
                    printf("    adding cow %d (%d..%d)\n", cows[j].s, -cows[j].f.s-1, cows[j].f.f-1);
                    update(-cows[j].f.s, 1);
                }
                lastend = cows[i].f.f;
                lastend_idx = i;
            }
            ans[cows[i].s] = query(-cows[i].f.s, cows[i].f.f);
            printf("stronger than %d\n", ans[cows[i].s]);
        }
        for (ll i=0; i<N; ++i)
        {
            if (i) printf(" ");
            printf("%lld", ans[i]);
        }
        printf("\n");
    }

	return 0;
}

/*

5
0 4
1 3
1 6
3 7
3 5
-> 1 0 2 1 0

6
0 5
2 9
3 5
5 11
6 8
10 12
-> 1 2 0 1 0 0
*/
