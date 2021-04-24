/*
 * Problem med2 (teamscode_spring_2021/med2)
 * Create time: Sat 24 Apr 2021 @ 14:58 (PDT)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MX = 1e5;

ll pri[MX], pcnt=0; bool sieve[MX];
ll N;

void sev(ll n)
{
    for (int i=2; i<=n; ++i) {
        if (!sieve[i]) pri[pcnt++] = i;
        for (int j=0; j<pcnt && i*pri[j] < MX; ++j) {
            sieve[i*pri[j]] = 1;
            if (i % pri[j] == 0) break;
        }
    }
}

int main()
{
    scanf("%lld", &N);
    sev(sqrt(N)+30);
    //for (int i=0; i<pcnt; ++i) printf("%3d", pri[i]);

    for (int i=0; i<pcnt; ++i) {
        ll cnt = 0;
        while (N % pri[i] == 0) ++cnt, N /= pri[i];
        if (cnt) printf("%lld %lld\n", pri[i], cnt);
    }
    if (N > 1) printf("%lld 1\n", N);
}
