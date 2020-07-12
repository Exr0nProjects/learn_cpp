/*
 * Problem 3974 (poj/3974)
 * Create time: Sun 12 Jul 2020 @ 10:39 (PDT)
 * Accept time: Sun 12 Jul 2020 @ 11:19 (PDT)
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

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
int N, len[MX*2];
char buf[MX], str[MX*2];

int solve()
{
    len[0] = 0;
    int i=0, ret=0;
    for (int j=1; j<N; ++j)
    {
        if (j > i+len[i]) i = j;
        int jp = (i<<1)-j;                          // reflect j across i to get j'
        len[j] = min(len[jp], i+len[i]-j);
        while (j-len[j] > 0 && j+len[j] < N-1       // while in range
            && str[j-len[j]-1] == str[j+len[j]+1])  // and is palendrome
            ++len[j];                               // extend
        if (j + len[j] > i + len[i]) i = j;
        ret = max(ret, len[j]);
    }
    return ret;
}

int main()
{
    int cs=0;
    while (~scanf("%s", buf))
    {
        if (!strcmp(buf, "END")) break;
        N = strlen(buf);
        for (int i=0; i<N; ++i)
        {
            str[i<<1|1] = buf[i]; // using 1-indexed math for zero-indexed because we want overlap at i=0
            str[i+1<<1] = '$';
        }
        str[0] = '$';
        N <<= 1;
        str[++N] = 0;
        printf("Case %d: %d\n", ++cs, solve());

        memset(len, 0, sizeof len);
        memset(buf, 0, sizeof buf);
        memset(str, 0, sizeof str);
    }

	return 0;
}

