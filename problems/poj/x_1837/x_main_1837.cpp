/*
 * Problem 1837 (poj/1837)
 * Create time: Tue 04 Aug 2020 @ 13:59 (PDT)
 * Accept time: Tue 04 Aug 2020 @ 14:30 (PDT)
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
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
const int MX = 20;
int C, G, w[MX], d[MX], dps[2][7500<<1];

int &dp(int i, int j)
{
    return dps[i&1][j+7500];
}

int main()
{
    scanf("%d%d", &C, &G);
    for (int i=1; i<=C; ++i) scanf("%d", &d[i]);
    for (int i=1; i<=G; ++i) scanf("%d", &w[i]);

    dp(0, 0) = 1;
    for (int i=1; i<=G; ++i)
        for (int j=-7500; j<=7500; ++j)
        {
            dp(i, j) = 0;   // FIX: rolling array clears-- reset dp(i, j) because we only add to it later
            for (int k=1; k<=C; ++k)
                dp(i, j) += dp(i-1, j-d[k]*w[i]);
        }

    printf("%d\n", dp(G, 0));

	return 0;
}

