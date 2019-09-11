/*
 11 Sep 2019
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 110;
int dist[MAXSZ][MAXSZ]; // represents dist from i to j

int main()
{
    int num = 100; // size

    for (int i = 0; i < num; ++i)
        for (int j = 0; j < num; ++j)
            dist[i][j] = 1000000000; // infinity

    for (int k = 0; k < num; ++k)
    {
        for (int i = 0; i < num; ++i)
        {
            for (int j = 0; j < num; ++j)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                dist[j][i] = dist[i][j];
            }
        }
    }
}
