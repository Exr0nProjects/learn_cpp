/*
 * Problem 1948 (poj/1948)
 * Create time: Sat 15 Aug 2020 @ 11:48 (PDT)
 * Accept time: Sat 15 Aug 2020 @ 12:24 (PDT)
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <numeric>
#include <algorithm>

#define ll long long
#define dl double

using namespace std;
const int MX = 45;
const int MXL = 810;    // not MX*MX because an edge can't be more than half the total length
int N, a[MX];
bool dp[MXL][MXL];

inline dl herons(dl a, dl b, dl c)
{
    dl s = (a+b+c)/2;
    if (a >= s || b >= s || c >= s) return -0.01;
    //printf("%5.2lf %5.2lf %5.2lf  ", a, b, c);
    //printf("%5.2lf -> %5.2lf * %5.2lf * %5.2lf * %5.2lf -> %5.5lf\n", s, s,(s-a),(s-b),(s-c), sqrt(s*(s-a)*(s-b)*(s-c)));
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
    scanf("%d", &N);
    for (int i=1; i<=N; ++i) scanf("%d", a+i);
    //for (int i=1; i<=N; ++i) printf("%3d", a[i]); printf("\n");

    int sum = 0;
    dl mx = -0.01;
    dp[0][0] = 1;
    for (int i=1; i<=N; sum += a[i], ++i)   // FIX: only add to sum once per item; FIX: add to sum BEFORE incrementing i
    {
        for (int j=MXL-1; ~j; --j)          // FIX: start at MXL-1 because array is 0-indexed so this is out of bounds
            for (int k=MXL-1; ~k; --k)
            {
                if (j >= a[i]) dp[j][k] |= dp[j-a[i]][k];
                if (k >= a[i]) dp[j][k] |= dp[j][k-a[i]];
                if (dp[j][k]) {
                    mx = max(mx, herons(j, k, sum+a[i]-j-k));   // FIX: need +a[i] here because the addition in the for loop happens after each iteration
                }
            }
    }
    printf("%d\n", (int)(mx*100));

	return 0;
}

