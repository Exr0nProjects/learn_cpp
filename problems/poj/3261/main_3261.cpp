/*
 * Problem 3261 (poj/3261)
 * Create time: Mon 03 Aug 2020 @ 19:53 (PDT)
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
const int MXN = 20100;
const int MXV = 1000111;
int N, K, inp[MXN];
int sa[MXN], rk[MXN], tmp[MXN], pos[MXV];
int lcp[MXN];

void ksa()
{
    int mx = MXV;
    for (int i=1; i<=N; ++i)
        rk[i] = inp[i], sa[i] = i;
    for (int i=1; i>>1<=N; i<<=1)
    {
        int k = i>>1, p = k;
        // second keyword
        for (int i=1; i<=k; ++i) tmp[i] = N-i+1;
        for (int i=1; i<=N; ++i) if (sa[i] > k) tmp[++p] = sa[i]-k;
        // first keyword
        memset(pos, 0, 1+mx<<2);
        for (int i=1; i<=N; ++i) ++pos[rk[i]];
        for (int i=1; i<=mx; ++i) pos[i] += pos[i-1];       // FIX: typo--mx not MX
        for (int i=N; i; --i) sa[pos[ rk[tmp[i]] ]--] = tmp[i];
        // rerank
        for (int i=1; i<=N; ++i)
            tmp[sa[i]] = tmp[sa[i-1]] + (rk[sa[i]] != rk[sa[i-1]] || rk[sa[i]+k] != rk[sa[i-1]+k]);
        memcpy(rk, tmp, 1+N<<2);
        for (int i=1; i<=N; ++i) printf("%3d", rk[i]); printf("\n");
        // reset
        mx = rk[sa[N]];
        if (mx == N) break;
    }
    for (int i=1; i<=N; ++i)
    {
        lcp[rk[i]] = max(lcp[rk[i-1]], 0);
        if (rk[i] > 1)
            while (inp[i+lcp[rk[i]]] == inp[  lcp[rk[i]-1]  +lcp[rk[i]]])
                ++lcp[rk[i]];
    }
}

int main()
{
    scanf("%d%d", &N, &K);
    for (int i=1; i<=N; ++i) scanf("%d", &inp[i]);
    ksa();

	return 0;
}

