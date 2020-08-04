#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <utility>
#include <map>
#include <list>
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
#define f first
#define s second

const int MXN = 20200;
const int MXV = 1000111;
int N, K;
int inp[MXN];
int sa[MXN], rk[MXN], tmp[MXN], pos[MXV];
int lcp[MXN];

//void gen_sa() {
//    for (int i = 1; i <= n; i++) {
//        rk[i] = a[i];
//        sa[i] = i;
//    }
//    int mx = 1000010;
//    for (int i = 1; (i >> 1) < n; i <<= 1) {
//        int k = i >> 1;
//        for (int j = 1; j <= k; j++) {
//            tmp[j] = n - j + 1;
//        }
//        int p = k;
//        for (int j = 1; j <= n; j++) {
//            if (sa[j] > k) tmp[++p] = sa[j] - k;
//        }
//        memset(pos, 0, sizeof(pos));
//        for (int j = 1; j <= n; j++) {
//            pos[rk[tmp[j]]]++;
//        }
//        for (int j = 1; j <= mx; j++) {
//            pos[j] += pos[j - 1];
//        }
//        for (int j = n; j >= 1; j--) {
//            sa[pos[rk[tmp[j]]]--] = tmp[j];
//        }
//        int cnt = 0;
//        for (int j = 1; j <= n; j++) {
//            if (rk[sa[j]] != rk[sa[j - 1]] || rk[sa[j] + k] != rk[sa[j - 1] + k]) ++cnt;
//            tmp[sa[j]] = cnt;
//        }
//        for (int j = 1; j <= n; j++) {
//            rk[j] = tmp[j];
//        }
//        mx = cnt;
//    }
//}

void ksa()
{
    int mx = MXV-10;
    for (int i=1; i<=N; ++i)
        rk[i] = inp[i], sa[i] = i;
    for (int i=1; i>>1<=N; i<<=1)
    {
        int k = i>>1, p = k;
        // second keyword
        for (int i=1; i<=k; ++i) tmp[i] = N-i+1;
        for (int i=1; i<=N; ++i) if (sa[i] > k) tmp[++p] = sa[i]-k;
        // first keyword
        //memset(pos, 0, 1+mx<<2);
        for (int i=1; i<=mx; ++i) pos[i] = 0;
        for (int i=1; i<=N; ++i) ++pos[rk[i]];
        for (int i=1; i<=mx; ++i) pos[i] += pos[i-1];       // FIX: typo--mx not MX
        for (int i=N; i; --i) sa[pos[ rk[tmp[i]] ]--] = tmp[i];
        // rerank
        for (int i=1; i<=N; ++i)
            tmp[sa[i]] = tmp[sa[i-1]] + (rk[sa[i]] != rk[sa[i-1]] || rk[sa[i]+k] != rk[sa[i-1]+k]);
        //memcpy(rk, tmp, 1+N<<2);
        for (int i=1; i<=N; ++i) rk[i] = tmp[i];
        // reset
        mx = rk[sa[N]];
        if (mx == N) break;
    }
    for (int i=1; i<=N; ++i)
    {
        lcp[rk[i]] = max(lcp[rk[i-1]]-1, 0);    // FIX: lcp[rk[i-1]] -1 not just lcp[rk[i-1]], since it could decrease by one
        if (rk[i] > 1)
            while (inp[  i  +lcp[rk[i]]] == inp[  sa[rk[i]-1]  +lcp[rk[i]]])    // FIX: sa[rk[i]-1] not lcp[rk[i]-1] for start pos of rank-prev suffix
                ++lcp[rk[i]];
    }
    //for (int i=2; i<=N; ++i) printf("%d\n", lcp[i]);  // FIX: remove debug output
}


//bool check(int x) {
//    int grp = 0;
//    for (int i = 1; i <= N; i++) {
//        int id = sa[i];
//        if (lcp[rk[id]] < x) grp = 1;
//        else grp++;
//        if (grp >= K) return true;
//    }
//    return false;
//}

bool check(int mn)
{
    //printf("checking mn = %d\n", mn);
    int maxsz = 0, start = 1;
    for (int i=2; i<=N; ++i)
    {
        if (lcp[i] < mn)
        {
            //printf("    group of size %d from %d->%d\n", i-start, start, i);
            maxsz = max(maxsz, i-start);
            start = i;
        }
    }
    maxsz = max(maxsz, N+1-start);  // FIX: fencepost--`N+1 - start`, since N-start already checked by for loop i<=N
    //printf("maxsize: %d\n", maxsz);
    return maxsz >= K;
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i=1; i<=N; ++i) scanf("%d", &inp[i]);
    //for (int i = 1; i <= N; i++) {
    //    scanf("%d", &inp[i]);
    //}
    //gen_sa();
    ksa();
    //for (int i = 1; i <= N; i++) {
    //    int prv = sa[rk[i] - 1];//index of suffix one before i in lexigraphical order
    //    int j = max(0, lcp[rk[i - 1]] - 1);
    //    while (max(i + j, prv + j) <= N && inp[i + j] == inp[prv + j]) {
    //        ++j;
    //    }
    //    lcp[rk[i]] = j;
    //    //printf("%d ", lcp[rk[i]]);
    //}
    //printf("\n");

    int l=0, r=N+1; // FIX: upper bound should be N+1 not N (exc r) and not MXN (too high)
    while (l+1 < r)
    {
        int mid = l + (r-l>>1);
        if (check(mid)) l = mid;
        else r = mid;
    }
    printf("%d\n", l);

    //int L = 0, R = N + 1;
    //while (R - L > 1) {
    //    int mid = (L + R) >> 1;
    //    if (check(mid)) L = mid;
    //    else R = mid;
    //}
    //printf("%d", L);
}

