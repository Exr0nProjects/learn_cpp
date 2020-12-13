/*
 * Problem circlecross (usaco/gold/2017feb/circlecross)
 * Create time: Sat 12 Dec 2020 @ 16:29 (PST)
 * Accept time: Sat 12 Dec 2020 @ 17:12 (PST)
 *
 */

#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e6+10;

long long N, bit[MX], cows[MX], seen[MX];

void bu(long long x, long long v)
{
    for (; x <= N; x+=x&-x)
        bit[x] += v;
}
long long bq(long long x)
{
    long long ans = 0; // FIX: init var smah
    for (; x; x-=x&-x)
        //printf("    at %d, ans %d\n", x, ans),
        ans += bit[x];
    return ans;
}

int main()
{
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w+", stdout);
    scanf("%d", &N);
    vector<pair<long long, long long> > renum(N);
    for (int i=1; i<=2*N; ++i)
    {
        long long c; scanf("%lld", &c);
        if (renum[c-1].first) renum[c-1].second = i;
        else renum[c-1].first = i;
    }
    sort(renum.begin(), renum.end());
    for (int i=0; i<N; ++i) cows[renum[i].first] = cows[renum[i].second] = i+1;
    //for (int i=1; i<=2*N; ++i) printf("%3d", cows[i]); printf("\n");
    //printf("um\n");
    long long ans = 0;
    for (int i=1; i<=2*N; ++i)
    {
        long long c = cows[i];
        //for (int i=1; i<=N; ++i) printf("%3d", bit[i]); printf("\n");
        if (!seen[c]) ans -= bq(c), bu(c, 1), seen[c] = 1;
        else { bu(c, -1); ans += bq(c); }
        //printf("saw cow %d, now %d\n", c, ans);
    }
    printf("%lld\n", -ans);
}
