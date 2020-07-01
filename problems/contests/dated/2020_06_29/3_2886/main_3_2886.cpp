/*
 * Problem 3_2886 (contests/dated/2020_06_29/3_2886)
 * Create time: Tue 30 Jun 2020 @ 15:38 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <cmath>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 500111;   // TODO: several cases

//int factors[MX], max_factors[MX];
//void get_factors(int N)
//{
//    for (int i=2; i<MX; ++i)
//    {
//        printf("%lld\n", i);
//        for (int j=i; j<MX; ++j)
//            ++factors[j];
//        max_factors[i] = max(max_factors[i-1], factors[i]);
//    }
//}


ll count_factors(ll n)
{
    ll i, tot = 0;
    for (i=1; i*i < n; ++i)
        if (n % i == 0) tot += 2;
    if (i*i == n) ++tot;
    return tot;
}

ll modulo(ll n, ll m)
{
    if (n < 0) return (m - (abs(n)%m)) % m;
    else return n % m;
}

ll N, K, circle[MX], card[MX];
ll D, tsum[MX]; // 1 means gap
char names[MX][20]; // TODO: max name len

void dump()
{
    return;
    ll d = D+1;
    for (ll i=1; i<1<<1+D; ++i)
    {
        if (__builtin_popcount(i) == 1) {--d; printf("\n");}
        printf("%3d", tsum[i]);
        for (ll i=1; i<1<<d; ++i) printf("   ");
    }
    printf("\n");
}
void update(ll q, ll k=1, ll tl=0, ll tr=(1<<D)-1)
{
    //printf("update %d @ %d(%d..%d)\n", q, k, tl, tr);
    ll mid = tl + (tr-tl>>1);
    if (tl == tr) ++tsum[k];
    else
    {
        if (q <= mid) update(q, k<<1, tl, mid);
        else update(q, k<<1|1, mid+1, tr);
        tsum[k] = tsum[k<<1] + tsum[k<<1|1];
    }
}
ll querykth(ll kth, ll k=1, ll tl=0, ll tr=(1<<D)-1)
{
    //printf("query %dth @ %d(%d..%d)\n", kth, k, tl, tr);
    if (tl == tr) return tl;
    ll mid = tl + (tr-tl>>1);
    ll lsize = mid-tl+1-tsum[k<<1];
    if (kth <= lsize) return querykth(kth, k<<1, tl, mid);
    else return querykth(kth-lsize, k<<1, mid+1, tr);
}

int main()
{
    scanf("%lld%lld", &N, &K);
    for (ll i=0; i<N; ++i)
        scanf("%s%d", names[i], &card[i]);
    D = log2(N)+1;

    ll players=N, maxcandy = 0, winner, cur=K-1;
    for (ll i=1; i<N; ++i)
    {
        //printf("removing %d\n", cur);
        --players;
        update(cur);
        dump();

        //printf("    i %d players %d cur %d\n", i, players, cur);
        ll factors = count_factors(i);
        if (factors > maxcandy)
        {
            //printf("update: winner is %d with %d candy\n", cur, factors);
            maxcandy = factors;
            winner = cur;
        }
        ll nxt = modulo(cur-1 + modulo(card[cur], players), players);
        //printf("    next up: (%d + %d) %% %d = %lld\n", cur, card[cur], players, nxt);
        //printf("    next up: %d -1 + %d %% %d = %d + %d = %lld\n", cur, card[cur], players, cur-1, modulo(card[cur], players), nxt);
        cur = querykth(nxt+1);
        //printf("    ==> %lld\n", cur);
    }
    if (count_factors(N) > maxcandy)
        printf("%s %d\n", names[cur], count_factors(N));
    else
        printf("%s %d\n", names[winner], maxcandy);

	return 0;
}

/*

3 2
a 1
b 1
c 2
-> b, c, a

*/
