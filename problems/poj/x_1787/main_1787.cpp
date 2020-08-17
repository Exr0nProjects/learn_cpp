/*
 * Problem 1787 (poj/1787)
 * Create time: Wed 12 Aug 2020 @ 21:14 (PDT)
 * Accept time: [!meta:end!]
 *  we know that we can do minimum number of coins greedily since lowest denomination divides all others,
 *  but how can we do maximum? what if you sum the value you have and use minimum coins to get sum-p?
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MXV = 10111;
int p, c1, c2, c3, c4;
int pre[5][MXV], dp[MXV];

void kp(int i, int c, int w)
{
    for (int k=1; k<c; k<<=1)
    {
        for (int j=p; j>=k*w; --j)  // FIX: bounds--don't start at tot cuz that can be overflow
        {
            if (dp[j] < dp[j-k*w]+k)
                dp[j] = dp[j-k*w]+k,
                pre[i][j] = pre[i][j-k*w] + k;
            //if (dp[j] > 0) printf("%3d", dp[j]); else printf("  -");
        }
        //printf("\n");
        c -= k;
    }
    for (int j=p; j>=c*w; --j)
    {
        if (dp[j] < dp[j-c*w]+c)
            dp[j] = dp[j-c*w]+c,
            pre[i][j] = pre[i][j-c*w] + c;
        //if (dp[j] > 0) printf("%3d", dp[j]); else printf("  -");
    }
    //printf("\n");
}

int main()
{
    while (~scanf("%d%d%d%d%d", &p, &c1, &c2, &c3, &c4) && p)   // FIX: format--5 `%d`s not 4
    {
        //printf("\n");
        memset(dp, 0x8f, sizeof dp);
        memset(pre, 0, sizeof pre);
        dp[0] = 0;
        //for (int i=tot; i > 0; --i) printf("%3d", i); printf("\n");
        kp(1, c1, 1);
        kp(2, c2, 5);
        kp(3, c3, 10);
        kp(4, c4, 25);
        //printf("\n");
        //for (int i=1; i<=4; ++i) { for (int j=tot; j>0; --j) if (pre[i][j]) printf("%3d", pre[i][j]); else printf(" "); printf("\n"); }
        if (dp[p] <= 0) { printf("Charlie cannot buy coffee.\n"); continue; }   // FIX: continue not return cuz multi-cases
        c4 = pre[4][p]; p -= c4*25;
        c3 = pre[3][p]; p -= c3*10;
        c2 = pre[2][p]; p -= c2*5;
        c1 = pre[1][p]; p -= c1*1;
        printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n", c1, c2, c3, c4);
    }

	return 0;
}

