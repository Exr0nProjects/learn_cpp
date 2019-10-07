/*
what the teacher said
6 oct 2019
f4(n) = min[f4(k)*2+f3(n-k) for k in [0:n]]
*/

#include <bits/stdc++.h>
#define cn const int
using namespace std;
cn MAXSZ = 1000000;
int best3[MAXSZ];
int bestk[MAXSZ];
int best4[MAXSZ];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        best3[i] = (1 << i) - 1;
        printf("%3d", best3[i]);
        best4[i] = MAXSZ;
    }
    printf("\n");

    best4[0] = 0;
    best4[1] = 1;

    for (int i = 1; i < n; ++i)
    {
        for (int k = 1; k < i; ++k)
        {
            printf("%d %d => %d\n", i, k, best4[k] + best3[n - k]);
            if (best4[k] * 2 + best3[n - k] < best4[i])
            {
                bestk[i] = k;
                best4[i] = best4[k] + best3[n - k];
            }
        }
        printf("%d: %d, %d\n\n", i, bestk[i], best4[i]);
    }
}
