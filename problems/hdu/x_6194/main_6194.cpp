/*
 * Problem 6194 (hdu/6194)
 * Create time: Tue 04 Aug 2020 @ 10:44 (PDT)
 * Accept time: [!meta:end!]
 *  I read the problem so wrong--I thought that the problem statement was wrong
 *  and that it actually meant count the number of non-overlapping substrings
 *  of length atleast K, since I thought that it was atleast K and not exactly
 *  K cuz we had done so many of thos problems. dang it.
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;
const int MX = 100001;
int N, K, sa[MX], rk[MX], tmp[MX], pos[MX], lcp[MX];
char inp[MX];
int mq[MX]; // monotonic queue

int main()
{
    int T=1;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &K);
        scanf("%s", inp+1);
        N = strlen(inp+1);

        memset(rk, 0, sizeof rk);
        memset(lcp, 0, sizeof lcp);
        memset(mq, 0, sizeof mq);
        // prep
        for (int i=1; i<=N; ++i)
            rk[i] = inp[i], sa[i] = i;
        int mx = 128;
        // sa, rk
        for (int i=1; i>>1<N; i<<=1)    // FIX: typo--i<<=1 not ++i
        {
            int k = i>>1, p = k;
            // second
            for (int i=1; i<=k; ++i) tmp[i] = N-i+1;    // FIX: typo--N-i+1 not N-k+1
            for (int i=1; i<=N; ++i) if (sa[i] > k) tmp[++p] = sa[i]-k;
            // first
            memset(pos+1, 0, mx<<2);
            for (int i=1; i<=N; ++i) ++pos[rk[i]];
            for (int i=1; i<=mx; ++i) pos[i] += pos[i-1];
            for (int i=N; i; --i) sa[pos[ rk[tmp[i]] ]--] = tmp[i];
            // rerank
            for (int i=1; i<=N; ++i)
                tmp[sa[i]] = tmp[sa[i-1]] + (rk[sa[i]] != rk[sa[i-1]] || rk[sa[i]+k] != rk[sa[i-1]+k]);
            memcpy(rk+1, tmp+1, N<<2);
            // reset
            mx = rk[sa[N]];
            if (mx == N) break;
        }
        // lcp
        for (int i=1; i<=N; ++i)
        {
            lcp[rk[i]] = max(lcp[rk[i-1]]-1, 0);    // FIX: typo--max not min
            if (rk[i] > 1)
                while (inp[i + lcp[rk[i]]] == inp[sa[rk[i]-1] + lcp[rk[i]]])
                    ++lcp[rk[i]];
        }

        if (K > 1)
        {
            int tot = 0, l=1, r=0;  // l and r for monotonic queue
            // monotonic queue
            for (int i=2; i<=K; ++i)
            {
                while (r >= l && mq[r] > lcp[i]) --r;   // FIX: init monotonic queue properly, delete bigger old things
                mq[++r] = lcp[i];
            }
            // sliding window to count
            for (int i=2; i+K-2<=N; ++i)
            {
                tot += max(mq[l] - max(lcp[i-1], lcp[i+K-1]), 0);
                while (r >= l && mq[r] > lcp[i+K-1]) --r;
                mq[++r] = lcp[i+K-1];
                if (mq[l] == lcp[i]) ++l;
            }
            printf("%d\n", tot);
        }
        else
        {
            int sum=0;
            for (int i=1; i<=N; ++i)
                sum += - sa[i] - max(lcp[i], lcp[i+1]);   // FIX: carried by big turtle
            printf("%d\n", N*N+sum+N);
        }
    }

	return 0;
}

