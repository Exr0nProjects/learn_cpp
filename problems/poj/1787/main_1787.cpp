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
int tot, dp[MXV];

void kp(int c, int w)
{
    for (int k=1; k<c; k<<=1)
    {
        for (int j=tot; ~j; --j)
            dp[j] = max(dp[j], dp[j-k*w]+k);
        c -= k;
    }
    for (int j=tot; ~j; --j)
        dp[j] = max(dp[j], dp[j-c*w]+c);
}

int main()
{
    while (~scanf("%d%d%d%d%d", &p, &c1, &c2, &c3, &c4) && p)   // FIX: format--5 `%d`s not 4
    {
        tot = c1 + 5*c2 + 10*c3 + 25*c4;
        kp(c1, 1);
        kp(c2, 5);
        kp(c3, 10);
        kp(c4, 25);
        if () printf("Charlie cannot buy coffee.\n");
        else printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n", c1, c2, c3, c4);
    }

	return 0;
}

