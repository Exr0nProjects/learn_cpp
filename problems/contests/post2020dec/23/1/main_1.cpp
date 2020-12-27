/*
 * Problem 1 (contests/post2020dec/23/1)
 * Create time: Sun 27 Dec 2020 @ 11:12 (PST)
 * Accept time: [!meta:end!]
 * word chain, pid 1314 (trie path counting?)
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MX = 1e4+1;
const ll MXL = 50;
const ll AL = 26;
ll N, trie[MX*MXL][AL], isw[MX*MXL], tcnt=0;
char buf[MXL];

int main()
{
    scanf("%lld", &N);
    ll ans = 1;
    for (ll i=1; i<=N; ++i)
    {
        scanf("%s", buf);
        ll cur = 0, sum = 0;
        for (ll j=0; buf[j]; ++j)
        {
            sum += isw[cur];
            if (!trie[cur][j]) trie[cur][j] = ++tcnt;
            cur = trie[cur][j];
        }
        isw[cur] = 1;
        //db("%s got %d\n", buf, sum);
        ans = max(ans, sum);
    }
    printf("%lld\n", ans);
}

