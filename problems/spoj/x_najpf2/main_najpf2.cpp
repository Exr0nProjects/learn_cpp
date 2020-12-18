/*
 * Problem najpf2 (spoj/najpf2)
 * Create time: Thu 17 Dec 2020 @ 22:15 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MX = 1e6;

ll T, N, P, pi[MX];
ll ans[MX], acnt=0;
char str[MX], pat[MX];

void kpi()
{
    pi[0] = -1;
    for (int i=1; i<P; ++i)
    {
        for (pi[i]=pi[i-1]; ~pi[i] && pat[pi[i]+1] != pat[i];
                pi[i] = pi[pi[i]]);
        if (pat[pi[i]+1] == pat[i]) ++pi[i];
    }
}

int main()
{
    scanf("%lld", &T);
    while (T--)
    {
        acnt=0; // FIX: clears
        scanf("%s%s", str, pat);
        N = strlen(str);
        P = strlen(pat);
        //printf("N %d P %d\n", N, P);
        kpi();
        //for (int i=0; i<P; ++i) printf("%3d", pi[i]);
        ll c = -1;   // c = prev match; FIX: start at -1 like the kpi fxn
        for (int i=0; i<N; ++i)
        {
            for (; ~c && pat[c+1] != str[i];
                    c = pi[c]);
            if (pat[c+1] == str[i]) ++c;
            if (c+1 == P)
                //printf("end match at %d\n", i),
                    ans[++acnt] = i-P+2;
        }
        if (!acnt) { printf("Not Found\n\n"); continue; }
        printf("%d\n", acnt);
        for (int i=1; i<=acnt; ++i) printf("%d ", ans[i]); printf("\n\n");
    }
}

