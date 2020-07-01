/*
 * Problem 2_poj2481 (contests/dated/2020_06_29/2_poj2481)
 * Create time: Wed 01 Jul 2020 @ 11:55 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstring>
#include <utility>
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
ll prefix(ll n)
{
    ll tot = 0;
    for (; n; n-=n&-n)
        tot += bidx[n];
    return tot;
}

int main()
{
    while (scanf("%lld", &N) == 1 && N)
    {
        memset(cows, 0, sizeof cows);
        memset(bidx, 0, sizeof bidx);
        memset(ans, 0, sizeof ans);
        for (ll i=0; i<N; ++i)
        {
            int s, e;
            scanf("%d%d", &s, &e);
            //scanf("%d%d", &cows[i].f.s, &cows[i].f.f);
            cows[i].f.f = e+1;
            cows[i].f.s = -(s+1);
            cows[i].s = i;
        }
        stable_sort(cows, cows+N, greater<pair<pair<ll, ll>, ll> >());
        ll same_idx=0;
        for (ll i=0; i<N; ++i)
        {
            //printf("cow %d (%d..%d)\n", cows[i].s, -cows[i].f.s-1, cows[i].f.f-1);
            if (cows[same_idx].f != cows[i].f)
            {
                update(-cows[same_idx].f.s, i-same_idx);
                same_idx = i;
            }
            //if (cows[i].f.f+cows[i].f.s != laststr)
            //{
            //    //for (ll j=laststr_idx; j<i; ++j)
            //    //{
            //    //    //printf("    adding cow %d (%d..%d)\n", cows[j].s, -cows[j].f.s-1, cows[j].f.f-1);
            //    //    update(-cows[j].f.s, 1);
            //    //}
            //    update(-cows[laststr_idx].f.s, i-laststr_idx);
            //    laststr = cows[i].f.f+cows[i].f.s;
            //    laststr_idx = i;
            //}
            ans[cows[i].s] = prefix(-cows[i].f.s);
            //printf("weaker than %d\n", ans[cows[i].s]);
        }
        for (ll i=0; i<N; ++i)
            printf("%lld ", ans[i]);
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
6
0 5
2 9
3 5
5 11
6 8
10 12
-> 0 2 0 0 2
-> 0 0 2 0 2 0
*/
