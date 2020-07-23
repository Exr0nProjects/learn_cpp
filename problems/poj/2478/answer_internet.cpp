// https://programtip.com/en/art-35797
#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

const int MX = 1e6 + 100;
int prime[(int)9e4], pcnt=0;
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
    //for (int i=0; i<1e6; ++i) printf("%d\n", nums[i]); return 0;
    for (int d; cin >> d && d;)
    {
        ll sum=0;
        for (int i=0; i<=d; ++i) sum += (ll) nums[i];
        printf("%lld\n", sum);
    }
    return 0;
}

