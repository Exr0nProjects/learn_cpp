/*
 * Problem #7998
 * work division
 */

#include <bits/stdc++.h> // includes "everything"
#include <iostream>
#include <cstdio>
#define ll long long
#define dl double
#define cn const int

using namespace std;

const int MAXSZ = 30;
cn INF = 1000000000;
int cost[MAXSZ][MAXSZ];  // cost of jobs
int state[MAXSZ][MAXSZ]; // dp[i][j] = i problems picked and j = snowflake of avaliable
int best[MAXSZ][MAXSZ];  // best given state [i][j]
int gmn = 0, n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        state[0][i] |= 1 << i;
        best[0][i] = cost[0][i];
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                best[i][j] = INF;
                if (best[i - 1][k] + cost[i][j] < best[i][j] && !((state[i - 1][k] >> (j)) & 1)) // possible error
                {
                    state[i][j] = state[i - 1][k] | (1 << j);
                    best[i][j] = best[i - 1][k] + cost[i][j];
                }
            }
            printf("%d, %d\n", i, j);
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                    printf("%3d", state[i][j]);
                printf("\n");
            }
            printf("\n");
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                    printf("%3d", best[i][j]);
                printf("\n");
            }
            printf("\n");
        }
    }

    gmn = best[n - 1][0];
    for (int i = 1; i < n; ++i)
    {
        gmn = min(gmn, best[n - 1][i]);
    }

    printf("%d", gmn);

    return 0;
}

/*
3
10 2 3
2 3 4
3 4 5
*/
