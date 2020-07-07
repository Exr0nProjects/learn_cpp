/*
 * Problem 1_poj1970 (contests/dated/2020_07_02/1_poj1970)
 * Create time: Mon 06 Jul 2020 @ 11:20 (PDT)
 * Accept time: [!meta:end!]
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

pair<int, pair<int, int> > is_match(int y, int x)
{
    //printf("ismatch %d %d\n", y, x);
    int src = board[y][x];
    if (!src) return mp(0, mp(0, 0));

    if (board[y-1][x] != src)
    {
        //if (y == 1 && x == 15) printf("vertical!\n");
        bool legit = 1;
        for (int i=0; i<5; ++i)
            if (board[y+i][x] != src)
                legit = 0;
        if (legit && board[y+5][x] != src)  // FIX: cannot be more than 5 in a row
            return mp(5, mp(y, x));
    }

    if (board[y][x-1] != src)
    {
        //if (y == 1 && x == 15) printf("horizontal!\n");
        bool legit = 1;
        for (int i=0; i<5; ++i)
            if (board[y][x+i] != src)
                legit = 0;
        if (legit && board[y][x+5] != src)
            return mp(5, mp(y, x));
    }

    if (board[y-1][x-1] != src)
    {
        //if (y == 1 && x == 15) printf("diagonal down!\n");
        bool legit = 1;
        for (int i=0; i<5; ++i)
            if (board[y+i][x+i] != src)
                legit = 0;
        if (legit && board[y+5][x+5] != src)
            return mp(5, mp(y, x));
    }
    if (board[y+1][x-1] != src)
    {
        //if (y == 1 && x == 15) printf("diagonal up!\n");
        bool legit = 1;
        for (int i=0; i<5; ++i)
            if (board[y-i][x+i] != src)
                legit = 0;
        if (legit && board[y-5][x+5] != src)
            return mp(5, mp(y, x));
    }
    return mp(0, mp(0, 0));
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
            {
                pair<int, pair<int, int> > match = is_match(i, j);
                if (match.f == 5)
                {
                    gone = 1;
                    printf("%d\n%d %d\n", board[match.s.f][match.s.s], match.s.f, match.s.s);
                    i += 100;   // FIX: abort out of outer loop as well
                    break;
                }
            }
        if (!gone) printf("0\n");   // FIX: no win case
    }

	return 0;
}

