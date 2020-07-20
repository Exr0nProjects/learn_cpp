/*
 * Problem 2478 (poj/2478)
 * Create time: Mon 20 Jul 2020 @ 11:28 (PDT)
 * Accept time: [!meta:end!]
 *
 * copied from attempt1.cpp
 */

#include <cstdio>
#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define lr tl, (tl+((tr-tl)>>1))
#define rr (tl+((tr-tl)>>1)+1), tr

const int MX = 10e6 + 100;
int prime[(int)8e4], pcnt=0;
int nums[MX];

void sieve()
{
    for (int i=2; i<MX; ++i) {
        if (!nums[i]) {
            nums[i] = i-1;
            prime[pcnt++] = i;
        }
        for (int j=0; i*prime[j]<MX; ++j) {
            //nums[i*prime[j]] = prime[j];
            nums[i*prime[j]] = nums[i] * nums[prime[j]];
            if (i%prime[j] == 0) {
                nums[i*prime[j]] = prime[j]*nums[i];
                break;
            }
        }
        //nums[i] += nums[i-1];
    }
}

int main()
{
    sieve();
    for (int d; ~scanf("%d", &d) && d;)
    {
        ll sum=0;
        for (int i=0; i<=d; ++i) sum += (ll) nums[i];
        //printf("%lld\n", nums[d]);
        printf("%lld\n", sum+2);
    }
}

