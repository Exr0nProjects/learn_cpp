/*
 * Problem 1_poj1970 (contests/dated/2020_07_02/1_poj1970)
 * Create time: Mon 06 Jul 2020 @ 11:20 (PDT)
 * Accept time: Mon 06 Jul 2020 @ 20:54 (PDT)
 *
 */

#include <iostream>
#include <cstring>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 31;
int board[MX][MX];

int is_match(int y, int x)
{
    //printf("ismatch %d %d\n", y, x);
    int src = board[y][x];
    if (!src) return 0;
    int dy[] = {1, 0, 1, -1};
    int dx[] = {0, 1, 1,  1};
    for (int d=0; d<4; ++d)
    {
        if (board[y-dy[d]][x-dx[d]] != src)
        {
            bool legit = 1;
            for (int i=0; i<5; ++i)
                if (board[y+dy[d]*i][x+dx[d]*i] != src)
                    legit = 0;
            if (legit && board[y+dy[d]*5][x+dx[d]*5] != src)
                return src;
        }
    }
    return 0;
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        memset(board, 0, sizeof board); // FIX: clears
        for (int i=1; i<=19; ++i)
            for (int j=1; j<=19; ++j)
                scanf("%d", &board[i][j]);
        bool gone=0;
        for (int i=1; i<=19; ++i)   // FIX: only need to go up to 15, else no space; FIXFIX: actually no there can be horizontals below 15 smah
            for (int j=1; j<=19; ++j)
                if (is_match(i, j))
                {
                    gone = 1;
                    printf("%d\n%d %d\n", board[i][j], i, j);
                    i += 100;   // FIX: abort out of outer loop as well
                    break;
                }
        if (!gone) printf("0\n");   // FIX: no win case
    }

	return 0;
}

