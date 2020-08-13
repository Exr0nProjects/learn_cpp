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

int p, c1, c2, c3, c4;

int main()
{
    while (~scanf("%d%d%d%d%d", &p, &c1, &c2, &c3, &c4) && p)   // FIX: format--5 `%d`s not 4
    {
        int tot = c1 + c2 + c3 + c4;
        p = c1 + 5*c2 + 10*c3 + 25*c4 -p;
        for (; c4 && p >= 25; p-=25) --c4;
        for (; c3 && p >= 10; p-=10) --c3;
        for (; c2 && p >= 5; p-=5) --c2;
        for (; c1 && p >= 1; p-=1) --c1;
        if (p) printf("Charlie cannot buy coffee.\n");
        else printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n", c1, c2, c3, c4);
    }

	return 0;
}

