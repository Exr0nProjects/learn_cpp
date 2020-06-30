/*
 * Problem 3_2886 (contests/dated/2020_06_29/3_2886)
 * Create time: Tue 30 Jun 2020 @ 15:38 (PDT)
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

int count_factors(int n)
{
    int i, tot = 0;
    for (i=1; i*i < n; ++i)
        if (n % i == 0) tot += 2;
    if (i*i == n) ++tot;
    return tot;
}

int modulo(int n, int m)
{
    if (n < 0) return (m - (abs(n)%m)) % m;
    else return n % m;
}

ll N, tsum[MX];
void update(ll q, ll k=1, ll tl=1, ll tr=1<<D)
{
    if (q < tl || q > tr) return;
    ll mid = tl + (tr-tl>>1);
    if (tl == tr) ++tsum[k];
    else if (q <= tl) update(q, k<<1, tl, mid);
    else update(q, k<<1|1, mid+1, tr);
    tsum[k] = tsum[k<<1] + tsum[k<<1|1];
}
ll querykth(ll kth, ll k=1, ll tl=1, ll tr=1<<D)
{
    if (tl == tr) return tl;
    ll mid = tl + (tr-tl>>1);
    ll lsize = tsum[k<<1];
    if (kth <= lsize) return querykth(kth, k<<1, tl, mid);
    else return querykth(kth-lsize, k<<1, mid+1, tr);
}

int main()
{
    scanf("%lld", &N);
    for (ll i=1; i<=N; ++i)
        printf("%3d", count_factors(i));

    for (;;)
    {
        ll n, m;
        scanf("%d%d", &n, &m);
        printf("%d %% %d = %d\n", n, m, modulo(n, m));
    }

	return 0;
}

