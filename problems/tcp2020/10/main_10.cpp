/*
 * Problem 10 (tcp2020/10)
 * Create time: Sun 19 Jul 2020 @ 09:35 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define lr tl, (tl+((tr-tl)>>1))
#define rr (tl+((tr-tl)>>1)+1), tr

using namespace std;
const ll MX = 2100;
int matrix[MX][MX];

int main()
{
    int N, X, Y;
    scanf("%d%d%d", &N, &X, &Y);
    for (int i=0; i<MX; ++i)
    {
        matrix[i][N+1] = -1;
        matrix[N+1][i] = -1;
        matrix[i][0] = -1;
        matrix[0][i] = -1;
    }

    int y=1, x=0, d=0;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int k=0; k<N*N; ++k)
    {
        int nx=x+dx[d], ny=y+dy[d];
        while (matrix[nx][ny])
        {
            printf("switching directions, now %+d %+d\n", dx[d], dy[d]);
            d = (d+1) %4;
            nx = x+dx[d];
            ny = y+dy[d];
        }
        x = ny; y = nx;
        matrix[x][y] = k+1;
        printf("%d: %d,%d\n", k, nx, ny);
    }

	return 0;
}

