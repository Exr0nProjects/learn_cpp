/*
 * Problem 2_uva147 (contests/dated/2020_07_02/2_uva147)
 * Create time: Mon 06 Jul 2020 @ 11:37 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
#include <utility>
#include <iterator>
#include <exception>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 6111;
const int coins = 11;
ll waze[MX][coins+10]; // dp[i][j] = ways to get to value i with largest coin value index j
ll waze_comb[MX]; // sum of waze[i]

inline void equ(int i)
{
    //printf("%6d: ", i);
    for (int n=0, d=1; n<coins; d*=10)
        for (int p=1; n<coins && p<5; ++n, p<<=1)
        {   // d*p = each coin value in cents divided by 5
            //printf("n = %3d d*p = %3d\n", n, d*p);
            if (i < d*p) { /*printf("\n");*/ return; }
            //int tot = 0;                // FIX: equ--tot resets every coin value
            for (int j=0; j<=n; ++j)    // every way to get to previous, ending in a smaller coin
            {
                //printf(" +=(%-2d %2d)", i-d*p, j);
                waze[i][n] += waze[i-d*p][j];
            }
            waze_comb[i] += waze[i][n];
        }
    //printf("\n");
}

int main()
{
    waze[0][0] = 1;
    for (int i=1; i<MX; ++i)
        equ(i);

    double target;
    while (scanf("%lf", &target) == 1 && target > 0)
    {
        printf("%6.2lf%17lld\n", target, waze_comb[(int)(target*20)]);
    }

	return 0;
}

