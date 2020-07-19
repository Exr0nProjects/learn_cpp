#include <iostream>
#include <cstdlib>
#include <cstdio>
const int MX = 16000;
bool grid[MX][MX]; int level[MX];

int main()
{
    int N; scanf("%d", &N);
    for (int k=0; k<N; ++k)
    {
        int x, y; scanf("%d%d", &x, &y);
        int cnt=0;
        for (int i=0; i<=x; ++i)
            for (int j=0; j<=y; ++j)
                if (grid[i][j]) ++cnt;
        ++level[cnt];
        grid[x][y] = 1;
    }
    for (int i=0; i<N; ++i)
        printf("%d\n", level[i]);
}

