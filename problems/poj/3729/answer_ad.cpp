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

const int maxN = 101000;

int n, m, k, N;
int a[maxN];
int sa[maxN], rk[maxN << 1], lcp[maxN];
int tmp[maxN], pos[maxN];
bool fst[maxN];
int ans;

void set_sa() {
    for (int i = 1; i <= N; i++) {
        rk[i] = a[i];
        sa[i] = i;
    }
    int mx = 11000;
    for (int i = 1; (i >> 1) < N; i <<= 1) {
        int t = i >> 1;
        for (int j = 1; j <= t; j++) {
            tmp[j] = N - j + 1;
        }
        int p = t;
        for (int j = 1; j <= N; j++) {
            if (sa[j] > t) tmp[++p] = sa[j] -t;
        }
        memset(pos, 0, sizeof(pos));
        for (int j = 1; j <= N; j++) {
            pos[rk[tmp[j]]]++;
        }
        for (int j = 1; j <= mx; j++) {
            pos[j] += pos[j - 1];
        }
        for (int j = N; j >= 1; j--) {
            sa[pos[rk[tmp[j]]]--] = tmp[j];
        }
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (rk[sa[j]] != rk[sa[j - 1]] || rk[sa[j] + t] != rk[sa[j - 1] + t]) ++cnt;
            tmp[sa[j]] = cnt;
        }
        memcpy(rk + 1, tmp + 1, N << 2);
        mx = cnt;
    }
}

void solve_k() {
    int b = 1;
    bool vis = 0;
    lcp[N + 1] = 0;
    for (int i = 1; i <= N + 1; i++) {
        if (lcp[i] < k) {
            for (int j = b; j < i; j++) {
                if (sa[j] <= n) fst[j] = vis;
            }
            vis = 0;
            b = i;
        }
        if (sa[i] > n + 1) vis = 1;
    }
}

void solve_ans() {
    int b = 1;
    bool vis = 0;
    for (int i = 1; i <= N + 1; i++) {
        if (lcp[i] < k + 1) {
            for (int j = b; j < i; j++) {
                if (sa[j] <= n) {
                    if (fst[j] && !vis) ++ans;
                }
            }
            vis = 0;
            b = i;
        }
        if (sa[i] > n + 1) vis = 1;
    }
}

int main() {
    while (scanf("%d%d%d", &n, &m, &k) == 3) {
        memset(a, 0, sizeof(a));
        memset(sa, 0, sizeof(sa));
        memset(rk, 0, sizeof(rk));
        memset(lcp, 0, sizeof(lcp));
        memset(tmp, 0, sizeof(tmp));
        memset(fst, 0, sizeof(fst));
        N = n + m + 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            ++a[i];
        }
        a[n + 1] = 10100;
        for (int i = n + 2; i <= N; i++) {
            scanf("%d", &a[i]);
            ++a[i];
        }
        set_sa();
        /*for (int i = 1; i <= N; i++) {
            printf("%d ", sa[i]);
        }
        printf("\n");
        for (int i = 1; i <= N; i++) {
            printf("%d ", rk[i]);
        }
        printf("\n");*/
        for (int i = 1; i <= N; i++) {
            int j = max(0, lcp[rk[i - 1]] - 1), prv = sa[rk[i] - 1];
            while (a[i + j] == a[prv + j]) ++j;
            lcp[rk[i]] = j;
        }
        //        int tot=0;
        //for (int i=1; i<N; ++i)
        //{
        //    //printf("i %d: ", i);
        //    int j=i+1;
        //    while (lcp[j] > k) ++j;
        //    //printf("j %d..", j);
        //    if (lcp[j] < k) continue;   // FIX: continue not break
        //    for (; lcp[j] > k-1; ++j)
        //    {
        //        if (min(sa[i], sa[j]) <= n && max(sa[i], sa[j]) > n)
        //        {
        //            //printf("%d..", j);
        //            ++tot;
        //        }
        //    }
        //    //printf("%d\n", j);
        //}
        //printf("%d\n", tot);
        //return 0;

        /*for (int i = 1; i <= N; i++) {
            printf("%d ", lcp[i]);
        }
        printf("\n");*/
        solve_k();
        /*for (int i = 1; i <= N; i++) {
            printf("%d ", num[i]);
        }
        printf("\n");*/
        ans = 0;
        solve_ans();
        printf("%d\n", ans);
    }
}

