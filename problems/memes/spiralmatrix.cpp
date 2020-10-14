#include <cstdio>
int N, arr[1010][1010];
int main()
{
    scanf("%d", &N);
    for (int i=0; i<=N+1; ++i)
        arr[0][i] = arr[i][0] = arr[i][N+1] = arr[N+1][i] = 1;
    const int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
    int y=1, x=0, p=0;
    for (int i=1; i<N*N; ++i)
    {
        arr[y+=dy[p]][x+=dx[p]] = i;
        while (arr[y+dy[p]][x+dx[p]]) p = (p+1)%4;
    }
    arr[y+dy[p%4]][x+dx[p%4]] = N*N;
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) printf("%3d", arr[i][j]);
        printf("\n");
    }
}

