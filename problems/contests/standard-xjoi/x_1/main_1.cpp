/*
 * Problem 1 (contests/standard-xjoi/1)
 * Create time: Sat 22 Aug 2020 @ 21:16 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 1010;
int N, grid[MX][MX];

int main()
{
    scanf("%d", &N);
    int y, x, v;
    while (scanf("%d%d%d", &y, &x, &v) && y)
    {
        grid[y][x] = v;
    }
    for (int i=1; i<=N; ++i) for (int j=1; j<=N; ++j) grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
    printf("%d\n", grid[N][N]);

	return 0;
}

