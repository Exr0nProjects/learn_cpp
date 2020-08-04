#include <cstdio>
#define S 4725
short C, G, w[20], d[20], dp[2][S*2];
int main()
{
    scanf("%hd%hd", &C, &G);
    for (short i=1; i<=C; ++i) scanf("%hd", &d[i]);
    dp[0][S] = 1;
    for (short i=1; i<=G; ++i) {
        scanf("%hd", &w[i]);
        //w[i-1] = 0;   // TODO: why does uncommenting this break it?
        for (short j=-S; j<=S; ++j) {
            dp[i&1][j+S] = 0;
            for (short k=1; k<=C; ++k)
                dp[i&1][j+S] += dp[~i&1][j-d[k]*w[i]+S];
        }
    }
    printf("%hd\n", dp[G&1][S]);
}

