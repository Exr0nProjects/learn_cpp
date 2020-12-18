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
        scanf("%s%s", str, pat);
        N = strlen(str);
        P = strlen(pat);
        kpi();
        for (int i=0; i<P; ++i) printf("%3d", pi[i]);
    }
}

