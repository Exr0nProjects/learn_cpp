/*
 * Problem 3518 (hdu/3518)
 * Create time: Tue 04 Aug 2020 @ 12:11 (PDT)
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
const ll MX = 1111;
int N;
char inp[MX];
int sa[MX], rk[MX], tmp[MX], pos[MX], lcp[MX];

void ksa()
{
    for (int i=1; i<=N; ++i)
        rk[i] = inp[i], sa[i] = i;
    int mx = 128;
    for (int i=1; i>>1<N; i<<=1)
    {
        int k = i>>1, p = k;
        for (int i=1; i<=k; ++i) tmp[i] = N-i+1;
        for (int i=1; i<=N; ++i) if (sa[i] > k) tmp[++p] = sa[i]-k; // FIX: typo-- sa[i]-k not just sa[i] smah
        memset(pos, 0, 1+mx<<2);
        for (int i=1; i<=N; ++i) ++pos[rk[i]];
        for (int i=1; i<=mx; ++i) pos[i] += pos[i-1];
        for (int i=N; i; --i) sa[pos[ rk[tmp[i]] ]--] = tmp[i];
        for (int i=1; i<=N; ++i)
            tmp[sa[i]] = tmp[sa[i-1]] + (rk[sa[i]] != rk[sa[i-1]] || rk[sa[i]+k] != rk[sa[i-1]+k]); // FIX: logic typo--!= and ||, not == and && smah
        memcpy(rk, tmp, 1+N<<2);
        mx = rk[sa[N]];
        if (mx == N) break;
    }
    for (int i=1; i<=N; ++i)
    {
        lcp[rk[i]] = max(lcp[rk[i-1]]-1, 0);
        if (rk[i] > 1)
            while (inp[i+lcp[rk[i]]] == inp[sa[rk[i]-1]+lcp[rk[i]]])
                ++lcp[rk[i]];
    }
}

int count_groups(int mn)
{
    int tot = 0, pre = 0;
    for (int i=1; i<=N; ++i)
    {
        if (lcp[i+1] < mn)
        {
            //printf("%d - %d = %d\n", i, pre, i-pre);
            if (i-pre >= 2)
            {
                int mxi=0, mni=N;
                for (int j=pre; j<=i; ++j)
                {
                    mxi = max(mxi, sa[j+1]), mni = min(mni, sa[j+1]);   // FIX: typo-- j not i
                    //printf("    at %d (%d), mx %d mn %d\n", i+1, sa[j+1], mxi, mni);
                }
                if (mni + mn <= mxi) ++tot;
            }
            pre = i;
        }
    }
    return tot;
}

int main()
{
    while (true)
    {
        memset(sa, 0, sizeof sa);
        memset(rk, 0, sizeof rk);
        memset(tmp, 0, sizeof tmp);
        memset(pos, 0, sizeof pos);
        memset(lcp, 0, sizeof lcp);
        memset(inp, 0, sizeof inp);

        scanf("%s", inp+1);
        if (inp[1] == '#') break;
        N = strlen(inp+1);
        ksa();

        //printf("\ni:         "); for (int i=1; i<=N; ++i) printf("%3d", sa[i]);
        //printf("\ninp[i]:    "); for (int i=1; i<=N; ++i) printf("%3d", inp[sa[i]]);
        //printf("\nrk[i]:     "); for (int i=1; i<=N; ++i) printf("%3d", i);
        //printf("\nlcp[rk[i]]:"); for (int i=1; i<=N; ++i) printf("%3d", lcp[i]);
        //printf("\n\n");
        //while (true)
        //{
        //    int d; scanf("%d", &d);
        //    printf("=> %d\n", count_groups(d));
        //}

        int tot = 0;
        for (int i=1; i<=N; ++i)
            tot += count_groups(i);
        printf("%d\n", tot);
    }

	return 0;
}

