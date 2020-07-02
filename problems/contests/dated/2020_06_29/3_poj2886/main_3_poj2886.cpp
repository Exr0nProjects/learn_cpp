/*
 * Problem 3_2886 (contests/dated/2020_06_29/3_2886)
 * Create time: Tue 30 Jun 2020 @ 15:38 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <cmath>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 700111;
ll factors[MX];
void init_factors()
{
    for (ll i=2; i<MX; ++i)
        for (ll j=i; j<MX; j+=i)
            ++factors[j];
}

ll modulo(ll n, ll m)
{
    if (n < 0) return (m - ((-n)%m)) % m;
    else return n % m;
}

ll N, K, card[MX];
ll D, tsum[MX<<1]; // 1 means gap, FIX: segtree is 2x memory
char names[MX][20];

void dump()
{
    //return;
    ll d = D+1;
    for (ll i=1; i<1<<1+D; ++i)
    {
        if (__builtin_popcount(i) == 1) {--d; printf("\n");}
        printf("%3d: %2d  ", i, tsum[i]);
        for (ll i=1; i<1<<d; ++i) printf("         ");
    }
    printf("\n");
}
void update(ll q, ll k=1, ll tl=0, ll tr=(1<<D)-1)
{
    //printf("update %lld @ %lld(%lld..%lld)\n", q, k, tl, tr);
    ll mid = tl + (tr-tl>>1);
    if (tl == tr) { tsum[k] = 0; return; }
    if (q <= mid) update(q, k<<1, tl, mid);
    else update(q, k<<1|1, mid+1, tr);
    tsum[k] = tsum[k<<1] + tsum[k<<1|1];
}
ll query(ll ql, ll qr, ll k=1, ll tl=0, ll tr=(1<<D)-1)
{
    //printf("    query %lld..%lld @ %lld (%lld..%lld)\n", ql, qr, k, tl, tr);
    if (qr < tl || tr < ql) return 0;
    if (ql <= tl && tr <= qr) return tsum[k];
    ll mid = tl + (tr - tl>>1);
    return query(ql, qr, k<<1, tl, mid)
         + query(ql, qr, k<<1|1, mid+1, tr);
}
ll querykth(ll kth, ll k=1, ll tl=0, ll tr=(1<<D)-1)
{
    //printf("    query %lldth @ %lld(%lld..%lld)\n", kth, k, tl, tr);
    if (tl == tr) return tl;
    ll mid = tl + (tr-tl>>1);
    ll lsize = tsum[k<<1];
    //printf("        lsize = %lld\n", lsize);
    //printf("        %lld <= %lld ? %lld\n", kth, lsize, kth <= lsize);
    if (kth <= lsize) return querykth(kth, k<<1, tl, mid);
    else return querykth(kth-lsize, k<<1|1, mid+1, tr); // FIX: typo--k<<1|1 not just k<<1 for right child smah
}

int main()
{
    init_factors();
    while (scanf("%lld%lld", &N, &K) == 2)
    {
        //memset(card, 0, sizeof card);
        memset(tsum, 0, sizeof tsum);
        //memset(names, 0, sizeof names);

        for (ll i=0; i<N; ++i)
            scanf("%s%lld", names[i], &card[i]);
        D = log2(N)+1;
        for (ll i=0; i<N; ++i)
            tsum[i+(1<<D)] = 1;
        for (ll i=(1<<D)-1; i>0; --i)
            tsum[i] = tsum[i<<1] + tsum[i<<1|1];
        //dump();

        ll players=N, maxcandy = 0, winner, cur=K-1;
        for (ll i=1; i<N; ++i)
        {
            --players;
            update(cur);

            ll facts = factors[i];
            if (facts > maxcandy)
            {
                maxcandy = facts;
                winner = cur;
            }

            // remove this player
            ll cur_pos = query(0, cur);
            //printf("pos of %d(%s) = %d\n", cur, names[cur], cur_pos);
            if (card[cur] > 0) --cur_pos;
            //printf("adjusted to %d\n", cur_pos);
            card[cur] = modulo(card[cur], players);
            //printf("stepping %d\n", card[cur]);
            //ll after_me = N-cur-query(cur, N);
            ll nxt = modulo(cur_pos + card[cur], players);
            //printf("expect to be at %d\n", nxt);
            cur = querykth(nxt+1);
            //printf("actual: %d\n\n", cur);
        }
        if (factors[N] > maxcandy)
            printf("%s %lld\n", names[cur], factors[N]+1);
        else
            printf("%s %lld\n", names[winner], maxcandy+1);
    }

	return 0;
}

/*

3 2
a 1
b 1
c 2
-> b, c, a
-> c 2

4 3
a 3
b -2
c -1
d 2
-> c, b, d, a
-> a 3

6 1
a -2
b 4
c -1
d -3
e 2
f 3
-> a, e, b, c, f, d; d 4

6 2
a -2
b 4
c -1
d -3
e 2
f 3
-> b, f, d, e, c, a; a 4

*/
