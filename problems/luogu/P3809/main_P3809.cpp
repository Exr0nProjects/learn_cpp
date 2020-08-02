/*
 * Problem P3809 (luogu/P3809)
 * Create time: Sun 02 Aug 2020 @ 12:56 (PDT)
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
const ll MX = 1000111;
int N, sa[MX], rk[MX];
char inp[MX];

void suffsort()
{
    for (int i=1; i<=N; ++i)
        rk[i] = inp[i], sa[i] = i;

    int tmp[MX], pos[MX];

    for (int kk=1; kk<N; kk<<=1)
    {
        int k = kk>>1, p = k, r = 0;    // r = current rerank num and it gets auto-incremented cuz pair[0] != pair[N]
        // copy by second keyword
        for (int i=1; i<=k; ++i) tmp[i] = N-i +1;   // set first k nums to max; +1 is fencepost cuz one indexed
        //for (int i=1; i<=N; ++i) if (sa[i] > k) tmp[p++] = sa[i];
        for (int i=1; i<=N; ++i) if (sa[i] > k) tmp[++p] = sa[i];   // put other elements into tmp but shifted (since they alre already sorted by second keyword from previous step); FIX: ++p not p++
        printf("tmp_%d: ", k); for (int i=1; i<=N; ++i) printf("%3d", tmp[i]); printf("\n");
        // radix sort by first keyword
        memset(pos, 0, sizeof pos);
        for (int i=1; i<=N; ++i) ++pos[rk[i]];          // radix sort by rk[tmp[i]] is equiv to sorting by rk[i]
        for (int i=1; i<=N; ++i) pos[i] += pos[i-1];    // prefix sum on pos to get end positions of each group
        for (int i=N; i>=1; --i) sa[pos[ rk[tmp[i]] ]--] = tmp[i];  // stable sort by first keyword, write tmp
        printf("sa_%d:  ", k); for (int i=1; i<=N; ++i) printf("%3d", tmp[i]); printf("\n");
        // re-rank
        for (int i=1; i<=N; ++i) tmp[sa[i]] = r += (rk[sa[i]] != rk[sa[i-1]] || rk[sa[i]+k] != rk[sa[i-1]+k]);
        //
        memcpy(rk, tmp, MX);
        printf("rk_%d:  ", k); for (int i=1; i<=N; ++i) printf("%3d", tmp[i]); printf("\n");
        printf("\n");
    }
}

int main()
{
    scanf("%s", inp+1);
    N = strlen(inp+1);
    suffsort();

	return 0;
}

