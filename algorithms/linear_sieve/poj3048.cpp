// 16 July 2020

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MX = 2e4 + 100;
int sieve[MX];
int pri[2300], pcnt=0;
//vector<int> pri;
int main()
{
    //for (int i=2; i<MX; ++i)
    //    if (!sieve[i])
    //        for (int j=1; i*j<MX; ++j)
    //            sieve[i*j] = i;
    for (int i=2; i<MX; ++i)
    {
        if (!sieve[i])
        {
            pri[pcnt] = sieve[i] = i; ++pcnt;
            //pri.push_back(i); sieve[i] = i;
        }
        for (int j=0; j<pcnt && i*pri[j]<MX; ++j)
        //for (int j=0; j<pri.size() && i*pri[j]<MX; ++j)
        {
            //printf("%d: max(%d %d) = %d\n", i*pri[j], pri[j], sieve[i], max(pri[j], sieve[i]));
            sieve[i*pri[j]] = max(pri[j], sieve[i]);
            if (i%pri[j] == 0) break;
        }
        //printf("%3d: %3d\n", i, sieve[i]);
    }
    int N;
    //printf("size: %d\n", pri.size());
    //printf("size: %d\n", pcnt);
    scanf("%d", &N);
    //for (int i=0; i<N; ++i) printf("%3d\n", sieve[i]); return 0;
    //printf("n = %d\n", N);
    int ret=0;  // FIX: can't assume 2 is the smallest, maybe its just one cow labeled 1
    for (int i=0; i<N; ++i)
    {
        int d; scanf("%d", &d);
        //printf("%d->%d better than %d->%d\n", d, sieve[d], ret, sieve[ret]);
        if (!ret || sieve[d] > sieve[ret])
            ret = d;
    }
    printf("%d\n", ret);
    //
    //int n;
    //scanf("%d", &n);
    ////for (int i=0; i<n; ++i) printf("%3d\n", sieve[i]); return 0;
    //int mx = 0, ans;
    //for (int i = 0; i < n; ++i) {
    //    int x;
    //    scanf("%d", &x);
    //    if (sieve[x] > mx) {
    //        mx = sieve[x];
    //        ans = x;
    //    }
    //}
    //printf("%d", ans);

    return 0;
}

