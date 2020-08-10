/*
 * Problem 3729 (poj/3729)
 * Create time: Mon 10 Aug 2020 @ 11:05 (PDT)
 * Accept time: [!meta:end!]
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
bool vis[MX];   // does pos i have match in other string
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
    //for (int i = 1; i <= N; i++) {
    //    rk[i] = inp[i];
    //    sa[i] = i;
    //}
    //int mx = 11000;
    //for (int i = 1; (i >> 1) < N; i <<= 1) {
    //    int t = i >> 1;
    //    for (int j = 1; j <= t; j++) {
    //        tmp[j] = N - j + 1;
    //    }
    //    int p = t;
    //    for (int j = 1; j <= N; j++) {
    //        if (sa[j] > t) tmp[++p] = sa[j] -t;
    //    }
    //    memset(pos, 0, sizeof(pos));
    //    for (int j = 1; j <= N; j++) {
    //        pos[rk[tmp[j]]]++;
    //    }
    //    for (int j = 1; j <= mx; j++) {
    //        pos[j] += pos[j - 1];
    //    }
    //    for (int j = N; j >= 1; j--) {
    //        sa[pos[rk[tmp[j]]]--] = tmp[j];
    //    }
    //    int cnt = 0;
    //    for (int j = 1; j <= N; j++) {
    //        if (rk[sa[j]] != rk[sa[j - 1]] || rk[sa[j] + t] != rk[sa[j - 1] + t]) ++cnt;
    //        tmp[sa[j]] = cnt;
    //    }
    //    memcpy(rk + 1, tmp + 1, N << 2);
    //    mx = cnt;
    //}

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
        memset(pos, 0, sizeof pos);
        memset(lcp, 0, sizeof lcp);
        memset(vis, 0, sizeof vis);
        int i=1;
        for (; i<=N; ++i)
            scanf("%d", inp+i);
        inp[i] = MXV-5;
        N += M+1;
        M = N-M-1; // store string boundary for later
        for (++i; i<=N; ++i)
            scanf("%d", inp+i);
        inp[++N] = MXV-5;
        for (int i=1; i<=N; ++i) ++inp[i];

        klcp();
        //for (int i=1; i<=N; ++i) printf("%3d", i); printf("\n");
        //for (int i=1; i<=N; ++i) inp[i] +6 > MXV ? printf("  _") : printf("%3d", inp[i]); printf("\n");
        //for (int i=1; i<=N; ++i) printf("%3d", sa[i]);  printf("\n");
        //for (int i=1; i<=N; ++i) printf("%3d", rk[i]);  printf("\n");
        //for (int i=1; i<=N; ++i) printf("%3d", lcp[i]); printf("\n");

        int tot=0;
        for (int i=1; i<N; ++i)
        {
            //printf("i %d: ", i);
            int j=i+1;
            while (lcp[j] > K) ++j;
            //printf("j %d..", j);
            if (lcp[j] < K) continue;   // FIX: continue not break
            //if (lcp[j] < K) { printf("\n"); continue; }
            for (; max(sa[i], sa[j])+K <= N && lcp[j] > K-1; ++j)   // FIX: don't go too far to the right
            {
                if (min(sa[i], sa[j]) < M && max(sa[i], sa[j]) > M)
                {
                    //printf("%d..", j);
                    vis[min(sa[i], sa[j])] = 1;
                }
            }
            //printf("%d\n", j);
        }
        for (int i=1; i<=M; ++i) tot += vis[i];
        printf("%d\n", tot);
    }

	return 0;
}

