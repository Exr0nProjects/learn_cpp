/*
 * Problem 14final (tcp2020b/14final)
 * Create time: Sun 26 Jul 2020 @ 10:53 (PDT)
 * Accept time: Wed 29 Jul 2020 @ 12:35 (PDT)
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <tuple>
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
#include <iterator>
#include <exception>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define lr tl, (tl+((tr-tl)>>1))
#define rr (tl+((tr-tl)>>1)+1), tr

using namespace std;
const ll MX = 100010;
int N, M, ins[MX];
ll ans[MX];
int bitL[MX], bitR[MX];
int invt[MX], invv[MX], auxt[MX], auxv[MX];

int die(int k=0)
{
    printf("%d\n", die(k+1));
}

void solve(int tl, int tr)  // dnq inversions counter, inc l exc r
{
    if (tl+1 == tr) return;
    int mid = tl+(tr-tl>>1);
    solve(tl, mid); solve(mid, tr);
    int l=tl, r=mid;

    for (int i=tl; i<tr; ++i)
    {
        if (l == mid || (r < tr && invt[r] < invt[l])) {    // take from right
            auxt[i] = invt[r];
            auxv[i] = invv[r];
            for (int x=N+1-auxv[i]; x; x-=x&-x)
                ans[auxt[i]] += bitL[x];
            for (int x=auxv[i]; x<=N; x+=x&-x)
                ++bitR[x];
            ++r;
        } else {                                // take from left
            auxt[i] = invt[l];
            auxv[i] = invv[l];
            for (int x=auxv[i]; x; x-=x&-x)
                ans[auxt[i]] += bitR[x];
            for (int x=N+1-auxv[i]; x<=N; x+=x&-x)
                ++bitL[x];
            ++l;
        }
    }
    for (int i=tl; i<mid; ++i)
        for (int x=N+1-invv[i]; x<=N; x+=x&-x)
            bitL[x] = 0;
    for (int i=mid; i<tr; ++i)
        for (int x=invv[i]; x<=N; x+=x&-x)
            bitR[x] = 0;
    memcpy(invt+tl, auxt+tl, sizeof(int)*(tr-tl));
    memcpy(invv+tl, auxv+tl, sizeof(int)*(tr-tl));
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=1; i<=N; ++i) scanf("%d", &invv[i]);
    for (int i=M; i>0; --i) {
        int d; scanf("%d", &d);
        ins[d] = i;
    }
    for (int i=1; i<=N; ++i) invt[i] = ins[invv[i]];

    solve(1, N+1);
    for (int i=0; i<M; ++i) ans[i+1] += ans[i];
    for (int i=M; i>0; --i) printf("%lld\n", ans[i]);

	return 0;
}

