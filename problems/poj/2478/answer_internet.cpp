// https://programtip.com/en/art-35797
#include <iostream>
#include <cstdio>

using namespace std;
//const int maxn = 1000000 + 5;
const int MX = 1e6 + 100;
int nums[MX];

int main()
{
    int n;
    for (int i = 2; i <= 1000000; i++) {
        if (!nums [i] ) {
            for (int j = i ; j <= 1000000 ; j += i) {
                if (!nums [j] )
                    nums[j] = j ;
                nums[j] = nums [j] / i * (i - 1) ;
            }
        }
    }
    for (int i=0; i<1e6; ++i) printf("%d\n", nums[i]); return 0;
    while (cin >> n) {
        if (n == 0) break;
        long long N = 0;//long long存储
        for (int i = 2; i <= n; i++) {
            N += nums[i];
        }
        cout << N << endl;
        //cout << endl;
    }
    return 0;
}

