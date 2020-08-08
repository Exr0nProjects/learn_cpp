/*
 * Problem 1276 (poj/1276)
 * Create time: Sat 08 Aug 2020 @ 14:46 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
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
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 10;
const int MXV = 100111;
int N, M, c[MX], v[MX], dp[100111];

int main()
{
    memset(dp, 0, sizeof dp);
    scanf("%d%d", &M, &N);
    for (int i=1; i<=N; ++i) scanf("%d%d", &c[i], &v[i]);
    dp[0] = 1;
    for (int i=1; i<=N; ++i)
    {
        printf("i %d, c[i] = %d\n", i, c[i]);
        for (int j=v[i]; j<=M; ++j)
        {
            for (int k=1; k<c[i]; k<<=1)
                dp[j] |= dp[j-k*v[i]],
                c[i] -= k;
            printf("segfault?\n");
            dp[j] |= dp[j-c[i]*v[i]];
        }
    }
    for (int i=M; i; --i) if (dp[i]) { printf("%d\n", i); break; }

	return 0;
}

