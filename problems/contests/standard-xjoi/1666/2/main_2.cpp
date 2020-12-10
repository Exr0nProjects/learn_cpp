/*
 * Problem 2 (contests/standard-xjoi/1666/2)
 * Create time: Wed 09 Dec 2020 @ 17:18 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <bits/stdc++.h>
#define nt long long
#define mp make_pair
#define F(i, n) for (nt i=1; i<=n; ++i)
using namespace std;

const nt MX = 1e5+11;
const nt MXE = MX<<2;
const nt mod = 1e9+7;
nt N, K;
nt aprod[MX], asum[MX];
struct Edge { nt t, n; } eg[MXE]; nt hd[MX], ecnt=2;
void addEdge(nt u=0, nt v=0, bool b=1)
{
    if (!v) scanf("%lld%lld", &u, &v);
    eg[ecnt] = { v, hd[u] };
    hd[u] = ecnt++;
    if (b) addEdge(v, u, 0);
}

//nt sz[MXE][16], dp[MXE][16];
//nt op(nt e, nt p=0, nt k=K)
//{
//    printf("at %d from %d for %d\n", eg[e].t, p, k);
//    if (k == 0) return dp[e][k] = 1;
//    if (sz[e][k]) return sz[e][k];
//    sz[e][k] = 1; op(e, p, k-1); dp[e][k] = dp[e][k-1];
//    for (nt n=hd[eg[e].t]; n; n=eg[n].n) if (eg[n].t != p)
//            sz[e][k] += op(n, eg[e].t, k-1), dp[e][k] += dp[n][k-1];
//    return sz[e][k];
//}

pair<nt, nt> solve(nt c, nt p=0, nt k=K)
{
    if (!k) return mp(1, 1);
    nt prod = 1, sum = 1;
    for (int e=hd[c]; e; e=eg[e].n)
        if (eg[e].t != p)
        {
            nt pr, sm; tie(pr, sm) = solve(eg[e].t, c, k-1);
            sum += sm; (prod *= pr) %= mod;
        }
    return mp(prod * sum % mod, sum % mod);
}

int main()
{
    scanf("%lld%lld", &N, &K);
    F(i, N-1) addEdge();

    F(i, N) tie(aprod[i], asum[i]) = solve(i);
    F(i, N) printf("%lld ", asum[i]); printf("\n");
    F(i, N) printf("%lld ", aprod[i]); printf("\n");

    //for (int i=N; i; --i) addEdge(0, i, 0);
    //for (nt e=hd[0]; e; e=eg[e].n)
    //    printf("%d ", op(e)); printf("\n");
    //for (nt e=hd[0]; e; e=eg[e].n)
    //    printf("%d ", dp[e][K]); printf("\n");
    //
    //F(i, K+1) { for (nt e=hd[0]; e; e=eg[e].n) printf("%3d", dp[e][i-1]); printf("\n"); }
}

