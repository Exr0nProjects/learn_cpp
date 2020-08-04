/*
 * Problem 6194 (hdu/6194)
 * Create time: Tue 04 Aug 2020 @ 10:44 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
#include <utility>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 100111;
int N, K, sa[MX], rk[MX], tmp[MX], pos[MX], lcp[MX];
char inp[MX];
void klcp() {
    memset(sa, 0, sizeof sa);
    memset(rk, 0, sizeof rk);
    memset(tmp, 0, sizeof tmp);
    //memset(pos, 0, sizeof pos);
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

int count_groups(int mn)
{
    int tot=0, pre=0;
    for (int i=1; i<=N; ++i)
    {
        if (lcp[i+1] < mn)
        {
            if (i-pre >= K) ++tot;  // TODO: exactly k times -> i-pre == K
            pre=i;
        }
        if (min(sa[i], sa[i+1]) + mn > max(sa[i], sa[i+1]))
            pre=i;
    }
    return tot;
}

int main()
{
    int T=1;
    //scanf("%d", &T);
    for (int t=0; t<T; ++t)
    {
        scanf("%d", &K);
        scanf("%s", inp+1);
        N = strlen(inp+1);
        klcp();
        printf("\ni:           "); for (int i=1; i<=N; ++i) printf("%3d", sa[i]);
        printf("\ninp[i]:      "); for (int i=1; i<=N; ++i) printf("%3d", inp[sa[i]]);
        printf("\nrk[i]:       "); for (int i=1; i<=N; ++i) printf("%3d", i);
        printf("\nlcp[rk[i]]:  "); for (int i=1; i<=N; ++i) printf("%3d", lcp[i]);
        printf("\n\n");
        //printf("%d: '%s'\n", N, inp+1);

        int tot=0;
        for (int i=1; i<=N; ++i)
            tot += count_groups(i);
        printf("%d\n", tot);

        //while (true)
        //{
        //    int d; scanf("%d", &d);
        //    printf("%d\n", count_groups(d));
        //}
    }


	return 0;
}

