#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <utility>
#include <map>
#include <list>
#define f first
#define s second
using namespace std;
const int maxn = 700111;
int n;
char names[maxn][20];
int rot[maxn];//rotate amount
int f[maxn];//factors
int sum[maxn << 2];//segment tree

void set_n(int inn) {
    n = 1;
    while (n < inn)
        n <<= 1;
}

void update(int id) {
    sum[id] = sum[id << 1] + sum[id << 1 | 1];
}

void modify(int id, int p, int v, int L, int R) {
    if (p < L || p > R) return;
    if (L == R) {
        sum[id] = v;
        return;
    }
    int lc = id << 1, rc = id << 1 | 1, mid = (L + R) >> 1;
    modify(lc, p, v, L, mid);
    modify(rc, p, v, mid + 1, R);
    update(id);
}

int query(int id, int qL, int qR, int L, int R) {
    if (L > qR || R < qL) return 0;
    if (qL <= L && R <= qR) return sum[id];
    int lc = id << 1, rc = id << 1 | 1, mid = (L + R) >> 1;
    return query(lc, qL, qR, L, mid) + query(rc, qL, qR, mid + 1, R);
}

int find(int id, int p, int L, int R) {
    if (L == R) return L;
    int ls = sum[id << 1], mid = (L + R) >> 1;
    if (p <= ls) return find(id << 1, p, L, mid);
    else return find(id << 1 | 1, p - ls, mid + 1, R);
}

int main() {
    int inn, k;
    for (int i = 1; i < maxn; i++) {
        for (int j = i; j < maxn; j += i) {
            f[j]++;
        }
    }
    while (scanf("%d%d", &inn, &k) == 2) {
        memset(sum, 0, sizeof(sum));
        set_n(inn);
        for (int i = 1; i <= inn; i++) {
            scanf("%s%d", names[i], &rot[i]);
            modify(1, i, 1, 1, n);
        }
        int cnt = 0, mx = 0, ans, sz = inn;
        while (sz > 0) {
            if (f[++cnt] > mx) {
                mx = f[cnt];
                ans = k;
            }
            if (sz == 1) break;
            modify(1, k, 0, 1, n);
            sz--;
            int r = rot[k];
            if (r > 0) r -= 1;
            r %= sz;
            r += sz;
            r %= sz;
            r++;
            int q = query(1, k, inn, 1, n);
            if (r <= q) {
                k = find(1, r + query(1, 1, k, 1, n), 1, n);
            }
            else {
                k = find(1, r - q, 1, n);
            }
            if (!query(1, k, k, 1, n)) {
                /*int a;
                for (long long i = 0; i < 1000000000000; i++) {
                    a++;
                    a %= maxn;
                }*/
            }
        }
        printf("%s %d\n", names[ans], mx);
    }
}

