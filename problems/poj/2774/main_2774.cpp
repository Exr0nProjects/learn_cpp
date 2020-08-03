/*
 * Problem 2774 (poj/2774)
 * Create time: Mon 03 Aug 2020 @ 11:27 (PDT)
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
const int MX = 200111;
char inp[MX];
int N, sa[MX], rk[MX], tmp[MX], pos[MX], lcp[MX];

//void ksa()
//{
//    int mx = 128;
//    for (int i=1; i<=N; ++i)
//        rk[i] = inp[i], sa[i] = i;
//    for (int i=1; i<<1<N; i<<=1)
//    {
//        printf("wait but why\n");
//        printf("%d\n", N);
//        int k = i>>1, p=k;
//        // second keyword
//        //for (int i=1; i<=k; ++i) tmp[i] = N-i+1;
//        for (int i=1; i<=N; ++i) if (sa[i] > k) tmp[++p] = sa[i]-k;
//        // first keyword
//        //memset(pos, 0, 1+mx<<2);    // times 4 for int
//        //for (int i=1; i<=N; ++i) ++pos[rk[i]];
//        //for (int i=1; i<mx; ++i) pos[i] += pos[i-1];    // FIX: mx not MX, altho both work
//        for (int i=N; i; --i) sa[pos[ rk[tmp[i]] ]--] = tmp[i];
//        //for (int i=1; i<=N; ++i) printf("%3d", sa[i]); printf("\n");
//        // re-rank
//        for (int i=1; i<=N; ++i)
//            tmp[sa[i]] = tmp[sa[i-1]] + (rk[sa[i]] != rk[sa[i-1]] || rk[sa[i]+k] != rk[sa[i-1]+k]);
//        //printf("%d %d\n", sizeof rk, sizeof tmp);
//        for (int i=1; i<=N; ++i) rk[i] = tmp[i];    // TODO: bus error
//        for (int i=1; i<=3; ++i) rk[i] = tmp[i];    // works
//        for (int i=1; i<=N; ++i) printf("%3d", rk[i]); printf("\n\n");
//        // prep
//        printf(" n = %d\n", N);
//        mx = rk[sa[N]];
//        printf("mx = %d, n = %d, eq? %d\n", mx, N, mx == N);
//        if (mx == N) break;
//        printf("what the hell??\n");
//    }
//}

void ksa()
{
    int mx = 128;
    for (int i=1; i<=N; ++i)
        rk[i] = inp[i], sa[i] = i;
    //for (int i=1; i<<1<N; i<<=1)
    int kk=1;
    while (kk*2<N)
    {
        printf("i = %d\n", kk);
        printf("%d\n", N);
        int k = kk>>1, p=k;
        // second keyword
        //for (int i=1; i<=k; ++i) tmp[i] = N-i+1;
        for (int i=1; i<=N; ++i) if (sa[i] > k) tmp[++p] = sa[i]-k;
        // first keyword
        //memset(pos, 0, 1+mx<<2);    // times 4 for int
        //for (int i=1; i<=N; ++i) ++pos[rk[i]];
        //for (int i=1; i<mx; ++i) pos[i] += pos[i-1];    // FIX: mx not MX, altho both work
        for (int i=N; i; --i) sa[pos[ rk[tmp[i]] ]--] = tmp[i];
        //for (int i=1; i<=N; ++i) printf("%3d", sa[i]); printf("\n");
        // re-rank
        for (int i=1; i<=N; ++i)
            tmp[sa[i]] = tmp[sa[i-1]] + (rk[sa[i]] != rk[sa[i-1]] || rk[sa[i]+k] != rk[sa[i-1]+k]);
        //printf("%d %d\n", sizeof rk, sizeof tmp);
        //for (int i=1; i<=N; ++i) rk[i] = tmp[i];    // TODO: bus error
        for (int i=1; i<=3; ++i) rk[i] = tmp[i];    // works
        for (int i=1; i<=N; ++i) printf("%3d", rk[i]); printf("\n\n");
        // prep
        printf(" n = %d\n", N);
        mx = rk[sa[N]];
        printf("mx = %d, n = %d, eq? %d\n", mx, N, mx == N);
        if (mx == N) break;
        printf("what the hell??\n");
        kk <<= 1;
        printf("wait but why %d\n", kk*2 < N);
        printf("kk %x tmp %x rk %x\n", &kk, tmp, rk);
    }
}

void klcp()
{
    for (int i=1; i<N; ++i)
    {
        lcp[rk[i]] = max(lcp[rk[i-1]], 0);
        while (inp[lcp[rk[i]]+i] == inp[sa[rk[i-1]] + lcp[rk[i]]])
            ++lcp[rk[i]];
    }
}

int main()
{
    scanf("%s", inp+1);
    N = strlen(inp+1);
    ksa();
    klcp();

    for (int i=1; i<=N; ++i) printf("%3d", i); printf("\n");
    for (int i=1; i<=N; ++i) printf("%3c", inp[i]); printf("\n");
    for (int i=1; i<=N; ++i) printf("%3d", sa[i]); printf("\n");
    for (int i=1; i<=N; ++i) printf("%3d", lcp[rk[i]]); printf("\n");

	return 0;
}

