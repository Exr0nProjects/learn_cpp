/*
 * Problem 3 (tcp2020b/3)
 * Create time: Wed 22 Jul 2020 @ 19:04 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <cmath>
#include <math.h>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define lr tl, (tl+((tr-tl)>>1))
#define rr (tl+((tr-tl)>>1)+1), tr

using namespace std;
const ll MX = -1;

int main()
{
    int N;
    scanf("%d", &N);
    for (int i=2; i<N; ++i)
    {
        int tot=0;
        for (int j=1; j<=1+sqrt(N); ++j)
        {
            if (i%j == 0) { tot += i + i/j;// }
            printf("%d %d\n", i, j/i); }
        }
        printf("tot %d\n", tot);
        if (tot == i*2) printf("%d\n", i);
    }

	return 0;
}

