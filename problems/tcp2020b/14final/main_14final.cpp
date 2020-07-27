/*
 * Problem 14final (tcp2020b/14final)
 * Create time: Sun 26 Jul 2020 @ 10:53 (PDT)
 * Accept time: [!meta:end!]
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
const ll MX = 100111;
int N, M, arr[MX], ins[MX], ans[MX];
int bitL[MX], bitR[MX];
pair<int, int> cinv[MX], aux[MX];    // <insert order, og value>

void bu(int b[], int x)     // bit update
{
    for (; x<=N; x+=x&-x)
        ++b[x];
}
int bq(int b[], int x)     // bit query
{
    int sum=0;
    for (; x; x-=x&-x)
        sum += b[x];
    return sum;
}
int bqs(int b[], int x)    // bit query suffix
{
    return bq(b, N) - bq(b, x-1);
}
void solve(int tl, int tr)  // dnq inversions counter, inc l exc r
{
    if (tl+1 == tr) return;
    //printf("    solve %d:%d    ", tl, tr); for (int i=tl; i<tr; ++i) printf("(%3d, %3d)  ", cinv[i].f, cinv[i].s); printf("\n");
    int mid = tl+(tr-tl>>1);
    solve(tl, mid); solve(mid, tr);
    int l=tl, r=mid;
    // TODO: below might tle, maybe only clear used parts or use segtree?
    memset(bitL, 0, sizeof bitL);
    memset(bitR, 0, sizeof bitR);
    for (int i=tl; i<tr; ++i)
    {
        //printf("        %2d v %-2d ", l, r);
        if (l == mid || (r < tr && cinv[r] < cinv[l])) {    // take from right
            //printf("take from right\n");
            aux[i] = cinv[r];
            ans[aux[i].f] += bqs(bitL, aux[i].s);
            bu(bitR, aux[i].s);
            ++r;
        } else {                                // take from left
            //printf("take from left\n");
            aux[i] = cinv[l];
            ans[aux[i].f] += bq(bitR, aux[i].s);
            bu(bitL, aux[i].s);
            ++l;
        }
    }
    memcpy(cinv+tl, aux+tl, tr-tl);
    //printf("    %2d, %-2d: ", tl, tr); for (int i=0; i<N; ++i) printf("%3d", ans[i]); printf("\n");
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=1; i<=N; ++i) scanf("%d", &arr[i]);
    for (int i=M; i>0; --i) {
        int d; scanf("%d", &d);
        ins[d] = i;
    }
    for (int i=1; i<=N; ++i) cinv[i] = { ins[arr[i]], arr[i] };

    //for (int i=1; i<=N; ++i) printf("%3d", cinv[i].f); printf("\n");
    //for (int i=1; i<=N; ++i) printf("%3d", cinv[i].s); printf("\n");

    solve(1, N+1);
    for (int i=0; i<M; ++i) ans[i+1] += ans[i];
    for (int i=M; i>0; --i) printf("%d\n", ans[i]);

	return 0;
}

