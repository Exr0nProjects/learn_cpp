/*
 * Problem P1879 (luogu/P1879)
 * Create time: Tue 05 Jan 2021 @ 17:19 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#define ll long long
#define db(...) fprintf(stdout, __VA_ARGS__)
#define pre(i, j) dp[j?i:i-1][j?j-1:M-1]
using namespace std;

const ll MX = 13;
const ll mod = 1e8;
ll N, M, can[MX], dp[MX][MX][1<<MX];

void print(ll x)
{
    for (int i=0; i<M; ++i) db("%2c", x>>i&1 ? '#' : '_');
}

int main()
{
    scanf("%lld%lld", &N, &M);
    for (int i=0; i<N; ++i) for (int j=0; j<M; ++j)
    {
        int x; scanf("%d", &x);
        if (x) can[i] |= 1<<j;
    }
    //for (int i=0; i<N; ++i) { for (int j=0; j<M; ++j) db("%3d", can[i]>>j&1); db("\n"); }
    //for (int x=0; x<1<<MX; ++x) dp[0][0][x] = 1;
    dp[0][0][0] = 1; dp[0][0][1] = can[0]&1;
    for (int i=0; i<N; ++i) for (int j=i?0:1; j<M; ++j)
        for (int x=0; x<(1<<(i*M+j+1)); ++x)
        {
            db("%2d %2d: ", i, j); print(i?can[i-1]:0); db(","); print(can[i]); db("\n");
            print(can[i]>>j | i?can[i-1]<<M-j:0); db("\n"); print(x); db("\n");
            if (!(x | ~(can[i]>>j | i?can[i-1]<<M-j:0)))
            {
                db("%3d - %x\n", i*M+j, x);
                dp[i][j][x] = pre(i, j)[x>>1] + pre(i, j)[x>>1 | 1<<(M-1)];
                if (x&1 && ~x>>1&1 && can[i]>>j&1) (dp[i][j][x] += pre(i, j)[x>>1]) %= mod;
            }
        }
    ll ans = 0; for (int x=0; x<1<<MX; ++x) (ans += dp[N-1][M-1][x]) %= mod;
    printf("%lld\n", ans);
}
