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
#include <set>
#include <utility>
#include <algorithm>

using namespace std;
const int MX = 100111;
int N, K, sa[MX], rk[MX], tmp[MX], pos[MX], lcp[MX];
char inp[MX];
void klcp() {
    memset(sa, 0, sizeof sa);
    memset(rk, 0, sizeof rk);
    memset(tmp, 0, sizeof tmp);
    memset(lcp, 0, sizeof lcp);
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
        memset(pos, 0, 1+mx<<2);
        for (int i=1; i<=N; ++i) ++pos[rk[i]];
        for (int i=1; i<=mx; ++i) pos[i] += pos[i-1];
        for (int i=N; i; --i) sa[pos[ rk[tmp[i]] ]--] = tmp[i];
        // rerank
        for (int i=1; i<=N; ++i)
            tmp[sa[i]] = tmp[sa[i-1]] + (rk[sa[i]] != rk[sa[i-1]] || rk[sa[i]+k] != rk[sa[i-1]+k]);
        memcpy(rk, tmp, 1+N<<2);
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
}

int st[MX];
int count_groups3()
{
    // sparse table
    //memcpy(st, lcp, 1+N<<2);
    for (int i=1; i<=N; ++i) st[i] = lcp[i];
    for (int d=0; 1<<1+d < K; ++d) {
        //printf("\n%2d: ", 1<<d);
        for (int i=1; i<=N; ++i) {
            st[i] = min(st[i], st[i+(1<<d)]);
            //printf("%3d", st[i]);
        }
    }
    //printf("\n");

    // sliding window to count
    int tot = 0;
    //multiset<int> mn;           // TODO: replace w/ sparse table?
    //for (int i=2; i<=K; ++i)
    //    mn.insert(lcp[i]);
    for (int i=2; i+K-2<=N; ++i)// TODO: doesn't work for K=1
    {
        tot += max(st[i] - max(lcp[i-1], lcp[i+K-1]), 0);
        //if (lcp[i-1] < *mn.begin() && lcp[i+K-1] < *mn.begin()) {
        //    //printf("range %d..%d legal!\n", i, i+K-2);
        //    tot += *mn.begin() - max(lcp[i-1], lcp[i+K-1]);
        //}
        //mn.erase(mn.find(lcp[i]));
        //mn.insert(lcp[i+K-1]);
    }
    return tot;
}

int main()
{
    int T=1;
    //scanf("%d", &T);
    for (int t=0; t<T; ++t)
    {
        //K = 3;
        scanf("%d", &K);
        scanf("%s", inp+1);
        N = strlen(inp+1);
        klcp();
        //printf("\ni:           "); for (int i=1; i<=N; ++i) printf("%3d", sa[i]);
        //printf("\ninp[i]:      "); for (int i=1; i<=N; ++i) printf("%3d", inp[sa[i]]);
        //printf("\nrk[i]:       "); for (int i=1; i<=N; ++i) printf("%3d", i);
        //printf("\nlcp[rk[i]]:  "); for (int i=1; i<=N; ++i) printf("%3d", lcp[i]);
        //printf("\n\n");

        printf("%d\n", count_groups3());
    }

	return 0;
}

