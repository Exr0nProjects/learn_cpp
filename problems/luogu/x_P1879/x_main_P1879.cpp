/*
 * Problem P1879 (luogu/P1879)
 * Create time: Tue 05 Jan 2021 @ 17:19 (PST)
 * Accept time: [!meta:end!]
 * dp with rolling bitmask to make decisions one cell at a time
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#define ll long long
#define db(...) fprintf(stdout, __VA_ARGS__)
#define pre(i, j) dp[j?i:i-1][j?j-1:M-1]
using namespace std;

const ll MX = 18;
const ll mod = 1e8;
ll N, M, can[MX], dp[MX][MX][1<<MX];

//void print(ll x, char end='\n')
//{
// for (int k=M-1; ~k; --k) db("%2c", x>>k&1 ? '#' : '_'); db("%c", end);
//}

int main()
{
    scanf("%lld%lld", &N, &M);
    for (int i=0; i<N; ++i) for (int j=M-1; ~j; --j)
    {
        int x; scanf("%d", &x);
        if (x) can[i] |= 1<<j;
    }

    dp[0][0][0] = 1; dp[0][0][1] = can[0]>>M-1;
    //dp[0][0][0] = 1; dp[0][0][1] = can[0]>>M-1&1;
    for (int i=0; i<N; ++i) for (int j=i?0:1; j<M; ++j)
    {
        //ll thisans = 0;
        ll opts = (can[i] >> (M-1-j)) | (i? (can[i-1] & ((1<<(M-1-j))-1)) << (j+1) :0);
        //db("%2d %2d: ", i, j); print(opts);
        dp[i][j][0] = pre(i, j)[0] + pre(i, j)[1<<M-1];
        for (int x=opts; x; x = (x-1)&opts)
        {
            if (x%4 < 3 || !j) (dp[i][j][x] += pre(i, j)[x>>1]) %= mod; // FIX: condition--add ||!j bc if j==0 then side condition doesn't matter
            if (~x&1 && i/* && can[i-1]>>j&1 */) (dp[i][j][x] += pre(i, j)[x>>1 | 1<<(M-1)]) %= mod;   // FIX: don't need to check prev row for cell positive anymore
            //db("     > "); print(x, ' '); db("%3d\n", dp[i][j][x]);
            //thisans += dp[i][j][x];
        }
        //db("%2d %2d finally got %d + %d\n", i, j, thisans, dp[i][j][0]);
    }
    ll ans = 0; for (int x=0; x<1<<M; ++x) (ans += dp[N-1][M-1][x]) %= mod;
    printf("%lld\n", ans);
}

