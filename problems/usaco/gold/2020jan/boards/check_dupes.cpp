#include <bits/stdc++.h>
#define ll long long

const ll MX = 50;
ll N, P, vis[MX][MX];

int main()
{
    scanf("%d%d", &N, &P);
    for (int i=1; i<=2*P; ++i)
    {
        int x, y; scanf("%d%d", &x, &y);
        if (vis[x][y]) printf("conflict between %d and %d at %d, %d\n", vis[x][y], i/2, x, y);
        else vis[x][y] = i;
    }
}

