/*
 * Problem 1961 (poj/1961)
 * Create time: Sun 12 Jul 2020 @ 12:32 (PDT)
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
int N, nxt[MX];
char str[MX];

void setnxt()
{
    nxt[0] = -1;
    for (int i=1; i<=N; ++i)
    {
        int j = nxt[i-1];
        while (~j && str[j+1] != str[i])
            j = nxt[j];
        nxt[i] = j+1;
    }
}

int main()
{
    int cs = 0;
    while (~scanf("%d", &N) && N)
    {
        scanf("%s", str+1);
        setnxt();
        printf("Test case #%d\n", ++cs);
        //for (int i=1; i<=N; ++i) printf("%3d", nxt[i]); printf("\n");
        for (int i=2; i<=N; ++i)
            if (nxt[i] % (i-nxt[i]) == 0 && nxt[i])
                printf("%d %d\n", i, i/(i-nxt[i]));
        printf("\n");
    }

	return 0;
}

