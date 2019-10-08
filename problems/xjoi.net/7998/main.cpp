/*
 * Problem #7998
 * work division
 */

#include <bits/stdc++.h> // includes "everything"
#include <iostream>
#include <cstdio>
#define ll long long
#define dl double

using namespace std;

const int MAXSZ = 30;

int dfs (const int cost[][MAXSZ], bool able[], const int siz, const int sum, const int rem)
{
    static int mmin = 1000000000;
    
    if (rem == 0 && sum < mmin) mmin = sum; // exit case
    if (sum > mmin || rem == 0) return mmin; // returns, the first part is an optimization (we cant get better if the sum is already over)
    
 //d   printf("    rem: %d, sum: %d\n", rem, sum);
    
    for (int i=0; i<siz; ++i)
    {
        if (!able[i])
        {
 //d           printf("       propogating with rem: %d, wrk: %d\n", rem-1, i);
            able[i] = true;
            dfs (cost, able, siz, sum+cost[rem-1][i], rem-1);
            able[i] = false;
        }
    }
    return mmin;
}


int main ()
{
    int cost[MAXSZ][MAXSZ];
    bool able[MAXSZ] = { };
    
    int size, temp; 
    scanf("%2d", &size);
    
    for (int i=0; i<size; ++i) 
        for (int j=0; j<size; ++j)
            cin >> cost[i][j];
    
    printf("%d", dfs(cost, able, size, 0, size));
}
