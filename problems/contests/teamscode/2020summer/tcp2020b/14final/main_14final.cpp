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

#include <chrono>
// Get time stamp in nanoseconds.
uint64_t nanos()
{
    uint64_t ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::
                  now().time_since_epoch()).count();
    return ns;
}
unsigned long long previous_time=0;
unsigned long long elapsed(bool print=true)
{
    unsigned long long elapsed = nanos() - previous_time;
    if (print) printf("%.3lf micros elapsed\n", (double)elapsed/1000);
    previous_time = nanos();
    return elapsed;
}

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
int N, M, ins[MX], ans[MX];
int bitL[MX], bitR[MX];
int invt[MX], invv[MX], auxt[MX], auxv[MX];
//pair<int, int> cinv[MX], aux[MX];    // <insert order, og value>

inline void bu(int b[], int x)     // bit update
{
    for (; x<=N; x+=x&-x)
        ++b[x];
}
inline int bq(int b[], int x)     // bit query
{
    int sum=0;
    for (; x; x-=x&-x)
        sum += b[x];
    return sum;
}
void solve(int tl, int tr)  // dnq inversions counter, inc l exc r
{
    if (tl+1 == tr) return;
    //printf("    solve %d:%d    ", tl, tr); for (int i=tl; i<tr; ++i) printf("(%3d, %3d)  ", cinv[i].f, cinv[i].s); printf("\n");
    int mid = tl+(tr-tl>>1);
    solve(tl, mid); solve(mid, tr);
    int l=tl, r=mid;

    //printf("memset start: "); elapsed();
    memset(bitL, 0, sizeof bitL);
    memset(bitR, 0, sizeof bitR);
    //printf("memset end: %lf\n", (double)elapsed(0)*1e3/(tr-tl));
    for (int i=tl; i<tr; ++i)
    {
        //printf("        %2d v %-2d ", l, r);
        if (l == mid || (r < tr && invt[r] < invt[l])) {    // take from right
            //printf("take from right\n");
            auxt[i] = invt[r];
            auxv[i] = invv[r];
            ans[auxt[i]] += bq(bitL, N+1-auxv[i]);
            bu(bitR, auxv[i]);
            ++r;
        } else {                                // take from left
            //printf("take from left\n");
            auxt[i] = invt[l];
            auxv[i] = invv[l];
            ans[auxt[i]] += bq(bitR, auxv[i]);
            bu(bitL, N+1-auxv[i]);
            ++l;
        }
    }
    //printf("merge end: %lf per num\n", (double)elapsed(0)*1e3/(tr-tl));
    //printf("merge end: %lf per num\n", (double)elapsed(0)*1e3);
    memcpy(invt+tl, auxt+tl, sizeof(int)*(tr-tl));
    memcpy(invv+tl, auxv+tl, sizeof(int)*(tr-tl));
    //for (int i=tl; i<tr; ++i) invt[i] = auxt[i], invv[i] = auxv[i];
    //printf("copy end: %lf per num\n", (double)elapsed(0)*1e3/(tr-tl));
    //printf("    %2d, %-2d: ", tl, tr); for (int i=0; i<N; ++i) printf("%3d", ans[i]); printf("\n");
}

int main()
{
    //printf("start: "); elapsed();
    scanf("%d%d", &N, &M);
    for (int i=1; i<=N; ++i) scanf("%d", &invv[i]);
    for (int i=M; i>0; --i) {
        int d; scanf("%d", &d);
        ins[d] = i;
    }
    //printf("input: "); elapsed();
    for (int i=1; i<=N; ++i) invt[i] = ins[invv[i]];
    //printf("processing: "); elapsed();

    //for (int i=1; i<=N; ++i) printf("%3d", invt[i]); printf("\n");
    //for (int i=1; i<=N; ++i) printf("%3d", invv[i]); printf("\n");

    solve(1, N+1);
    //printf("solved: "); elapsed();
    for (int i=0; i<M; ++i) ans[i+1] += ans[i];
    //printf("postprocess: "); elapsed();
    for (int i=M; i>0; --i) printf("%d\n", ans[i]);
    //printf("output: "); elapsed();

	return 0;
}

