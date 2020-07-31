/*
 * Problem C-more-and-more (contests/zju-icpc/2020summer3/C-more-and-more)
 * Create time: Fri 31 Jul 2020 @ 11:12 (PDT)
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
const ll MX = 1e5+1;
const ll MXM = 50;
ll N, M, K, val[MX], dp[MXM][4];    // dp[i][j][k] = max sum from 1..i but you must take i, j muliplies used, k = whether we are taking this? or not.. rolling array on i
// FIX: hold up, M <= 30? not 1e4??

int main()
{
    scanf("%lld%lld%lld", &N, &M, &K);
    for (int i=1; i<=N; ++i) scanf("%lld", &val[i]);

    for (int i=0; i<=MXM; ++i) dp[i][1] = -1e8;

    ll ret = -1e8;
    for (int i=1; i<=N; ++i)
    {
        for (int j=M; ~j; --j)
        {
            dp[j][0] = max(max(dp[j][0], dp[j][1]), 0ll) + val[i];
            if (j) dp[j][1] = max(max(dp[j][1], dp[j-1][0]), 0ll) + val[i]*K;
            else dp[j][1] = -1e8;
            ret = max(ret, max(dp[j][0], dp[j][1]));
            //printf("(%-2d %2d)  ", dp[i][j][0], dp[i][j][1]);
        }
        //printf("\n");
    }

    printf("%lld\n", ret);

	return 0;
}

