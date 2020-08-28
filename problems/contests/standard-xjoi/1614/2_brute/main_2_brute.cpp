/*
 * Problem 2_brute (contests/standard-xjoi/1614/2_brute)
 * Create time: Thu 27 Aug 2020 @ 19:18 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 50;
const int MOD = 1e9+7;

int N;
pair<int, int> p[MX];

int count(int vis)
{
    //printf("\nvis %d\n", vis);
    int tot = 0, pre = 0;
    for (int i=1; i<=N; ++i) if (vis>>i & 1)
    {
        if (pre) {
            //printf("check %d with %d\n", i, pre);
            if (p[pre].f < p[i].s) ++tot;
        }
        pre = i;
    }
    return tot+1;
}

int main()
{
    scanf("%d", &N);
    for (int i=1; i<=N; ++i)
        scanf("%d%d", &p[i].s, &p[i].f);
    sort(p, p+N);
    int tot = 0;
    for (int i=1; i<1<<N; ++i)
        tot = (tot + count(i<<1)) % MOD;

    printf("%d\n", tot);

	return 0;
}

