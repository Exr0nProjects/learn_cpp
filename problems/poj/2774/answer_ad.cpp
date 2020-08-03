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

const int maxn = 20200;

char a[maxn];
int n, m, sa[maxn], rk[maxn << 1], lcp[maxn];
int tmp[maxn], pos[1000100];

void gen_sa() {
    for (int i = 1; i <= n; i++) {
        rk[i] = a[i];
        sa[i] = i;
    }
    int mx = 1000010;
    for (int i = 1; (i >> 1) < n; i <<= 1) {
        int k = i >> 1;
        for (int j = 1; j <= k; j++) {
            tmp[j] = n - j + 1;
        }
        int p = k;
        for (int j = 1; j <= n; j++) {
            if (sa[j] > k) tmp[++p] = sa[j] - k;
        }
        memset(pos, 0, sizeof(pos));
        for (int j = 1; j <= n; j++) {
            pos[rk[tmp[j]]]++;
        }
        for (int j = 1; j <= mx; j++) {
            pos[j] += pos[j - 1];
        }
        for (int j = n; j >= 1; j--) {
            sa[pos[rk[tmp[j]]]--] = tmp[j];
        }
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (rk[sa[j]] != rk[sa[j - 1]] || rk[sa[j] + k] != rk[sa[j - 1] + k]) ++cnt;
            tmp[sa[j]] = cnt;
        }
        for (int j = 1; j <= n; j++) {
            rk[j] = tmp[j];
        }
        mx = cnt;
    }
}

bool check(int x) {
    int grp = 0;
    for (int i = 1; i <= n; i++) {
        int id = sa[i];
        if (lcp[rk[id]] < x) grp = 1;
        else grp++;
        if (grp >= m) return true;
    }
    return false;
}

int main() {
    //scanf("%d", &n);
    scanf("%s", a+1);
    int N1 = strlen(a+1);
    //N = strlen(a+1);
    a[N1+1] = '#';
    scanf("%s", a+2+N1);          // FIX: rename-- +N1 not +N because N == 0 here!
    printf("'%s'\n", a+1);
    n = N1 + strlen(a+1+N1);

    //scanf("%s", a+1);
    //n = strlen(a+1);
    gen_sa();
    for (int i = 1; i <= n; i++) {
        int prv = sa[rk[i] - 1];//index of suffix one before i in lexigraphical order
        int j = max(0, lcp[rk[i - 1]] - 1);
        while (max(i + j, prv + j) <= n && a[i + j] == a[prv + j]) {
            ++j;
        }
        lcp[rk[i]] = j;
        //printf("%d ", lcp[rk[i]]);
    }
    for (int i=1; i<=n; ++i) printf("%3d ", lcp[i]); printf("\n");
}

