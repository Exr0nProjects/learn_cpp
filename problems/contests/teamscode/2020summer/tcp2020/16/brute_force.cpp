#include <iostream>
#include <cstdlib>
#include <cstdio>
const int MX = 16000;
bool grid[MX][MX]; int x[MX], y[MX], level[MX];

int main()
{
    int N; scanf("%d", &N);
    for (int k=0; k<N; ++k)
    {
        scanf("%d%d", &x[k], &y[k]);
        grid[x[k]][y[k]] = 1;
    }
    for (int k=0; k<N; ++k)
    {
        int cnt=0;
        for (int i=0; i<=x[k]; ++i)
            for (int j=0; j<=y[k]; ++j)
                if (grid[i][j]) ++cnt;
        ++level[cnt-1];
    }
    for (int i=0; i<N; ++i)
        printf("%d\n", level[i]);
}

