#include <bits/stdc++.h>
#define ll long long
#define F(i, N) for (int i=1; i<=N; ++i)
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 1e5+10;
ll N, rcnt='a';
char s[MX], alph[32], remap[256];
ll acnt = 0;

int main()
{
    scanf("%s", s+1);
    N = strlen(s+1);

    F(i, N) {
        //if (!remap[s[i]]) remap[s[i]] = rcnt++;
        //s[i] = remap[s[i]];
        if (!remap[s[i]]) alph[acnt++] = s[i], remap[s[i]] = rcnt++;
    }

    ll perms = 1;
    F(i, acnt) perms *= i;

    ll ans = 1e9;
    //db("acnt = %d\n", acnt);
    //do {
    F(i, perms) {
        ll c = 0;
        F(i, N) { while (alph[c%acnt] != s[i] && c < ans) ++c; ++c; }
        //if (c <= ans) {
        //if ((c-1)/acnt <= (ans-1)/acnt) {
        ////if (true) {
        //    for (int i=0; i<acnt; ++i) db("%c ", alph[i]);
        //    db("-> %d (%d)\n", (c-2)/acnt+1, c);
        //}
        ans = min(ans, c);
        next_permutation(alph, alph+acnt);
    }
    //} while (next_permutation(alph, alph+acnt));
    printf("%d\n", (ans-1)/acnt+1);
}

