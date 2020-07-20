// 20 July 2020
// math reference: https://codeforces.com/blog/entry/54090

#include <cstdio>
const int MX = 10e6 + 100;
int prime[MX], pcnt=0, nums[MX];

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
    }
}

int main()
{
    sieve();
    for (int i=0; i<100; ++i) printf("%3d: %d\n", i, nums[i]);
}

