/*
 * Problem 1077 (usaco/gold/2021jan/1077)
 * Create time: Sun 24 Jan 2021 @ 10:35 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define F(i, N) for (int i=1; i<=N; ++i)
#define db(...) fprintf(stderr, __VA_ARGS__)
//#define db(...) (i)
using namespace std;

const ll MX = 1e6+10;

ll N, rcnt='a';
char s[MX], remap[256];
ll cnt[256], cmax=0;

int main()
{
	scanf("%s", s+1);
	N = strlen(s+1);
    ll ans = 1;
    F(i, N) {
        if (!remap[s[i]]) remap[s[i]] = rcnt++;
        cmax = max(cmax, ++cnt[s[i]]);
        s[i] = remap[s[i]];
        db("%c", s[i]);
        if (s[i] <= s[i-1]) db("!"), ++ans;
        db(" ");
    }
    printf("%lld\n", cmax);
}
