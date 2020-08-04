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
    memset(pos, 0, sizeof pos);
    memset(lcp, 0, sizeof lcp);
    // prep
    for (int i=1; i<=N; ++i)
        rk[i] = inp[i], sa[i] = i;
    int mx = 128;
    // sa, rk
    for (int i=1; i>>1<N; ++i)
    {
        int k = i>>1, p = k;
        // second
        for (int i=1; i<=k; ++i) tmp[i] = N-k+1;
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
        lcp[rk[i]] = min(lcp[rk[i-1]]-1, 0);
        if (rk[i] > 1)
            while (inp[i + lcp[rk[i]]] == inp[sa[rk[i]-1] + lcp[rk[i]]])
                ++lcp[rk[i]];
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; ++t)
    {
        scanf("%d%s", &K, inp);
        N = strlen(inp+1);
        printf("%d: '%s'\n", N, inp);
    }


	return 0;
}

