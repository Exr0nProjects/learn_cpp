/*
 * Problem etf (spoj/etf)
 * Create time: Tue 15 Dec 2020 @ 22:26 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MX = 1e6+10;
ll T, N=MX-10, phi[MX], pri[MX], pcnt=0;
bool vis[MX];

int main()
{
    scanf("%d", &T);
    phi[1] = 1; // FIX: set phi[1]
    for (int i=2; i<=N; ++i)
    {
        if (!phi[i]) pri[++pcnt] = i, phi[i] = i-1;
        for (int j=1; j<=pcnt && i*pri[j] <= N; ++j)    // FIX: j <= pcnt
        {
            phi[i*pri[j]] = phi[i] * phi[pri[j]];
            if (i % pri[j] == 0)
            {
                phi[i*pri[j]] = pri[j]*phi[i];  // FIX: pri[j]*phi[i] not i*phi[pri[j]]
                break;
            }
        }
    }
    while (T--)
    {
        ll x; scanf("%lld", &x);
        printf("%lld\n", phi[x]);
    }
}

