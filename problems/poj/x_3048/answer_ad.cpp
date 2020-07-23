#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <utility>
#include <map>
#include <list>
using namespace std;
typedef pair <int, int> pii;
#define f first
#define s second
const int MX = 2e4 + 100;
int sieve[MX];// pri[MX], pcnt=0;
vector <int> pri;

int main() {
    for (int i=2; i<MX; ++i)
    {
        if (!sieve[i])
        {
            //pri[pcnt++] = sieve[i] = i;
            pri.push_back(i);
            sieve[i] = i;
        }
        for (int j = 0; j < pri.size(); ++j) {
            if (i * pri[j] < MX) sieve[i * pri[j]] = max(pri[j], sieve[i]);
            if (i % pri[j] == 0) break;
        }
    }
    int N;
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

    return 0;
}

