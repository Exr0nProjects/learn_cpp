/*
 * Problem 1252up (uva/1252up)
 * Create time: Mon 27 Jul 2020 @ 12:58 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
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
#define lr tl, (tl+((tr-tl)>>1))
#define rr (tl+((tr-tl)>>1)+1), tr

using namespace std;
const int MX = 11;
const int MXN = 128;

int M, N, arr[MXN];
bool dp[MXN][1<<MX];

int main()
{
    while (~scanf("%d%d", &M, &N) && M && N)
    {
        memset(arr, 0, sizeof arr); // FIX: clear arr, since we don't set it, we just or= it
        char buf[20];
        for (int i=0; i<N; ++i)
        {
            scanf("%s", buf);
            for (int j=0; j<M; ++j)
                if (buf[j]-'0')
                    arr[i] |= 1<<j;
        }

        //for (int x=0; x<1<<M; ++x) dp[0][x] = 1;
        memset(dp, 0xff, sizeof dp);
        for (int i=1; i<N; ++i)
        {
            for (int x=0; x<1<<M; ++x)
            {
                if (!dp[i-1][x])
                    dp[i][x] = 0;
                else
                    for (int j=0; j<i; ++j)
                        if (!((arr[j]&x)^(arr[i])&x))
                            dp[i][x] = 0, j=i;
                //printf("dp[%d][%d] = %d\n", i, x, dp[i][x]);
            }
        }
        int mn=MX+1;
        for (int x=0; x<1<<M; ++x)
            if (dp[N-1][x])
                mn = min(mn, __builtin_popcount(x));
        printf("%d\n", mn);
    }

	return 0;
}

