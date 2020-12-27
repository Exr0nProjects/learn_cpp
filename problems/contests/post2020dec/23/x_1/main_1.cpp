/*
 * Problem 1 (contests/post2020dec/23/1)
 * Create time: Sun 27 Dec 2020 @ 11:12 (PST)
 * Accept time: [!meta:end!]
 * word chain, pid 1314 (trie path counting?)
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const int MX = 1e4+10;
const int MXL = 60;
const int AL = 32;
int N, isw[MX*MXL], tcnt=0;
map<char, int> trie[MX*MXL];
char buf[MXL];

int main()
{
    scanf("%d", &N);
    int ans = 1;
    for (int i=1; i<=N; ++i)
    {
        scanf("%s", buf);
        int cur = 0, sum = 0;
        for (ll j=0; buf[j]; ++j)
        {
            char c = buf[j] - 'a';  // FIX: typo--trie on char not j
            if (!trie[cur].count(c)) trie[cur][c] = ++tcnt;
            cur = trie[cur][c];
            sum += isw[cur];
            //db("after %d: at %d\n", j, cur);
        }
        isw[cur] = 1;
        //db("%s got %d\n", buf, sum);
        ans = max(ans, sum);
    }
    printf("%lld\n", ans+1);
}

