/*
 * Problem 3729 (poj/3729)
 * Create time: Mon 10 Aug 2020 @ 11:05 (PDT)
 * Accept time: Fri 14 Aug 2020 @ 11:53 (PDT)
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 500101<<1;
const int MXV = 100010;
int N, M, K, inp[MX];

int sa[MX], rk[MX], tmp[MX], pos[MXV], lcp[MX];
int vis[MX], cnt[MX];    // how many suffixes from a have lcp of len i with b
void klcp()
{
    int mx = MXV;
    for (int i=1; i<=N; ++i)
        rk[i] = inp[i], sa[i] = i;
    for (int i=1; i>>1<N; i<<=1)    // FIX: typo--main loop in suffarray is i<<=1
    {
        int k=i>>1, p=k;
        for (int i=1; i<=k; ++i) tmp[i] = N-i+1;
        for (int i=1; i<=N; ++i) if (sa[i] > k) tmp[++p] = sa[i]-k;
        memset(pos, 0, 1+mx<<2);
        for (int i=1; i<=N; ++i) ++pos[rk[i]];
        for (int i=1; i<=mx; ++i) pos[i] += pos[i-1];
        for (int i=N; i; --i) sa[pos[ rk[tmp[i]] ]--] = tmp[i];
        for (int i=1; i<=N; ++i)
            tmp[sa[i]] = tmp[sa[i-1]] + (rk[sa[i]] != rk[sa[i-1]] || rk[sa[i]+k] != rk[sa[i-1]+k]);
        memcpy(rk, tmp, 1+N<<2);
        mx = rk[sa[N]]; if (mx == N) break; // FIX: logic--forgot suffarr resync code
    }
    for (int i=1; i<=N; ++i)
    {
        lcp[rk[i]] = max(lcp[rk[i-1]]-1, 0);
        if (rk[i] > 1)
            while (inp[i+lcp[rk[i]]] == inp[sa[rk[i]-1]+lcp[rk[i]]])
                ++lcp[rk[i]];
    }
}

int main()
{
    while (~scanf("%d%d%d", &N, &M, &K))
    {
        memset(inp, 0, sizeof inp); // FIX: clears
        memset(sa, 0, sizeof sa);
        memset(rk, 0, sizeof rk);
        memset(tmp, 0, sizeof tmp);
        memset(lcp, 0, sizeof lcp);
        memset(cnt, 0, sizeof cnt);
        int i=1;
        for (; i<=N; ++i)
            scanf("%d", inp+i);
        inp[i] = MXV-5;
        N += M+1;
        M = N-M-1; // store string boundary for later
        for (++i; i<=N; ++i)
            scanf("%d", inp+i);
        for (int i=1; i<=N; ++i) ++inp[i];

        klcp();
        //printf("N = %d M = %D K = %D\n", N, M, K);
        //for (int i=1; i<=N; ++i) printf("%3d", i); printf("\n\n");
        //for (int i=1; i<=N; ++i) inp[i] +6 > MXV ? printf("  _") : printf("%3d", inp[i]); printf("\n");
        //for (int i=1; i<=N; ++i) printf("%3d", rk[i]);  printf("\n");
        //for (int i=1; i<=N; ++i) printf("%3d", sa[i]);  printf("\n");
        //for (int i=1; i<=N; ++i) printf("%3d", lcp[i]); printf("\n\n");
        //
        // NOTE: add max between prev and next b-suf for each a-suf. counting sort. output pos[K]
        int mn = MX-5;
        for (int i=1; i <= N; ++i)
            if (sa[i] > M) mn = MX-5;
            else mn = min(mn, lcp[i]), vis[sa[i]] = mn;
        //for (int i=1; i<=M; ++i) printf("%3d", vis[i]); printf("\n");
        mn = MX-5;
        for (int i=N; i; --i)
            if (sa[i] > M) mn = lcp[i];
            else vis[sa[i]] = max(vis[sa[i]], mn), mn = min(mn, lcp[i]);
            //else vis[sa[i]] = mn, mn = min(mn, lcp[i]);
        for (int i=1; i<=M; ++i) ++cnt[vis[i]];
        //for (int i=1; i<=M; ++i) printf("%3d", vis[i]); printf("\n");
        //for (int i=1; i<=M; ++i) printf("%3d", cnt[i]); printf("\n");
        printf("%d\n", cnt[K]);
    }

	return 0;
}

