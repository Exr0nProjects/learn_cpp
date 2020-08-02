/*
 * Problem P3809 (luogu/P3809)
 * Create time: Sun 02 Aug 2020 @ 12:56 (PDT)
 * Accept time: Sun 02 Aug 2020 @ 15:14 (PDT)
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 1000111;
int N, sa[MX], rk[MX], tmp[MX], pos[MX];
char inp[MX];

void suffsort()
{
    for (int i=1; i<=N; ++i)
        rk[i] = inp[i], sa[i] = i;                                          // initially, sort by character rank directly so first keyword is identity

    int mx=128;                                                             // 128 because we take ascii directly
    for (int i=1; i>>1<N; i<<=1)
    {
        int k = i>>1, p = k;                                                // r = current rerank num and it gets auto-incremented cuz pair[0] != pair[N]
        // copy by second keyword
        for (int i=1; i<=k; ++i) tmp[i] = N-i +1;                           // set first k nums to max; +1 is fencepost cuz one indexed
        for (int i=1; i<=N; ++i) if (sa[i] > k) tmp[++p] = sa[i]-k;         // put other elements into tmp but shifted (since they alre already sorted by second keyword from previous step); FIX: ++p not p++; FIX: sa[i]-k not sa[i], cuz u need to shift it over
        memset(pos, 0, sizeof(int)*(mx+1));                                 // FIX: indexing--memset N+1 not mx again!!!
        for (int i=1; i<=N; ++i) ++pos[rk[i]];                              // radix sort by rk[tmp[i]] is equiv to sorting by rk[i]
        for (int i=1; i<=mx; ++i) pos[i] += pos[i-1];                       // prefix sum on pos to get end positions of each group; FIX: up to mx not N because mx can be larger, on first iteration when its characters up to 127
        for (int i=N; i; --i) sa[pos[ rk[tmp[i]] ]--] = tmp[i];             // stable sort by first keyword, write tmp
        // re-rank
        for (int i=1; i<=N; ++i) tmp[sa[i]] = tmp[sa[i-1]]                  // rerank, same as previous but
            + (rk[sa[i]] != rk[sa[i-1]] || rk[sa[i]+k] != rk[sa[i-1]+k]);   // plus one if it is different
        memcpy(rk, tmp, (N+1)*sizeof(int));                                 // FIX: memcpy N+1 not mx
        // prep for next iteration
        mx = rk[sa[N]];                                                     // set mx to maximum rk, this is how "spread out" the substrings are
        if (mx == N) break;                                                 // optimization: break if everything is spread out enough
    }
}

int main()
{
    scanf("%s", inp+1);
    N = strlen(inp+1);
    suffsort();
    for (int i=1; i<=N; ++i)
        printf("%d ", sa[i]);
    printf("\n");

	return 0;
}

