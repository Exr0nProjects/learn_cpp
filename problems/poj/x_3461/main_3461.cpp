/*
 * Problem 3461 (poj/3461)
 * Create time: Fri 10 Jul 2020 @ 10:27 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define lr tl, (tl+((tr-tl)>>1))
#define rr (tl+((tr-tl)>>1)+1), tr

using namespace std;
const ll MX = 1000111;
int N, P, nxt[MX];
char pat[MX], str[MX];

void set_nxt()
{
    nxt[0] = -1;
    for (int i=1; i<=P; ++i)
    {
        int j = nxt[i-1];
        while (~j && pat[j+1] != pat[i])
            j = nxt[j];
        nxt[i] = j+1;
    }
}

int count()
{
    int tot=0, j=0;
    for (int i=1; i<=N; ++i)
    {
        while (~j && pat[j+1] != str[i])
            j = nxt[j];
        ++j;
        if (j == P) ++tot, j=nxt[j];
    }
    return tot;
}

int main()
{
    int cs; scanf("%d", &cs);
    while (cs--)
    {
        scanf("%s%s", pat+1, str+1);
        P = strlen(pat+1);
        N = strlen(str+1);
        set_nxt();
        printf("%d\n", count());
    }

	return 0;
}

