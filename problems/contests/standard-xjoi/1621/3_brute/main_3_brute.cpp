/*
 * Problem intest (spoj/intest)
 * Create time: Sun 30 Aug 2020 @ 11:26 (PDT)
 * Accept time: [!meta:end!]
 *
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb(x) ((x)&-(x))

#define F(i,b) for (ll i=1; i<=(b); ++i)
#define R(i,b) for (ll i=(b); i>=1; --i)
//struct Edge { int f, t, n; } edges[-1]; int head[-1];

#define _gc getchar_unlocked
inline bool sc(ll &n)
{
    int neg = 1;
    register char c;
    do c = _gc(); while (isspace(c));
    if (c == '-') neg = -1, c = _gc();
    for (n=0; c >= '0' && c <= '9'; c=_gc())
        (n *= 10) += (c-'0');
    n *= neg;
    return c != EOF;
}
#define _ilb inline bool
_ilb sc(int &a) { ll x; bool b=sc(x); a=x; return b; }
_ilb sc(int &a, int &b) { return sc(a)&&sc(b); }
_ilb sc(int &a, int &b, int &c) { return sc(a, b)&&sc(c); }
_ilb sc(ll &a, ll &b) { return sc(a)&&sc(b); }
_ilb sc(ll &a, ll &b, int &c) { return sc(a, b)&&sc(c); }

using namespace std;
const int MX = 1e5+11;
const int MXM = 32;

int N, M, K, cv[MXM][MXM], cvsum[MX][MXM], dp[MX];
char S[MX];

int main()
{
    sc(N, M, K);
    scanf("%s", S+1);
    //for (int i=1; i<=M; ++i) for (int j=1; j<=M; ++j)
    memset(cv, 0x3f, sizeof cv);
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0; // FIX: base case
    F(i, M) F(j, M) sc(cv[i][j]);
    F(k, M) F(i, M) F(j, M)
        cv[i][j] = min(cv[i][j], cv[i][k] + cv[k][j]);

    for (int c=1; c<=M; ++c)
    //{ printf("c = %d   ", c);
        for (int i=1; i<=N; ++i)
        {
            cvsum[i][c] = cvsum[i-1][c] + cv[S[i]-96][c];
            if (i >= K) cvsum[i][c] -= cv[S[i-K+1]-96][c];
            fprintf(stderr, "%d\n", cvsum[i][c]);
            //printf(" (+%d)", cv[S[i]-96][c]);
            //if (i > K) printf(" (-%d)", cv[S[i-K]-96][c]);
            //printf("%3d", cvsum[i][c]);
        }
    //printf("\n");}
    //printf("%d \n", cvsum[3][1]);
    //F(i, M) { F(j, M) printf("%3d", cv[i][j]); printf("\n"); }
    for (int i=K; i<=N; ++i)
        for (int c=1; c<=M; ++c)
        {
            int cost = cvsum[i][c]; // FIX: typo--cvsum not cv
            //cost = 0;
            //int cost = 0;
            //printf("i %d c %d cost %d\n", i, c, cost);
            //for (int k=0; k<i; ++k)
            for (int k=K-1; k<i; ++k)
            {
                cost += cv[S[i-k]-96][c];
                //printf("+= %d (%d) cost to conv %d..%d to %c = %d\n", S[i-k]-96, cv[S[i-k]-96][c], i-k, i, c+96, cost);
                if (cost > dp[i]) break;
                //printf("k = %d\n", k+1);
                if (k+1 >= K) dp[i] = min(dp[i], dp[i-k-1] + cost);
            }
            //printf("dp[%d] = %d\n", i, dp[i]);
        }
    printf("%d\n", dp[N]);
}

