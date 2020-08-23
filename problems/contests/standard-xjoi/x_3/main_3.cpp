/*
 * Problem 3 (contests/standard-xjoi/3)
 * Create time: Sat 22 Aug 2020 @ 21:29 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 310;
int N, w[MX], dp[MX][MX];

int kdp(int l, int r) // inc inc
{
    if (l >= r) return 0;
    int &ret = dp[l][r];
    if (ret) return ret;
    ret = 1<<25;
    for (int m=l; m<r; ++m) // FIX: bounds--m < r not m <= r cuz we use m+1..r
        ret = min(ret, kdp(l, m) + kdp(m+1, r));    // FIX: equ--m+1..r not m..r because else the center is overlapped
    ret += w[r] - w[l-1];
    //printf("%d..%d = %d\n", l, r, ret);
    return ret;
}

int main()
{
    scanf("%d", &N);
    for (int i=1; i<=N; ++i)
        scanf("%d", w+i);
    for (int i=1; i<=N; ++i)
        w[i] += w[i-1];
    printf("%d\n", kdp(1, N));

	return 0;
}

