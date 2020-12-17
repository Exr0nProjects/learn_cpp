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

int main()
{
    scanf("%d%d", &N, &M);
    for (int s=0; s<2; ++s)
        for (int i=1; i<=N; ++i) scanf("%s", gene[s][i]+1);

    for (int s=0; s<2; ++s)
        for (int i=1; i<=N; ++i) for (int j=1; j<=M; ++j)
            hs[s][i][j][j] = compress(gene[s][i][j]);

    for (int i=1; i<=N; ++i) { for (int j=1; j<=M; ++j) printf("%3d", hs[0][i][j][j]); printf("\n"); }

    for (int s=0; s<2; ++s) for (int i=1; i<=N; ++i)
        for (int n=1; n<N; ++n) for (int j=1; j+n<=N; ++j)
            hs[s][i][j][j+n] =
                (hs[s][i][j][j+n-1] << 2)%mod + hs[s][i][j+n][j+n];
    for (int i=1; i<=N; ++i) { for (int j=1; j<=M; ++j) printf("%20lld", hs[0][i][j][j+1]); printf("\n"); }
}

