/*
 * Problem cownomics (usaco/gold/2017open/cownomics)
 * Create time: Wed 16 Dec 2020 @ 17:40 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MX = 510;
const ll mod = 1e17+3;  // prime :)
ll N, M, hs[2][MX][MX][MX];
char gene[2][MX][MX];

ll compress(char &c)
{
    switch (c)
    {
        case 'G': return 0;
        case 'C': return 1;
        case 'A': return 2;
        case 'T': return 3;
    }
}

bool check(ll len)
{
    printf("check %d\n", len);
    set<ll> vis;
    for (int j=1; j+len <= M; ++j)
    {
        vis.clear();
        bool good = 1;
        for (int i=1; i<=N; ++i)
            vis.insert(hs[0][i][j][j+len]);
        for (int i=1; i<=N; ++i)
            if (vis.count(hs[1][i][j][j+len]))
            { good = 0; break; }
        if (good) return 1;
    }
    printf("no \n");
    return 0;
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int s=0; s<2; ++s)
        for (int i=1; i<=N; ++i) scanf("%s", gene[s][i]+1);

    for (int s=0; s<2; ++s)
        for (int i=1; i<=N; ++i) for (int j=1; j<=M; ++j)
            hs[s][i][j][j] = compress(gene[s][i][j]);

    for (int i=1; i<=N; ++i) { for (int j=1; j<=M; ++j) printf("%3d", hs[0][i][j][j]); printf("\n"); }

    for (int s=0; s<2; ++s) for (int n=1; n<M; ++n)
    {
        for (int i=1; i<=N; ++i) for (int j=1; j+n<=M; ++j) // FIX: typo-- some should be <= M not <= N
            //printf("%d << 2 + %d = %d\n", hs[s][i][j][j+n-1], hs[s][i][j+n][j+n], (hs[s][i][j][j+n-1] << 2)%mod + hs[s][i][j+n][j+n]),
            hs[s][i][j][j+n] =
                (hs[s][i][j][j+n-1] << 2)%mod + hs[s][i][j+n][j+n];
        //for (int i=1; i<=N; ++i) { for (int j=1; j<=M; ++j) printf("%20lld", hs[0][i][j][j+n]); printf("\n"); } printf("\n\n");
    }
    ll l=0, r=M-1, m;
    for (; l+1 <= r; (check(m)?r:l) = m)
        m = l + (r-l>>1);
    printf("%d\n", r);
}

