/*
 * Problem 1276 (poj/1276)
 * Create time: Sat 08 Aug 2020 @ 14:46 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

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
    while (~scanf("%d%d", &M, &N))
    {
        memset(dp, 0, sizeof dp);
        for (int i=1; i<=N; ++i) scanf("%d%d", &c[i], &v[i]);
        dp[0] = 1;
        for (int i=1; i<=N; ++i)
        {
            for (int k=1; k<c[i]; k<<=1)
            {
                for (int j=M; j>=k*v[i]; --j)   // FIX: loop from high to low because bounded knapsack-> 0/1 knapsack not bounded knapsack -> unbounded
                    dp[j] |= dp[j-k*v[i]];
                c[i] -= k;
            }
            for (int j=M; j>=c[i]*v[i]; --j)    // FIX: 0/1 knapsack loops from high to low in rolling array
                dp[j] |= dp[j-c[i]*v[i]];
        }
        for (int i=M; ~i; --i) if (dp[i]) { printf("%d\n", i); break; } // FIX: break on ~i not i because i might go down to zero
    }

	return 0;
}

