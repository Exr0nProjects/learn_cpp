/*
 * Problem 2406 (poj/2406)
 * Create time: Fri 10 Jul 2020 @ 10:56 (PDT)
 * Accept time: [!meta:end!]
 *
 * first try :sunglasses:
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
int N, replen=0, nxt[MX];
char buf[MX];

void set_nxt()
{
    nxt[0] = -1;
    for (int i=1; i<=N; ++i)
    {
        int j=nxt[i-1];
        while (~j && buf[j+1] != buf[i])
            j = nxt[j];
        if (!~j) replen = i;
        nxt[i] = j+1;
    }
}


int main()
{
    while (scanf("%s", buf+1))
    {
        if (buf[1] == '.') break;
        N = strlen(buf+1);
        set_nxt();
        //for (int i=1; i<=N; ++i) printf("%3d", nxt[i]); printf("\n");
        //printf("N %d, replen = %d, nxt[N] %d\n", N, replen, nxt[N]);
        if (!(nxt[N]%replen)) printf("%d\n", N/replen);
        else printf("1\n");
    }

	return 0;
}

