#include <cstdio>
#include <cstring>

using namespace std;
#define ll long long
const ll MX = 500111;
ll N, K, card[MX], gone[MX];
char names[MX][20];

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
    if (n < 0) return (m - ((-n)%m)) % m;
    else return n % m;
}

int main()
{
    while (scanf("%lld%lld", &N, &K))
    {
        memset(card, 0, sizeof card);
        memset(gone, 0, sizeof gone);
        memset(names, 0, sizeof names);
        for (ll i=0; i<N; ++i)
            scanf("%s%lld", names[i], &card[i]);

        for (ll i=0; i<N; ++i) printf("\n%s %d\n", names[i], card[i]);

        ll cur=K-1, maxcandy=0;
        for (int i=0; i<N-1; ++i)
        {
            printf("deleting %d\n", cur);
            gone[cur] = 1;
            ll start = cur;
            card[start] = modulo(card[start], N-i-1);
            printf("steps: %d\n", card[start]);
            for (int j=0, cur=0; j<=card[start]; ++cur)
            {
                printf("j %d cur %d gone[cur] %d\n", j, cur, gone[cur]);
                if (!gone[cur]) ++j;
            }
            --cur;
            printf("now deleting %d (%s)\n", cur, names[cur]);
        }
    }
}

