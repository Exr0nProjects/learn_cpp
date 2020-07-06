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

int is_match(int y, int x)
{
    bool legit = 1;
    int src = board[y][x];
    if (!src) return 0;

    for (int i=0; i<5; ++i)
        if (board[y+i][x] != src)
            legit = 0;
    if (legit) return src;

    legit = 1;
    for (int i=0; i<5; ++i)
        if (board[y][x+i] != src)
            legit = 0;
    if (legit) return src;

    legit = 1;
    for (int i=0; i<5; ++i)
        if (board[y+i][x+i] != src)
            legit = 0;
    if (legit) return src;
    return 0;
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        for (int i=0; i<19; ++i)
            for (int j=0; j<19; ++j)
                scanf("%d", &board[i][j]);
        bool gone=0;
        for (int i=0; i<19; ++i)
            for (int j=0; j<19; ++j)
                if (is_match(i, j))
                    gone=1, printf("%d\n%d %d\n", board[i][j], i+1, j+1);
        if (!gone) printf("0\n");   // FIX: no win case
    }

	return 0;
}

