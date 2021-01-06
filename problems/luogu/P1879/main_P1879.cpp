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
            //if (!(x | (can[i]>>j | i?can[i-1]<<M-j:0)))
        {
            bool bad = 0;
            for (int k=0; k<(i?M:j) && !bad; ++k)
            {
                if (x>>k&1 && x>>(k+1)&1) bad = 1;
                //db("%d %d %d : %d && !(can[%d-%d]->%d >> %d : %d)\n", i, j, k, x>>k&1, i, k>j, can[i-((bool)k>j)], j-k, (can[i-((bool)k>j)]>>(j-k)&1));
                //printf("%d and %d?\n", x>>k&1, !(can[i-((bool)k>j)]>>(j-k)&1));
                if (x>>k&1 && !(can[i-((bool)k>j)]>>(j-k)&1)) bad = 1; // illegal mask
            }
            if (bad) continue;  // FIX: logic--continuing in nested loop smah, need flag var
            //db("%3d - %x\n", i*M+j, x);
            dp[i][j][x] = pre(i, j)[x>>1];
            if (~x&1 && i && can[i-1]>>j&1) (dp[i][j][x] += pre(i, j)[x>>1 | 1<<(M-1)]) %= mod;
            //if (x&1 && ~x>>1&1 && can[i]>>j&1) (dp[i][j][x] += pre(i, j)[x>>1]) %= mod;
        }
    ll ans = 0; for (int x=0; x<1<<M; ++x) (ans += dp[N-1][M-1][x]) %= mod;
    printf("%lld\n", ans);
}
