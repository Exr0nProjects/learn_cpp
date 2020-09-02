#include <iostream>

int N, P, d[100010];

int main()
{
    scanf("%d%d", &N, &P);
    for (int i=1; i<=N; ++i) d[i] = 1;
    printf("%d\n", d[1]);
}

